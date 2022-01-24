//PROYECTO FINAL DE SISTEMAS OPERATIVOS: MINI SHELL
//ALUMNA: ADRIANA GABRIELA RODRÍGUEZ LINARES

//LIBRERIAS A UTILIZAR
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/types.h>

//DEFINICIÓN DE VARIABLES GLOBALES
//Número máximo de parametros de un comando
#define num_parametros_max 10
//Número máximo de carácteres de un comando
#define num_caracteresc_max 260

//CHARS
//Variable que guarda la ruta actual
char ruta_actual[num_caracteresc_max];
char comando_ingresado[num_caracteresc_max];
char *argumentos[num_parametros_max];


//DEFINICIÓN DE FUNCIONES
//Ejecuta todos los comandos
void bucle_shell();
//Ejecucion de comandos del sistema
void comandos_sistemas();
//Pequeña calculadora
void calculadora_bebe();



//FUNCIÓN PRINCIPAL DEL PROGRAMA
int main(void){

	//Getcwd obtiene la ruta del directorio actual
	getcwd(ruta_actual,num_caracteresc_max);

	//Mensaje de bienvenida
	printf("------------------------------------------------------------------------------\n");
	printf("			¡BIENVENIDO! SOY UNA MINI-SHELL\n");
	printf("------------------------------------------------------------------------------\n");
    printf("		Ven...entra a mi casa y ¡siéntete cómodo!\n");
	printf("				 INSTRUCCIONES:\n");
	printf("Para ver lo que puedo hacer, escribe un comando que quieres que ejecute.\n");
	printf("Para salir de casa, escribe 'exit'.\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");

	//Ejecución de la shell
	bucle_shell();

	return 0;
}//finaliza el main


void bucle_shell(){

	//Definición de la flag para iniciar=0/finalizar=1 el programa
	int finalizar_programa= 0;

	//Ejecución de todo el programa	mientras la flag valga 1
	while(!finalizar_programa){

	//Impimir el nombre de identificación y la ruta actual
	printf("AdrianaRL@sistemasoperativos:~%s>",ruta_actual);

	//Ir borrando el contenido de el char que guarda los comandos, para ingresar un nuevo comando
	__fpurge(stdin); memset(comando_ingresado,'\0',num_caracteresc_max);

	//El usuario ingresa el comando
	scanf("%s",comando_ingresado);

	//CONDICIONES:
	//Condición para salir del programa
	if(strcmp(comando_ingresado,"exit")==0){
	 printf("Bueno..¡Adiós! Me vienes a visitar otro día:)...\n");
	 //Asignamos el valor 1 a la flag para que el bucle termine su ejecución
	 finalizar_programa=1;

	 //Condición para ver los archivos contenidos en el directorio actual
	}else if(strcmp(comando_ingresado,"contenido")==0){
		strcpy(comando_ingresado,"ls");
		comandos_sistemas();//aquí llamamos a la función execvp
		printf("¡Acabas de ver todo el contenido que tengo escondido! Ya no puedo tener privacidad...\n");

	//Condición para limpiar la consola
	}else if(strcmp(comando_ingresado,"limpiar")==0){
		strcpy(comando_ingresado,"clear");
		comandos_sistemas();//aquí llamamos a la función execvp
		printf("Muchas gracias. Ahora mi casa está limpia, trata de no ensuciar más por favor...\n");

	//Condición para ejecutar la calculadora bebé
	} else if(strcmp(comando_ingresado,"bebe")==0){
	    puts("¡Te presento a mi bebé!\n");
		calculadora_bebe();

	//Condición que equivale al comando pwd de Linux
	}else if(strcmp(comando_ingresado,"ubicacion")==0){
		printf("Te presento este lugar de mi casa llamado:\n");
		printf("%s\n",ruta_actual);//llamamos a la ruta actual
	//Condición que equivale a cambiarse del directorio actual
	}else if (strcmp(comando_ingresado,"who")==0){
		strcpy(comando_ingresado,"who");
		printf("¿Quién eres tú?...\n");
		comandos_sistemas();//aquí llamamos a la función execvp

	//Condición para el comando ifcongig que muestra la ip de la red de conexión actual
	}else if (strcmp(comando_ingresado,"ip")==0){
		strcpy(comando_ingresado,"ifconfig");
		printf("Esta es la IP de la red...\n");
		comandos_sistemas();//aquí llamamos a la función execvp
	}else if (strcmp(comando_ingresado,"fecha")==0){
		strcpy(comando_ingresado,"date");
		comandos_sistemas();//aquí llamamos a la función execvp
	//Condición para el proceso de la shell
	}else if (strcmp(comando_ingresado,"process")==0){
		strcpy(comando_ingresado,"ps");
		//printf("In...\n");
		comandos_sistemas();//aquí llamamos a la función execvp

	//Condición para cualquier otra cosa que se ingrese
	}else{
		perror("Pues no lo conozco... Pero  me puedes hablar sobre otro :D\n");
	}

	}//cerrar el while

}


