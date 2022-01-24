#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>

#define LIMITE 1000000

void *incrementa();
void *decrementa();

static int global_var=0;
sem_t *mutex;

int main()
{
	//Asignamos espacio para los threads que vamos a almacenar
	pthread_t suma, resta;
	//Creamos es semaforo que usaremos para limitar acceso a la variable global
	mutex=sem_open("/semaforo", O_CREAT, S_IRUSR | S_IWUSR, 1);
	//Creamos los threads suma y resta
	pthread_create(&suma, NULL, &incrementa, NULL);
	pthread_create(&resta, NULL, &decrementa, NULL);
	//Unimos los threads Suma y Resta
	pthread_join(resta, NULL);
	pthread_join(suma, NULL);
	//Imprimimos el valor final de la variable. Deberia de ser 0
	printf("El valor final de la variable es %d\n", global_var);
	//Terminamos el semaforo
	sem_close(mutex);
	sem_unlink("/semaforo");
	//Terminamos el proceso
	return 0;
}
void *incrementa()
{
	int i;
	puts("Comienza hilo suma\n");
	//Sumamos a la variable global +1 la cantida de veces indicadas por LIMITE
	for (i=0;i<LIMITE;i++)
	{
		//Esperamos en el semaforo y lo bloqueamos
		sem_wait(mutex);
		global_var=global_var+1;
		//Desbloqueamos el Semaforo
		sem_post(mutex);
	}
	//Imprimimos el valor de la variable global
	printf("Suma: el valor final de la variable es %d\n", global_var);
	//Terminamos el proceso
	return 0;
}
void *decrementa()
{
	int i;
	puts("Comienza hilo resta\n");
	//Restamos a la variable global -1 la cantida de veces indicadas por LIMITE
	for (i=0;i<LIMITE;i++)
	{
		//Esperamos en el semaforo y lo bloqueamos
		sem_wait(mutex);
		global_var=global_var-1;
		//Desbloquemos el Semaforo
		sem_post(mutex);
	}
	//Imprimimos el valor de la variable global
	printf("resta:valor final de la variable es %d\n", global_var);
	//Terminamos el proceso
	return 0;
}
