#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/mman.h>
#define LIMITE 1000

static int *numero;

int main(void)
{
  pid_t primerhijo;
  pid_t segundohijo;
  numero = 0;
  *numero = &numero;

  primerhijo = fork();

  if(primerhijo > 0){
    segundohijo=fork();
  }

  if(primerhijo == 0){
    for(int i = 0; i<=LIMITE;i++)
    {
      *numero =*numero+1;
    }
    exit(0) ;
  }
  else if(segundohijo==0 && primerhijo!=0){
    for(int i = 0; i<=LIMITE;i++)
    {
      *numero =*numero-1;
    }
    exit(0) ;
  }
  else if(primerhijo > 0 && segundohijo>0){

    while(wait(NULL)>0);
    printf("Soy el proceso padre. El resultado de la numa es: %d\n" , *numero);
  }

  return 0;
}
