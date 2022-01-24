#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/sem.h>

static void deunoenuno(char *);
int main(void) {
  /* code */
  pid_t hijo;
  if ((hijo=fork())<0) {
    /* code */
    perror("Error creando el proceso hijo\n");
  }
  if (hijo==0) {
    /* code */
    deunoenuno("Esta es la cadena del hijo me cago en la madre que la pario el hijo de la grn bretania\n");
    exit(0);
  }
  else if(hijo>0){
    deunoenuno("Esta es la cadena del padre me cago en la madre que la pario el hijo de la grn bretania\n");
  }
  return 0;
}
static void deunoenuno(char *str){
  char *ptr;
  int c;
  setbuf(stdout, NULL);
  for (ptr=str;(c=*ptr++)!=0;) {
    /* code */
    putc(c, stdout);
  }
}
