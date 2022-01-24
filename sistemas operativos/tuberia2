#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
  /* code */
  int tuberia[2];
  pid_t hijo;
  FILE *stream;
  char mensaje;

  pipe(tuberia);

  if ((hijo=fork())<0) {
    /* code */
    perror("Ha ocurrido un error\n");
    exit(-1);
  }
  if(hijo>0){ //Proceso padre
    close(tuberia[0]);
    stream=fdopen(tuberia[1], "w");
    mensaje='F';
    fprintf(stream, "%c", mensaje);
    fclose(stream); //cierra el fichero
    wait(NULL);
  }
  else if(hijo==0){ //proceso hijo
    close(tuberia[1]); //cerramos el lado que no usamos
    stream= fdopen(tuberia[0], "r");
    fscanf(stream, "%c", &mensaje);
    printf("Soy el proceso hijo y papa me ha pasado el mensaje %c\n", mensaje);
    fclose(stream);
    exit(0);
  }
  return 0;
}
