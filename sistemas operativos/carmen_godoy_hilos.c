#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <pthread.h>
#define NUMHILOS 10//definimos el numero de hilos que queremos

void *nada();
void *input();
int num;
int main (void){
	//Variables para iterar
	int i,j;
	//Creamos la referencia de los hilos y le pasamos como parametro la constante NUMHILOS, que sera la cantidad de hilos que crearemos
	pthread_t hilos[NUMHILOS];

	//Creamos un hilo que llama a input para registrar entrada del usuario
	pthread_create(&hilos[NUMHILOS-1],NULL, &input, NULL);

	//Creamos hilos que llaman a nada y mostramos en consola que se creo cada hilo
	for(i=1;i<(NUMHILOS-1);i++){
		//Creamos un hilo a nada
		pthread_create(&hilos[i],NULL, &nada, NULL);
		printf("Acabo de crear el hilo %d: %lu\n", i, hilos[i]);
	}
	//Mostramos en consola la cantidad de hilos que creamos previamente
	printf("Acabo de crear %d hilos\n",NUMHILOS-1);

	//Unimos los hilos creados nuevamente
	for(j=NUMHILOS-1;j>0;j--){
		//Unimos el hilo previamente creado
		printf("Voy a eliminar el hilo %d: %lu\n",j, hilos[j]);
		pthread_join(hilos[NUMHILOS-1],NULL);
		printf("Acabo de eliminar el hilo %d\n", j);
	}

}
void *nada(){
	//terminamos el metodo
	return 0;
}
void *input(){
	//Pedimos al usario que ingrese algo
	puts("Escribe lo que sea");
	scanf("%d", &num);
	//Terminamos el metodo
	return 0;
}
