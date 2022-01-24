// Ejecutar comandos con execl
// Nunca ejecutar system para lanzar procesos

// Librerias a utlizar
#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/types.h>

// cantidad maxima de argumentos
#define argumentos_max 15
// numero de caracteres maximos
#define comandos_max 100

/*
 * comando --> Array de lectura donde se almacenan los comandos
 * *args --> Array con ls argumentos encontrados
 * ruta --> Ruta actual del sistema, texto con el directorio local
 */
char comando[comandos_max], *args[argumentos_max], ruta[comandos_max];

/*
 * Definición de funciones a usar
 * comando_sistema_fn --> función para ejecutar funciones externas del sistema
 * obtener_args_fun --> separa los argumentos individualmente
 * echo_fn --> imprime por pantalla un cadena de texto
 * dir_fn --> muestras los archivos del directorio local o de una ruta especificada desde el directorio raiz
 * sumar_fn, restar_fn, multiplicar_fn, dividir_fn --> funciones aritmeticas que reciben los parametros por argumento
 * ayuda_fn --> funcion que imprime el listado de comandos
 */
void comando_sistema_fn(), obtener_args_fn(), echo_fn(), dir_fn();
void sumar_fn(), restar_fn(), multiplicar_fn(), dividir_fn(), ayuda_fn();

// Funcion principal
int main(void){
	// Bandera para terminar la ejecución del programa
	int finalizar = 0;
	// Colocamos la ruta actual en memoria
	getcwd(ruta,comandos_max);
	printf("Bienvenido a la Shell, fui creada por Kevin Acuña, diviertete.\n");
	printf("--------------------------------------------------------------------\n");
	while(!finalizar){
		// Imprimimos cada vez la ruta y el identificador de la Shell
		printf("KRAM@v5.0:~%s >",ruta);
		// limpiamos las variables para asegurar el correcto funcionamiento
		//__fpurge(stdin);
		memset(comando,'\0',comandos_max);
		// Pedimos el comando
		scanf("%[^\n]s",comando);
		// Solo ejecutamos si se ha escrito algo
		if(strlen(comando)>0){
			// Separamos el comando de sus argumentos
			obtener_args_fn();
			// Buscamos el comando ingresado por el usuario y ejecutamos
			if(strcmp(comando,"salir")==0){
				// Salir del programa
				printf("Cerrando programa...\n");
				finalizar=1;
			}else if(strcmp(comando,"pwd")==0){
				// Comando pwd con validacion de para no recibir argumentos e impresión del directorio actual
				if(args[1]) perror("El comando pwd no requiere de parametros ... Pero tranquilo, te entiendo :)\n");
				printf("%s\n",ruta);
			}else if(strcmp(comando,"cd")==0){
				/*
				 * Comando cd con validacion de argumentos
				 * si la nueva ruta intenta el cambio de directorio y se coloca en memoria la nueva ruta
				 * si no consigue el cambio de directorio se lanza un error
				 */
				if(args[1] == NULL) perror("Para ejecutar el comando cd es necesario argumentos, prueba con cd ..\n");
				else if(chdir(args[1])==0) getcwd(ruta,comandos_max);
				else perror("Error cambiando al directorio\n");
			}else if(strcmp(comando,"limpiar")==0){
				// comando limpiar envia al sistema el comando clean, es solo un alias
				  strcpy(comando,"clear"), comando_sistema_fn();
			}else if(strcmp(comando,"dir")==0){
				// comando dir
				  dir_fn();
			}else if(strcmp(comando,"sumar")==0){
				// funció sumar
				 sumar_fn();
			}else if(strcmp(comando,"restar")==0){
				// función restar
				  restar_fn();
			}else if(strcmp(comando,"multiplicar")==0){
				// función multiplicar
				  multiplicar_fn();
			}else if(strcmp(comando,"dividir")==0){
				// función dividir
				  dividir_fn();
			}else if(strcmp(comando,"fecha")==0){
				// comando fecha envia al sistema el comando date, es solo un alias
				  strcpy(comando,"date"), comando_sistema_fn();
			}else if(strcmp(comando,"ayuda")==0){
				// función que imprime por los comandos posibles
				ayuda_fn();
			}else if(strcmp(comando,"echo")==0){
				// función que imprime por pantalla
				if(args[1]) echo_fn();
			}else{
				// para cualquier otro comando se intenta con un llamado al sistema
				comando_sistema_fn();
			}
		}
	}
}
// Suma con los argumentos del comando
void sumar_fn(){
	// Si tiene ambos argumentos
	if(args[1] && args[2]){
		// Se pasa de string to int, se suma y se imprime por pantalla
		int valor1, valor2, total;
		valor1 = atoi(args[1]);
		valor2 = atoi(args[2]);
		total = valor1 + valor2;
		printf("%i + %i = %i\n",valor1, valor2, total);
	}else{
		// Si no se tienen los argumentos se lanza un error
		perror("Para usar la función sumar necesitas 2 numeros como parámetros\n");
	}
}

