#include <unistd.h> // getcwd

#include <stdio.h> // printf
//Constantes de linux 
#include <limits.h> //PATH_MAX
#include <stdlib.h> // realloc, malloc
#include <string.h> // strcmp
#include <sys/wait.h> //wait

// cantidad maxima de argumentos
#define CANTIDAD_MAXIMA_ARGUMENTOS 15
// numero de caracteres maximos
#define LONGITUD_MAXIMA 1024

/* declare your struct for a person here */
typedef struct{
  char *nombre;
  int posicion; 
}  historial;

historial historialShell[LONGITUD_MAXIMA];

int indiceActualHistorial = 0;
//LINUX LO DEFINE COMO 4096
//PATH_MAX
char ruta_actual[PATH_MAX];
char *orden;
char *parametros[LONGITUD_MAXIMA];

void directorioActual(char *buf);
void shell_loop();
char *leerLinea();
void actualizarHistorial(char *comandoEjecutado);
void print(char *t, int pos);
void ejecutarDesdeSistema();

void parsearParametros();

int main(int argc, char **argv)
{
  /*
  * Preconfiguraciones
  */
	system("clear");

	printf("                 /|  /|  ---------------------------------\n");
	printf("                 ||__||  |                                |\n");
	printf("                /   O O\\__  Hola! Bienvenido. Cada vez   |\n");
	printf("               /          \\     que necesites ejecutar   |\n");
	printf("              /      \\     \\  un comando, presione INTRO  |\n");
	printf("             /   _    \\     \\ ----------------------------------------\n");
	printf("            /    |\\____\\     \\      ||\n");
	printf("           /     | | | |\\____/      ||\n");
	printf("          /       \\| | | |/ |     __||\n");
	printf("         /  /  \\   -------  |_____| ||\n");
	printf("        /   |   |           |       --|\n");
	printf("        |   |   |           |_____  --|\n");
	printf("        |  |_|_|_|          |     \\----\n");
	printf("        /\\                  |\n");
	printf("       / /\\        |        /\n");
	printf("      / /  |       |       |\n");
	printf("  ___/ /   |       |       |\n");
	printf("|____/    c_c_c_C/ \\C_c_c_c\n");  
	printf("------------------------------------------------------------\n");

  directorioActual(ruta_actual);

  // Loop principal.
  shell_loop();


  return 0;
}

/*
* obtener el directorio actual
* char *buf Variable donde se guardará el directorio actual con logitud definida en PATH_MAX
*/
void directorioActual(char *buf){
 if (getcwd(buf, PATH_MAX) == NULL)
      perror("Error al obtener directorio actual");
    else
      printf("Directorio actual: %s\n", buf);

}
void shell_loop(){	 
	 char **args;
	 int debeFinalizar = 0;
	 do {
		// Imprimimos cada vez la ruta y el identificador de la Shell
		printf("eabol@v1.0:%s$ ",ruta_actual);
		fflush(stdin);
		//memset(orden, '\0', LONGITUD_MAXIMA);
		orden = leerLinea();
		parsearParametros();

		//Cada vez que se lee un comando se guarda en el historial
		actualizarHistorial(orden);

		/*for (int i = 0; i <= indiceActualHistorial; ++i)
		{
			printf("%s\n", historialShell[i].nombre);
		}*/
		indiceActualHistorial++;

		
		//salir de la shell
		if(strcmp(orden,"q")==0){

			printf("\nChao chao...\n");

			debeFinalizar = 1;
		}else if(strcmp(orden,"limpiar")==0){
			
			strcpy(orden,"clear");
			ejecutarDesdeSistema();
		} else if(strcmp(orden,"ls")==0){
			
			strcpy(orden,"ls");
			ejecutarDesdeSistema();
		}else if(strcmp(orden, "ubicacion")==0){
			directorioActual(ruta_actual);

		}else{
			ejecutarDesdeSistema();
		}

	}while(debeFinalizar != 1);

}

/*
* Historial para guardar comandos
*/
void actualizarHistorial(char *comandoEjecutado){
	historialShell[indiceActualHistorial].nombre = comandoEjecutado;
	historialShell[indiceActualHistorial].posicion = indiceActualHistorial;
}

