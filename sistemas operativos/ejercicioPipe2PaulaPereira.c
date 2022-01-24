#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
//el proceso hijo hace la suma y pasa la respuesta a padre que lo imprime
int main(void) {
  /* code */
  int tuberia1[2],tuberia2[2];
  pid_t hijo;
  int num1, num2, operacionsuma;
  pipe(tuberia1);
  pipe(tuberia2);
  if ((hijo=fork())<0) {
    /* code */
    perror("Ha ocurrido un error\n");
    exit(-1);
  }
  if(hijo>0){ //Proceso padre
    //pasando los datos al hijo
    close(tuberia1[0]);
    puts("escribe un primer numero:\n ");
    scanf("%d", &num1 );
    write(tuberia1[1], &num1, sizeof(num1));
    puts("escribe un segundo numero:\n");
    scanf("%d", &num2);
    write(tuberia1[1], &num2, sizeof(num2));
    wait(NULL);
    //leer y imprimir la suma
    close(tuberia2[1]); //cerramos el lado que no utilizamos
    read(tuberia2[0],&operacionsuma, sizeof(operacionsuma));
    printf("Soy el proceso padre y mi hijo me ha pasado el mensaje %d\n", operacionsuma);

  }
  else if(hijo==0){ //proceso hijo
    close(tuberia1[1]); //cerramos el lado que no usamos y hacemos la suma
    read(tuberia1[0], &num1, sizeof(num1));
    read(tuberia1[0], &num2, sizeof(num2));
    operacionsuma = num1+num2;
    //enviando la suma por otra tuberia al papa
    close(tuberia2[0]);
    write(tuberia2[1], &operacionsuma, sizeof(operacionsuma));
    exit(0);
  }
  return 0;
}
