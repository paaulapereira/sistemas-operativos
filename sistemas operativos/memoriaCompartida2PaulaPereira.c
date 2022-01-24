#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/mman.h>

static int *num1, *flag,*flag1, *factorial, *run;

int main(void) {
  /* code */
  pid_t hijo;
  num1=mmap(NULL, sizeof *num1, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
  flag=mmap(NULL, sizeof *flag, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
  flag1=mmap(NULL, sizeof *flag, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
  factorial=mmap(NULL, sizeof *flag, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
  run=mmap(NULL, sizeof *flag, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);

  *flag=1;
  *flag1=1;
  *run=1;

  if((hijo=fork())<0){
    perror("Fallo al crear el proceso\n");
  }
  if(hijo>0){ //padre
    while(*num1>=0){
      puts("Escribe el número que quiera saber el factorial:");
      scanf("%d", &*num1);
      *flag1=0;
      while (*flag);
      if(*num1>=0){
        printf("El factorial del número %d es %d\n", *num1, *factorial);
      }
      *flag1=1;
    }
    *run=0;
    printf("Termine el proceso\n");
  }
  else if(hijo==0){
    while (*run) {
      /* code */
      *flag=1;
      while (*flag) {
        /* code */
      }
      if (*num1>0) {
        /* code */
        int i, nuevoFactorial=*num1;
        for (i = (*num1-1); i >1; i--) {
          /* code */
          nuevoFactorial *=i;
        }
        *factorial= nuevoFactorial;
      }
      else if(*num1==0){
        *factorial=1;
      }
      *flag=0;
    }

  }
  return 0;
}
