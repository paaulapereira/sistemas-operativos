#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){

  pid_t proceso_suicida;
  int opcion;
  printf("Ingrese un número entre esas opciones(-1, 0, 1): \n");
  scanf("%d", &opcion);

  while (opcion!= -1) {
    /* code */
    proceso_suicida = fork();
    if(proceso_suicida>0){ //padre
      wait(NULL);
    }
    else if(proceso_suicida==0){ //hijo
      if(opcion==0){
        execl("/bin/ls", "ls", "-l", NULL);
      }
      else if(opcion ==1){
        execl("/bin/ps", "ps","-e", NULL);
      }
    }
    printf("Escribe comando: \n");
    scanf("%d", &opcion);
  }
  return 0;
}
