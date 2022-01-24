#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void){
  pid_t suma,resta;
  int num1, num2;

  puts("escribe un primer numero: ");
  scanf("%d", &num1 );
  puts("escribe un segundo numero: ");
  scanf("%d", &num2);

  suma=fork();
  if (suma>0) {
    resta = fork();
  }
  if(resta>0 && suma>0){
    puts("Soy el padre, estoy a la espera\n");
    wait(NULL);
    puts("Soy el padre, ciao\n");
  }
  else if (suma==0 && resta!0){ //proceso suma
    sleep(1);
    printf("La suma vale %d\n", num1+num2);
    exit(0);
  }
  else if(suma!=0 && resta==0){ //proceso resta
    sleep(1);
    printf("La resta vale %d\n", num1-num2);
  }
  return 0;
}
