#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
  pid_t proceso_nuevo;
  int num1, num2;
  printf("Ahora estoy seguro que soy el proceso padre\n");
  proceso_nuevo=fork();
  if (proceso_nuevo>0) { //este el proceso padre
    printf("Soy el padre con PID %d y estoy a la espera de nu hijo con PID %d\n", getpid(), proceso_nuevo);
    wait(NULL);
    puts("mi hijo ha terminado me largo yo tambien\n");
  }
  else if (proceso_nuevo==0) { //proceso hijo

    sleep(1);
    printf("Soy el%s\n", );

    puts("escribe un primer numero:\n");
    scanf("%d", &num1 );
    puts("escribe un segundo numero:\n");
    scanf("%d", &num2 );
    printf("La suma de %d y %d es %d\n", num1, num2, num1+num2);
  }
  else if (proceso_nuevo==1) { //proceso hijo

    perror("Se ha producido un error creando el proceso\n");
  }
  return 0;
}