char *leerLinea()
{
  int tamanoBuffer = LONGITUD_MAXIMA;
  int indiceActual = 0;
  //Creamos nuestra variable buffer que contendrá lo que leeremos por teclado
  //usamos malloc para asignar LONGITUD_MAXIMA  * el tamaño de char especificado en bytes
  char *buffer = malloc(sizeof(char) * tamanoBuffer);
  int caracter;

  if (!buffer) {
    perror("Error al asignar memoria de buffer de entrada\n");
  }
  /* use system call to make terminal send all keystrokesdirectly to stdin y desactivar echo */
  /*RAW MODE
	You write an appropriate control code to the console when you read an ^M. 
	The whole point of raw mode is that the console does not do things like recognize line ends, 
	backspaces, etc., etc., because you want to handle them yourself. Once you do that, you need 
	to handle all those things.
  */
  system ("/bin/stty raw -echo");
  int posicionActualEjecutado=indiceActualHistorial;
  do{
    // Leemos el caracter
    caracter = getchar();
    //printf("%d", caracter);
    //printf("%i\n", caracter);
    if (caracter == 127) { 
    	if (indiceActual>0){
    		
    		putchar('\b');
    		buffer[indiceActual]='\0';
	    	putchar(' ');
	    	//printf("%d", indiceActual);
	    	putchar('\b');
	    	indiceActual--;
    		
    	} 	
    	
    	
    }else{

    	 if (caracter == 65 || caracter == 66){

   	    	//system ("/bin/stty cooked echo");
	    	//printf("Se ha presionado la tecla de arriba \n");
	    	if (indiceActualHistorial > 0){

	    		if (caracter ==65){
	    			if (posicionActualEjecutado > 0){
		    			posicionActualEjecutado--;
		    		}
	    		}
	    		

	    		if (caracter == 66){
	    			if (posicionActualEjecutado < (indiceActualHistorial-1)){
		    			posicionActualEjecutado++;
		    		}
	    		}
	    		
	    		
	    		int i;
	    		for (i = 0; i<=indiceActual; ++i)
	    		{
	    			putchar('\b');
	    			putchar(' ');
	    			putchar('\b');
	    			
	    		}
	    		indiceActual = 0;
	    		memset(buffer, '\0', LONGITUD_MAXIMA);
	    		buffer = malloc(sizeof(char) * tamanoBuffer);
	    		strcpy(buffer, historialShell[posicionActualEjecutado].nombre);
	    		
	    		putchar(' ');
	    		putchar('\b');
	    		putchar(' ');
	    		printf("%s", buffer);
	    		indiceActual = strlen(buffer);	    		    
	    	}
	    	
	    }else{
	    	// Si leemos un EOF o un salto de linea se reemplaza con caracter nul y se retorna el valor.
	    if (caracter == EOF || caracter == 13) {
	    	system ("/bin/stty cooked echo");
		       printf("\n");	
		      buffer[indiceActual] = '\0'; //Caracter vacio

		      return buffer;

		    } else {
		    	if (caracter !=27){ //Eliminamos el caracter
		    		if (caracter != 91){ //eliminamos caracter
		      			buffer[indiceActual] = caracter;
		      			indiceActual++;
		      			putchar(caracter);
		    		}
		    			
		    	}
		    	
		    }
		    

		    // Si nos excedemos reasignamos memoria
		    if (indiceActual >= tamanoBuffer) {
		      tamanoBuffer += LONGITUD_MAXIMA;
		      buffer = realloc(buffer, tamanoBuffer);
		      if (!buffer) {
		        perror("Error al asignar memoria de buffer de entrada\n");
		      }
		    }
	    	
	    }


    }
  
  }while (1);
  
  /* use system call to set terminal behaviour to more normalbehaviour */
  system ("/bin/stty cooked echo");
}


//Ejecucion de comandos del sistema
void ejecutarDesdeSistema(){

	pid_t procesoHijo;
	int tuberia[2];
	pipe(tuberia);

	procesoHijo=fork();
	if(procesoHijo<0)
	{
		// Error, el hilo no se puede crear
		perror("Error! no se pudo crear un proceso hijo\n");
	}
	if (procesoHijo==0){
		FILE *datos;
		//Con execvp ejecutarmos la ordern dada
		//estado cero para exitoso y -1 para error
		
		int estado = execvp(orden,parametros);
		close (tuberia[0]);
		datos = fdopen(tuberia[1], "w");
		// Coloca el estado en la tuberia
		fprintf(datos, "%d", estado);
		fclose(datos);
		exit(-1);
	}
	else
	{
		// Esperamos a que termine el hijo
		wait(NULL);
		FILE *datos;
		int estadoProcesoHijo = 0;
		close(tuberia[1]);
		datos=fdopen(tuberia[0], "r");
		// leemos el estado devuelto del hijo
		fscanf(datos, "%d", &estadoProcesoHijo);
		if(estadoProcesoHijo){
		  perror("Comando no valido\n");
		}
		fclose(datos);
	}
}


// Extraer parametros del la orden a ejecutar
void parsearParametros(){
	int i;
	// parametroa a NULL
	for(i=0;i<(LONGITUD_MAXIMA-1);i++){
		parametros[i]=NULL;
	}
	// Split string into tokens
	// A sequence of calls to this function split str into tokens, 
	// which are sequences of contiguous characters separated by any of the characters that are part of delimiters.
	strtok(orden," ");
	// reiniciamos el contador
	i=0;
	// Extremos el comando a ejecutar
	parametros[i]=orden;
	/*
	 * parseamos los parametros 
	 * LONGITUD_MAXIMA -2 porque necesitamos que al final del array exista siempre un NULL siendo -1 
	 * porque el indice inicia en 0 y -2 al dejar siempre al final un valor NULL
	 * parametros[++i]=strtok(NULL," ") --> Agrega el siguiente argumento obteniendolos por sus tokens al array de argumentos
	 */
	while((parametros[++i]=strtok(NULL," ")) != NULL && i<(LONGITUD_MAXIMA-2));
}