// Imprimir los comandos posibles
void ayuda_fn(){
	printf("1  - pwd\n");
	printf("2  - cd [dirección desde directorio local] \n");
	printf("3  - limpiar \n");
	printf("4  - dir [*dirección desde directorio local] \n");
	printf("5  - sumar [valor1] [valor2] \n");
	printf("6  - restar [valor1] [valor2] \n");
	printf("7  - multiplicar [valor1] [valor2] \n");
	printf("8  - dividir [divisor] [dividendo]  \n");
	printf("9  - fecha\n");
	printf("10 - echo [cadena de texto a mostrar por pantalla] \n");
	printf("11 - ayuda\n");
	printf("12 - *Comandos de sistema con sus argumentos como ls [*-a] [*-l] [*-i] *\n");
	printf("13 - salir\n");
}

// Resta con los argumentos del comando
void restar_fn(){
	// Si tiene ambos argumentos
	if(args[1] && args[2]){
		// Se pasa de string to int, se resta y se imprime por pantalla
		int valor1, valor2, total;
		valor1 = atoi(args[1]);
		valor2 = atoi(args[2]);
		total = valor1 - valor2;
		printf("%i - %i = %i\n",valor1, valor2, total);
	}else{
		// Si no se tienen los argumentos se lanza un error
		perror("Para usar la función sumar necesitas 2 numeros como parámetros\n");
	}
}

// Multiplica con los argumentos del comando
void multiplicar_fn(){
	// Si tiene ambos argumentos
	if(args[1] && args[2]){
		// Se pasa de string to int, se multiplica y se imprime por pantalla
		int valor1, valor2, total;
		valor1 = atoi(args[1]);
		valor2 = atoi(args[2]);
		total = valor1 * valor2;
		printf("%i * %i = %i\n",valor1, valor2, total);
	}else{
		// Si no se tienen los argumentos se lanza un error
		perror("Para usar la función sumar necesitas 2 numeros como parámetros\n");
	}
}

// Divide con los argumentos del comando
void dividir_fn(){
	// Si tiene ambos argumentos
	if(args[1] && args[2]){
		/*
		 * Se pasa de string a float para obtener decimales al dividir,
		 * se divide y se imprime por pantalla, para ser mejor visualmente, se imprime
		 * el string eliminando así los decimales
		 */
		float valor1, valor2, total;
		valor1 = atoi(args[1]);
		valor2 = atoi(args[2]);
		if(valor2 == 0) {
			printf("No es posible la división entre cero\n");
		}else{
			total = valor1 / valor2;
			printf("%s / %s = %f\n",args[1], args[2], total);
		}
	}else{
		// Si no se tienen los argumentos se lanza un error
		perror("Para usar la función sumar necesitas 2 numeros como parámetros\n");
	}
}
// Separa el comando y los argumentos
void obtener_args_fn(){
	int i;
	// Se limpia el array de argumentos colocandolos a NULL
	for(i=0;i<(argumentos_max-1);i++) args[i]=NULL;
	// Separamos el comando con sus stocks
	strtok(comando," ");
	// reiniciamos el contador
	i=0;
	// asignamos al primer campo el comando, necesitado para el exec
	args[i]=comando;
	/*
	 * agumentos_max -2 porque necesitamos que al final del array exista siempre un NULL siendo -1
	 * porque el indice inicia en 0 y -2 al dejar siempre al final un valor NULL
	 * args[++i]=strtok(NULL," ") --> Agrega el siguiente argumento obteniendolos por sus tokens al array de argumentos
	 */
	while((args[++i]=strtok(NULL," ")) != NULL && i<(argumentos_max-2)); //printf("valor de args[%i] es %s\n", i, args[i]);
}

