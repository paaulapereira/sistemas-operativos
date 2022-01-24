#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <pthread.h>
#define LIMITE 11 //define el número maximo de hilos que se estan creando

void *palabra(){
  //aqui pide una palabra cualquier que será utilizada para matar a los hilos
  int palabra;
  scanf("%d", &palabra);
  return 0;
};
void *calcula(){
  //mantiene los hilos ejecutando un bucle largo mientras se crean los nuevos
  long long unsigned t;
  for(t=0;t<(0xFFFF);t++);
};

int main (void){

	pthread_t hilo[LIMITE]; //creo un hilo que tiene como su parámetro el limite y puesto que es la cantidad de los hilos que quiero crear

 //creo un primer hilo que llama al parámetro palabra para que leer lo que el usuario ha puesto
	pthread_create(&hilo[LIMITE-1],NULL, &palabra, NULL);

  //se crea un bucle con tamaño menor que el limite
	for(int i=1;i<(LIMITE-1);i++){
    //aqui se crean hilos que llaman a calcula para que hagan algo
		pthread_create(&hilo[i],NULL, &calcula, NULL);
		printf("Me crearon. Soy el hilo con ID %lu\n", hilo[i]); //imprime el id del hilo
	}

  //se crea el bucle para matar a los hilos en orden de creacion
	for(int j=LIMITE-1;j>0;j--){
    //aqui se une el hilo que tenía sido previamente creado
    pthread_join(hilo[LIMITE-1],NULL);
		printf("El hilo con ID %lu ha muerto\n", hilo[j-1]);

	}

}
