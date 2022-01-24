#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> //libreria que implementa el standard POSIX
#include <semaphore.h> //libreria de los semaforos 

#define DERECHA(x)		(((x)+1)%PERSONAS) //aqui se calcula quien es el filosofo que esta a la derecha
#define IZQUIERDA(x)	((x) !=0 ? (x)-1 : (PERSONAS-1)) //aqui se calcula quien es el filosofo que esta a la izquierda
#define PERSONAS 5 //cantidad de filosofos que estan en la cena
#define VIDA 10

typedef enum{ //declaramos las opciones de accion que hay para los filosofos
	PENSANDO,
  CON_HAMBRE,
  COMIENDO
}status;

status estado[PERSONAS]; //relacionamos las opciones que hay de accion con los filosofos que estan en la cena directamente
sem_t exclusivo,controlar[PERSONAS]; //crea dos semaforos, el exclusivo -el que controla que solo un filosofo puede coger o soltar los palillos, y el controlar[PERSONAS]- en el cual controlamos si yo pude coger los palillos o no, y si sea el caso que no me quedo bloqeuado hasta que me despierte un filosofo vecino
void pensar(int id);
void comer(int id);
void pillar_palillos(int id);
void comprobar(int id);
void libertar_palillos(int id);

int main(void)
{
	extern status estado[PERSONAS];
	extern sem_t exclusivo,controlar[PERSONAS];

	int v[PERSONAS],value,i; //el v[PERSONAS] informa a cada hijo quien es
	sem_init(&exclusivo,0,1);
	pthread_t filosofo[PERSONAS]; //proceso que almacena el identificador de cada uno de los hilos creado, que en ese caso serian de cada uno de los filosofos
	void *Filosofo(void* );

	for(i=0;i<PERSONAS;i++){ //inicializa todos los semaforos
		sem_init(&controlar[i],0,0);
		estado[i]=PENSANDO;

	}

	for(i=0;i<PERSONAS;i++){ //crea los procesos para cada filosofo que esta en la cena
		v[i]=i;
		if(value==pthread_create(&filosofo[i],NULL,Filosofo, (void *) &v[i]))
			exit(value);

	}

	for(i=0;i<PERSONAS;i++){ //proceso padre aguardando que todos los hijos terminen

		pthread_join(filosofo[i],NULL);
	}

	return 0;
}

void *Filosofo(void* i){
	int id,j;
	id=*(int *) i;

	for(j=0;j<2;j++)
	{
		pensar(id);
		pillar_palillos(id);
		comer(id);
		libertar_palillos(id);
	}
}

void pensar(int id)
{
	printf("El filósofo %d esta pensando\n",id);
	sleep (random() % 10);
}

void comer(int id)
{
	printf("El filósofo %d está comiendo\n",id);
	sleep (random() % 10);
}

void pillar_palillos(int id)
{
	sem_wait(&exclusivo); //aqui veo si alguien esta cogiendo palillos o no, si no hay nadie es posible que coja sino no
	estado[id]=CON_HAMBRE;
	comprobar(id);
	sem_post(&exclusivo); // haz con que sea posible que otro filosofo coja palillos
	sem_wait(&controlar[id]); //espera hasta que la funcion comprobar esté lista, sino se queda atrapado aqui
}
void libertar_palillos(int id)
{
	sem_wait(&exclusivo); //controla los palillos, mientras que haya alguien cogiendo palillos los otros tienen que esperar
	estado[id]=PENSANDO;
	comprobar(IZQUIERDA(id));
	comprobar(DERECHA(id));
	sem_post(&exclusivo);
}
void comprobar(int id)
{
	if(estado[id]==CON_HAMBRE&&estado[IZQUIERDA(id)]!=COMIENDO&&estado[DERECHA(id)]!=COMIENDO)
	{
		estado[id]=COMIENDO;
		sem_post(&controlar[id]); //libera el filosofo que ya conseguio coger los palillos
	}
}
