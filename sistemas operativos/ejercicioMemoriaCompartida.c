//ejercicio
//proibido usar sleep
//papa crea el proceso hijo
//hijo se llama datos
//hijo va a leer el valor de dos variables compartidas(1 e 2) por teclando
//cuando el hijo haya acabado, papi va a sumar los dos números, lo saca por pantalla y adios programa
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/mman.h>

static int *num1, *num2, *flag;

int main(void) {
  /* code */
  pid_t hijo;
  num1=mmap(NULL, sizeof *num1, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
  num2=mmap(NULL, sizeof *num2, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
  flag=mmap(NULL, sizeof *flag, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
  *flag=-1;

  if((hijo=fork())<0){
    perror("Fallo al crear el proceso\n");
  }
  if(hijo>0){ //padre
    while (*flag==-1);
    printf("Soy el padre después de 84 años el cabron del hijo me ha pasado los valores, y la suma de %d y %d es %d\n", *num1, *num2, *num1+*num2);

  }
  else if(hijo==0){

    puts("Escribe el primer número:");
    scanf("%d", &*num1);
    puts("Escribe el segundo número:");
    scanf("%d", &*num2);
    *flag=1;
    exit(0);
  }
  return 0;
}