// Obtener los archivos actual o de una ruta desde el directorio actual
void dir_fn(){
	// contador de archivos encontrados en el directorio
	int contador_archivos;
	// ruta auxiliar para no cambiar la local
	char ruta_aux[comandos_max];
	// hacemos una copia de la ruta actual
	strcpy(ruta_aux,ruta);
	// variable tipo struct dirent de la estructura del directorio
	struct dirent **directorio;
	// Si se define una ruta la concatemos a la ruta auxiliar precedido con un /
	if(args[1]){
		strcat(ruta_aux,"/");
		strcat(ruta_aux,args[1]);
	}
	// Con la ruta auxiliar almacenamos los ficheros en la variable struct directorio y guardamos la cantidad de archivos
	contador_archivos=scandir(ruta_aux,&directorio,NULL,alphasort);
	/*
	 * Si no existen archivos la ruta no existe
	 * Si el directorio solo contiene 2 archivos, significa que está vacio conteniendo solo
	 * la referencia del directorio local (.) y al padre (..)
	 * de lo contrario el directorio tiene archivos
	 */
	if(contador_archivos<0) perror("Error, la ruta indicada no existe\n");
	else if(contador_archivos==2) printf("El directorio [%s] esta vacio\n",ruta_aux);
	else{
		// Iteramos sobre los archivos imprimiendo el nombre
		for(int i = 0; i < contador_archivos; i ++)
			if(strcmp(directorio[i]->d_name,".")!=0 && strcmp(directorio[i]->d_name,"..")!=0) printf("%s\t",directorio[i]->d_name);
		printf("\n");
	}
}

// Imprime por pantalla la cadena de texto de los argumentos
void echo_fn(){
	int i=1;
	  while(args[i]){
		printf("%s ",args[i]);
		i++;
	  }
	  printf("\n");
}

// Comando de llamado al sistema para comandos no creados
void comando_sistema_fn(){
	// identificador del proceso y tubería de comunicación
	pid_t hijo;
	int tuberia[2];
	pipe(tuberia);
	// Se genera el nuevo proceso
	hijo=fork();
	if(hijo<0)
	{
		// Error, el hilo no se puede crear
		perror("Error! no se pudo crear un proceso hijo\n");
	}
	if (hijo==0){
		FILE *datos;
		/*
		 * Proceso hijo que ejecuta el comando con sus argumentos y almacena el estado
		 * execvp devuelve 0 si ha sido exitoso y -1 si exitío error
		 */
		int estado = execvp(comando,args);
		close (tuberia[0]);
		datos = fdopen(tuberia[1], "w");
		// Coloca el estado en la tuberia
		fprintf(datos, "%d", estado);
		fclose(datos);
		// Termina el proceso
		exit(-1);
	}
	else
	{
		// Proceso padre que espera que el proceso hijo termine
		wait(NULL);
		FILE *datos;
		// Variable de estado del comando que ejecuto el hijo, inicializado a 0
		int estado_leido = 0;
		close(tuberia[1]);
		datos=fdopen(tuberia[0], "r");
		// Se almacena el nuevo valor del estado del la ejecución del comando
		fscanf(datos, "%d", &estado_leido);
		// Si se obtiene un -1 es decir, entra al if se imprime un error
		if(estado_leido){
		  perror("El comando no se reconoce\n");
		}
		fclose(datos);
	}
}
