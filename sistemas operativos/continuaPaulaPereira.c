#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <stdbool.h>
#define LIMITE 1000

static int *var_compartida;

int main(void){
	var_compartida = mmap(NULL,sizeof(*variable_compartida), PROT_READ| PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS,-1,0);
	*var_compartida = 0;

	pid_t suma, resta;
	suma= fork();
	//la suma crea la resta
	if(suma>0){
      resta=fork();
	}

	if(suma==0)
	{
		for(int i = 1; i<=LIMITE; ++i)
		{
				*var_compartida = *var_compartida +1; //aqui suman los numeros
		}
		exit(0);
	}

	else if(resta==0)
	{
		for(int i = 1; i<=LIMITE; ++i)
		{
				*var_compartida = *var_compartida -1;
		}
		exit(0);
	}

	else if(suma>0&&resta>0)
	{
		while(wait(NULL)>0); //imprime el resultado mientras no sea el número
		printf("El resultado es: %d\n",*var_compartida);
	}

	return 0;
}
