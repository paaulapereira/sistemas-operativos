#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/mman.h>
#define LIMITE 1000 //define el limite de las operaciones a 1000

static int *var_compartida, *flag;

int main(void){
	var_compartida = mmap(NULL,sizeof(*var_compartida), PROT_READ| PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS,-1,0);
	flag= mmap(NULL, sizeof(*var_compartida), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	*var_compartida = 0;

	pid_t hijo, hijo2;
	hijo= fork();

	if (hijo<0) {
		/* code */
		perror("Ha ocurrido un error\n");
    exit(-1);
	}
	if(hijo>0){ //proceso padre que crea el segundo hijo
      hijo2=fork();
	}

	if(hijo==0)
	{ //ese hijo hace la suma de lo que hay en la cuenta
		for(int i = 1; i<=LIMITE; ++i)
		{
			while (*flag==0);
			*var_compartida = *var_compartida +1; //aqui suman los numeros
			*flag=0;
		}
		exit(1);
	}

	else if(hijo2==0)
	{ //ese hijo hace la resta de lo que hay en la cuenta
		for(int i = 1; i<=LIMITE; ++i)  //mientras no sea mayor que el limite
		{
				while(*flag==1);
				*var_compartida = *var_compartida -1;
				*flag=1;
		}
		exit(0);
	}

	else if(hijo!=0 && hijo2!=0)
	{
		while(wait(NULL)>0); //imprime el resultado final de la cuenta bancaria
		printf("El resultado final de la es: %d\n",*var_compartida);
	}

	return 0;
}
