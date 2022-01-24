#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
  /* code */
  int tuberia[2];
  pid_t hijo;
  int num1, num2;

  pipe(tuberia);

  if ((hijo=fork())<0) {
    /* code */
    perror("Ha ocurrido un error\n");
    exit(-1);
  }
  if(hijo>0){ //Proceso padre
    close(tuberia[0]);
    puts("escribe un primer numero: ");
    scanf("%d", &num1 );
    write(tuberia[1], &num1, sizeof(num1));
    puts("escribe un segundo numero: ");
    scanf("%d", &num2);
    write(tuberia[1], &num2, sizeof(num2));
    wait(NULL);
  }
  else if(hijo==0){ //proceso hijo
    close(tuberia[1]); //cerramos el lado que no usamos
    read(tuberia[0], &num1, sizeof(num1));
    read(tuberia[0], &num2, sizeof(num2));
    printf("Soy el proceso hijo y papa me ha pasado el mensaje %d\n", num1+num2);
    exit(0);
  }
  return 0;
}