//Función para la mini-calculadora
void calculadora_bebe(){
	//Opciones de la calculadora
	int opcion;
	//Flag para verificar la exixtencia del bebé
	int no_bebe=0;

	//Mensaje de bienvenida
	printf("------------------------------------------------------------------------------\n");
	printf("			¡BIENVENIDO! SOY LA CALCULADORA BEBÉ\n");
	printf("------------------------------------------------------------------------------\n");
	printf("\n");
	printf("Soy una calculadora recién nacida. ¡Mamá dice que aprendo muy rápido!\n");
	printf("Así que hasta ayer me enseñó mamá a sumar y restar :D\n");
	printf("Hoy te enseñaré lo buena que soy en matemáticas a mi corta edad:)\n");
	printf("\n");

	while(!no_bebe){
	printf("¿Quieres que te reste dos números? O,o,ooo ¿Quieres que te sume dos números?\n");
	printf("Presiona 1 = SUMAR o 0 = RESTAR.Para SALIR y volver a la shell, ingresa 9.\n");
	scanf("%d", &opcion);

    //Suma
	if(opcion==1){
	int valor1, valor2, total;
	printf("------------------------------------------------------------------------------\n");
	printf("			¡TE ENSEEÑARÉ LO RÁPIDO QUE SUMO!\n");
	printf("\n");
	puts("Ingresa el numero 1:\n");
	scanf("%d",&valor1);
	puts("Ingresa el numero 2:\n");
	scanf("%d",&valor2);
	total = valor1 + valor2;
	printf("------------------------------------------------------------------------------\n");
	printf("RESULTADO: %i + %i = %i\n",valor1, valor2, total);
	printf("------------------------------------------------------------------------------\n");
    //Resta
	}else if (opcion==0){
    int valor1, valor2, total;
	printf("------------------------------------------------------------------------------\n");
	printf("			¡TE ENSEEÑARÉ LO RÁPIDO QUE RESTO!\n");
	printf("\n");
	puts("Ingresa el numero 1:\n");
	scanf("%d",&valor1);
	puts("Ingresa el numero 2:\n");
	scanf("%d",&valor2);
	total = valor1 - valor2;
	printf("------------------------------------------------------------------------------\n");
	printf("RESULTADO: %i - %i = %i\n",valor1, valor2, total);
	printf("------------------------------------------------------------------------------\n");
	//Salir y volver a la shell
	}else if (opcion==9){
	puts("Vuelve pronto por favor, ¡pueda que mamá me enseñe más cosas pronto!:(...¡Adiós!");
	bucle_shell();
	no_bebe=1;
	}else{
		perror("Opción no valida. ¡¡¡DIJE QUE INGRESARAS 1/0/9!!!");
	}
	}
}


//Ejecucion de comandos del sistema: ya no hay que llamar a cada rato a execvp y se lo pasamos por tuberias
void comandos_sistemas(){

	pid_t hijo;
	int tuberia[2];
	pipe(tuberia);

	hijo=fork();
	if(hijo<0)
	{
		// Exepción cuando el hilo no se puede crear
		perror("El hijo no pudo nacer lastimosamente.\n");
	}
	if (hijo==0){
		FILE *datos;

		char * args[] = {comando_ingresado, NULL};//esta shell no ejecuta argumentos
		printf("%s\n", comando_ingresado);
		//Con execvp ejecutarmos la orden dada
		int estadoProcesoHijo = execvp(comando_ingresado,args);
		close (tuberia[0]);
		datos = fdopen(tuberia[1], "w");
		//Estado  en la tuberia
		fprintf(datos, "%d", estadoProcesoHijo);
		fclose(datos);
		exit(-1);//estado cero para exitoso y -1 para error
	}else{
		wait(NULL);//En espera de que termine el hijo
		FILE *datos;
		int estadoProcesoHijo = 0;
		close(tuberia[1]);
		datos=fdopen(tuberia[0], "r");
		// leemos el estado devuelto del hijo
		fscanf(datos, "%d", &estadoProcesoHijo);
		if(estadoProcesoHijo){
		  perror("Espera...pensé que lo conocía.\n");
		}
		fclose(datos);
	}

}
