#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>

#define LIMITE 10000

static int variable_g=0;
sem_t *mutex;

void *adicion(){ //metodo para hacer la suma
	puts("El hilo suma empieza\n");
	//bucle para sumar de uno en uno (con la cantidad de veces igual al limite) a la variable global
	for (int i=0;i<LIMITE;i++)
	{
		//aguardo el semaforo y ahi lo bloqueo
		sem_wait(mutex);
		variable_g=variable_g+1;
		//el semaforo se desbloquea
		sem_post(mutex);
	}
	//se imprime el valor de la suma
	printf("En la suma la variable tiene un valor de %d\n", variable_g);
	return 0;
};
void *sustraccion(){ //metodo para hacer la resta
	puts("El hilo resta empieza\n");
	//bucle para restar de uno en uno (con la cantidad de veces igual al limite) a la variable global
	for (int i=0;i<LIMITE;i++)
	{
		//aguardo el semaforo y ahi lo bloqueo
		sem_wait(mutex);
		variable_g=variable_g-1;
		//el semaforo se desbloquea
		sem_post(mutex);
	}
	//se imprime el valor de la resta
	printf("En la resta la variable tiene un valor de %d\n", variable_g);
	return 0;
};

int main(void)
{
	pthread_t suma, resta; //creo un espacio para los hilos de suma y resta
	//creo el mutex para limitar el acesso a la variable
	mutex=sem_open("/semaphore", O_CREAT, S_IRUSR | S_IWUSR, 1);

  //creo los hilos para sumar y restar, y cada uno llama a los parametros de adicion y sustraccion, respectivamente
	pthread_create(&suma, NULL, &adicion, NULL);
	pthread_create(&resta, NULL, &sustraccion, NULL);

	pthread_join(resta, NULL); //se une el hilo resta
	pthread_join(suma, NULL); //se une el hilo suma

	//aqui imprimo el valor final de la variable, que si todo esta bien debería ser 0
	printf("Después de sumar y restar, el valor final de la variable es %d\n", variable_g);

	//aqui termino el mutex y se acaba el programa
	sem_close(mutex);
	sem_unlink("/semaphore");

	return 0;
}
