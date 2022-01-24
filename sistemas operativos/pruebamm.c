#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/mman.h>

static int *variable_compartida;

int main(void) {
  /* code */
  pid_t hijo;
  variable_compartida=mmap(NULL, sizeof *variable_compartida, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
  *variable_compartida=0;
  if((hijo=fork())<0){
    perror("Fallo al crear el proceso\n");
  }
  if(hijo>0){
    printf("Soy el padre y la variable vale %d\n", *variable_compartida);
    sleep(3);
    printf("Soy el padre y el cabron del hijo me ha cambiado la variable a %d\n", *variable_compartida);
    wait(NULL);
  }
  else if(hijo==0){
    sleep(1);
    puts("tocando los huevos a papi\n");
    *variable_compartida=69;
    exit(0);
  }
  return 0;
}
