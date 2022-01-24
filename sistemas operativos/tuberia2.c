#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
  /* code */
  int tuberia[2];
  pid_t hijo;
  char mensaje;

  pipe(tuberia);

  if ((hijo=fork())<0) {
    /* code */
    perror("Ha ocurrido un error\n");
    exit(-1);
  }
  if(hijo>0){ //Proceso padre
    close(tuberia[0]);
    mensaje='F';
    write(tuberia[1], &mensaje, sizeof(mensaje));
    wait(NULL);
  }
  else if(hijo==0){ //proceso hijo
    close(tuberia[1]); //cerramos el lado que no usamos
    read(tuberia[0], &mensaje, sizeof(mensaje));
    printf("Soy el proceso hijo y papa me ha pasado el mensaje %c\n", mensaje);
    exit(0);
  }
  return 0;
}
