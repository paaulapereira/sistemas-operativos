//Mini Shell Paula Pereira
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/types.h>

//aqui se definen las variables globales, el limite para parametros de un comando y el limite de caracteres para un comando
#define max_param 10
#define max_carac 260

//aqui se definen los arrays, en orden, uno para la ruta, otro para los comandos que serán ingresados y otro con los argumentos
char route[max_carac];
char comandos[max_carac];
char *argument[max_param];

//se definen las funciones, la primera ejecuta todos los comandos de la shell, la segunda los comandos del sistema, la tercera se enseÑa un listado con los comandos, la cuarta es una pequeña magia de numeros y la quinta para imprimir una arte!
void shell();
void sist_comandos();
void zeus_ayuda();
void magia_nike();
void arte_dionisio();

//esa es la funcion primordial
int main(void){

	//esa funcion se utiliza para obtener la ruta que se esta todo
	getcwd(route,max_carac);
	printf("----------------------------------------------------------------------------------------------\n");
	printf("............(¯`'..\n");
	printf("..............(¯'.(¯'............._/)/)\n");
	printf("...............(¯'..(¯'........((.....((                  ¡BUENOS DÍAS!\n");
	printf("................(¯`'.(¯'....((.)..(. ' /)\n");
	printf(".................(¯`'..(¯'((.)....|\\_/      Soy Edison, el Pegaso y estoy aqui para ayudarles!\n");
	printf(".....,,,~\"¯¯¯`'¯(_¸´(_.)......|                  Es un placer tenerlos aqui :)\n");
	printf("...(((./...........................)__      Para saber que habilidades tengo, escribe 'zeus'\n");
	printf("..((((.\\......),,...........(...../__`\\             y mi dueño te los dirá!\n");
	printf("..))))..\\ . .//...¯¯¯¯¯¯¯' \\.../... / /    Si quieres salir del Olimpo, escribe 'bajar'\n");
	printf(".(((...../ .// .............. | ./.....\\/            y volvemos al suelo.\n");
	printf(".))).....| ||.................| |...........         Muchas gracias por venir!\n");
	printf("((........) \\\\.................) \\...........\\|/    No te olvides divertirte!\n");
	printf("----------------------------------------------------------------------------------------------\n");
	shell();

	return 0; //con eso se termina la shell
}

//funcion para imprimir el listado de comandos
void zeus_ayuda(){
	printf("1 - bajar -> volvemos al suelo.\n");
	printf("2 - zeus -> invocamos Zeus, mi dueño, que te cuenta mis habilidades.\n");
	printf("3 - destinos -> te enseño a donde podemos ir.\n");
	printf("4 - arre -> aqui me dices que podemos seguir y cambiar el sitio donde estamos.\n");
	printf("5 - higia -> invocamos Hígia, la diosa de la limpieza.\n");
	printf("6 - oraculo -> preguntamos al Oráculo donde estamos.\n");
	printf("7 - atenea -> invocamos Atenea, la diosa de la sabiduría para decirte quien eres\n");
	printf("8 - hades -> invocamos a Hades, el dios del reino de los muertos.\n");
	printf("9 - cronos -> invocamos Cronos, el dios del tiempo, para saber donde fuimos anteriormente.\n");
	printf("10- hemera -> invocamos Hemera, la personificación del día para descubrir la fecha.\n");
	printf("11- hefesto -> invocamos Hefesto, el dios de muchos trabajadores para enseñarnos como van nuestros trabajos.\n");
	printf("12- dionisio -> invoca Dionisio, el dios de la arte para enseñarte algo bonito.\n");
	printf("13- nike -> desafia Nike, la diosa de la victoria a ver si falla con su magia.\n");
}

void magia_nike(){
	//creamos la presentacion de la magia
	int respuesta;
  int num=0;
  printf("-------------------------------------------------------------\n");
  printf("               MAGIA DE LAS CARTAS\n");
  printf("    Hola, soy Nike, la diosa de la victoria.\n");
  printf("   Siempre gano, y si no me crees, ¡te propongo una magia!\n");
  printf("   INSTRUCCIONES: \n");
  printf("   1- Piense en un número entre 0 y 63.\n");
  printf("   2- Mire en las cartas.\n");
  printf("   3- Si el número que has pensado esté en una de las cartas,\n");
  printf("   contéstame la pregunta con 1, y si no está, 0.\n");
  printf("                     EMPECEMOS...\n");
  printf("---------------------------------------------------------------\n");
  printf("       CARTA 1\n");
  //creamos las tarjetas con los numeros
  int carta1[4][8]= {{1 , 9 , 17, 25, 33, 41, 49, 57},
                {3 , 11, 19, 27, 35, 43, 51, 59},
                {5 , 13, 21, 29, 37, 45, 53, 61},
                {7 , 15, 23, 31, 39, 47, 55, 63}};

  int carta2[4][8]= {{2 , 10, 18, 26, 34, 42, 50, 58},
                {3 , 11, 19, 27, 35, 43, 51, 59},
                {7 , 14, 22, 30, 38, 46, 54, 62},
                {6 , 15, 23, 31, 39, 47, 55, 63}};

  int carta3[4][8]= {{4 , 12, 20, 28, 36, 44, 52, 60},
                {5 , 13, 21, 29, 37, 45, 53, 61},
                {6 , 14, 22, 30, 38, 46, 54, 62},
                {7 , 15, 23, 31, 39, 47, 55, 63}};

  int carta4[4][8]= {{8 , 12, 24, 85, 40, 44, 56, 60},
                {9 , 13, 25, 29, 41, 45, 57, 61},
                {10, 14, 26, 30, 42, 46, 58, 62},
                {11, 15, 27, 31, 43, 47, 59, 63}};

  int carta5[4][8]= {{16, 20, 24, 28, 48, 52, 56, 60},
                {17, 21, 25, 29, 49, 53, 57, 61},
                {18, 22, 26, 30, 50, 54, 58, 62},
                {19, 23, 27, 31, 51, 55, 59, 63}};

  int carta6[4][8]= {{32, 36, 40, 44, 48, 52, 56, 60},
                {33, 37, 41, 45, 49, 53, 57, 61},
                {34, 38, 42, 46, 50, 54, 58, 62},
                {35, 39, 43, 47, 51, 55, 59, 63}};
	//imprimimos las tarjetas y las preguntas
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 8; j++){
      printf("%d ", carta1[i][j]);
    }
    printf("\n");
  }
  printf("-----------------------\n");
  printf("¿El número que has pensado aparece en la carta 1? (SI=1; NO=0)\n");
  scanf("%d\n", &respuesta);
  if (respuesta==1) {
    num = num +1;
  }else if(respuesta==0){
    num = num;
  }else{
    printf("Ingrese una respuesta válida por favor\n");
  }
  num=num;
  printf("-----------------------\n");
  printf("       CARTA 2\n");
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 8; j++){
      printf("%d ", carta2[i][j]);
    }
    printf("\n");
  }
  printf("-----------------------\n");
  printf("¿El número que has pensado aparece en la carta 2? (SI=1; NO=0)\n");
  scanf("%d\n", &respuesta);
  if (respuesta==1) {
    num= num + 2;
  }else{
    num = num;
  }
  num=num;
  printf("-----------------------\n");
  printf("       CARTA 3\n");
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 8; j++){
      printf("%d ", carta3[i][j]);
    }
    printf("\n");
  }
  printf("-----------------------\n");
  printf("¿El número que has pensado aparece en la carta 3? (SI=1; NO=0)\n");
  scanf("%d\n", &respuesta);
  if (respuesta==1) {
    num= num + 4;
  }else{
    num = num;
  }
  num=num;
  printf("-----------------------\n");
  printf("       CARTA 4\n");
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 8; j++){
      printf("%d ", carta4[i][j]);
    }
    printf("\n");
  }
  printf("-----------------------\n");
  printf("¿El número que has pensado aparece en la carta 4? (SI=1; NO=0)\n");
  scanf("%d\n", &respuesta);
  if (respuesta==1) {
    num= num + 8;
  }else{
    num = num;
  }
  num=num;
  printf("-----------------------\n");
  printf("       CARTA 5\n");
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 8; j++){
      printf("%d ", carta5[i][j]);
    }
    printf("\n");
  }
  printf("-----------------------\n");
  printf("¿El número que has pensado aparece en la carta 5? (SI=1; NO=0)\n");
  scanf("%d\n", &respuesta);
  if (respuesta==1) {
    num= num + 16;
  }else{
    num = num;
  }
  num=num;
  printf("-----------------------\n");
  printf("       CARTA 6\n");
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 8; j++){
      printf("%d ", carta6[i][j]);
    }
    printf("\n");
  }
  printf("-----------------------\n");
  printf("¿El número que has pensado aparece en la carta 6? (SI=1; NO=0)\n");
  scanf("%d\n", &respuesta);
  if (respuesta==1) {
    num= num + 32;
  }else{
    num = num;
  }
  num=num;
	//imprimimos los números
  printf("El número que has pensado es %d\n", num);
	printf("Si el número que he dicho no es el mismo que has pensado, me has ganado, y por eso te regalo un búho\n");
	//dibujamos el buho
  printf("                  , _ ,\n");
  printf("                 ( o o )\n");
  printf("                /'` ' `'\\\n");
  printf("                |'''''''|\n");
  printf("                |\\\\'''//|\n");
  printf("                   \"\"\"\n");
  return 0;
}

void arte_dionisio(){
	//mini arte del comando proprio
	printf("-------------------------------------------------------------\n");
  printf("               						¡BIENVENIDO!\n");
	printf("          SOY EL DIOS DE LA ARTE, Y POR ESO TE ENSEÑO UNA\n");
	printf("            DE LAS MAYORES OBRAS QUE SE HAN HECHO HASTA HOY\n");
	printf("                    DE DA VINCI PARA USTED\n");
	printf("                           _,,ad8888888888bba,_\n");
  printf("                        ,ad88888I888888888888888ba,\n");
  printf("                      ,88888888I88888888888888888888a,\n");
  printf("                    ,d888888888I8888888888888888888888b,\n");
  printf("                   d88888PP"""" ""YY88888888888888888888b,\n");
  printf("                 ,d88\"'__,,--------,,,,.;ZZZY8888888888888,\n" );
  printf("                ,8IIl'\"                ;;l\"ZZZIII8888888888\n");
  printf("               ,I88l;'                  ;lZZZZZ888III8888888,\n");
  printf("             ,II88Zl;.                  ;llZZZZZ888888I888888,\n");
  printf("            ,II888Zl;.                .;;;;;lllZZZ888888I8888b\n");
  printf("           ,II8888Z;;                 `;;;;;''llZZ8888888I8888,\n");
  printf("           II88888Z;'                        .;lZZZ8888888I888b\n");
  printf("           II88888Z; _,aaa,      .,aaaaa,__.l;llZZZ88888888I888\n");
  printf("           II88888IZZZZZZZZZ,  .ZZZZZZZZZZZZZZ;llZZ88888888I888,\n");
  printf("           II88888IZZ<'(@@>Z|  |ZZZ<'(@@>ZZZZ;;llZZ888888888I88I\n");
  printf("          ,II88888;   `\"\"\" ;|  |ZZ; `\"\"\"     ;;llZ8888888888I888\n");
  printf("          II888888l            `;;          .;llZZ8888888888I888,\n");
  printf("         ,II888888Z;           ;;;        .;;llZZZ8888888888I888I\n");
  printf("         III888888Zl;    ..,   `;;       ,;;lllZZZ88888888888I888\n");
  printf("         II88888888Z;;...;(_    _)      ,;;;llZZZZ88888888888I888,\n");
  printf("         II88888888Zl;;;;;' `--'Z;.   .,;;;;llZZZZ88888888888I888b\n");
  printf("         ]I888888888Z;;;;'   \";llllll;..;;;lllZZZZ88888888888I8888,\n");
  printf("         II888888888Zl.;;\"Y88bd888P\";;,..;lllZZZZZ88888888888I8888I\n");
  printf("         II8888888888Zl;.; `\"PPP\";;;,..;lllZZZZZZZ88888888888I88888\n");
  printf("         II888888888888Zl;;. `;;;l;;;;lllZZZZZZZZW88888888888I88888\n");
  printf("         `II8888888888888Zl;.    ,;;lllZZZZZZZZWMZ88888888888I88888\n");
  printf("          II8888888888888888ZbaalllZZZZZZZZZWWMZZZ8888888888I888888,\n");
  printf("          `II88888888888888888b\"WWZZZZZWWWMMZZZZZZI888888888I888888b\n");
  printf("           `II88888888888888888;ZZMMMMMMZZZZZZZZllI888888888I8888888\n");
  printf("            `II8888888888888888 `;lZZZZZZZZZZZlllll888888888I8888888,\n");
  printf("             II8888888888888888, `;lllZZZZllllll;;.Y88888888I8888888b,\n");
  printf("            ,II8888888888888888b   .;;lllllll;;;.;..88888888I88888888b,\n");
  printf("            II888888888888888PZI;.  .`;;;.;;;..; ...88888888I8888888888,\n");
  printf("            II888888888888PZ;;';;.   ;. .;.  .;. .. Y8888888I88888888888b,\n");
  printf("           ,II888888888PZ;;'                        `8888888I8888888888888b,\n");
  printf("           II888888888'                              888888I8888888888888888b\n");
  printf("          ,II888888888                              ,888888I88888888888888888\n");
  printf("         ,d88888888888                              d888888I8888888888ZZZZZZZ\n");
  printf("      ,ad888888888888I                              8888888I8888ZZZZZZZZZZZZZ\n");
  printf("    ,d888888888888888'                              888888IZZZZZZZZZZZZZZZZZZ\n");
  printf("  ,d888888888888P'8P'                               Y888ZZZZZZZZZZZZZZZZZZZZZ\n");
  printf(" ,8888888888888,  \"                                 ,ZZZZZZZZZZZZZZZZZZZZZZZZ\n");
  printf("d888888888888888,                                ,ZZZZZZZZZZZZZZZZZZZZZZZZZZZ\n");
  printf("888888888888888888a,      _                    ,ZZZZZZZZZZZZZZZZZZZZ888888888\n");
  printf("888888888888888888888ba,_d'                  ,ZZZZZZZZZZZZZZZZZ88888888888888\n");
  printf("8888888888888888888888888888bbbaaa,,,______,ZZZZZZZZZZZZZZZ888888888888888888\n");
  printf("88888888888888888888888888888888888888888ZZZZZZZZZZZZZZZ888888888888888888888\n");
  printf("8888888888888888888888888888888888888888ZZZZZZZZZZZZZZ88888888888888888888888\n");
  printf("888888888888888888888888888888888888888ZZZZZZZZZZZZZZ888888888888888888888888\n");
  printf("8888888888888888888888888888888888888ZZZZZZZZZZZZZZ88888888888888888888888888\n");
  printf("88888888888888888888888888888888888ZZZZZZZZZZZZZZ8888888888888888888888888888\n");

}

void shell(){

	int concluir= 0; //aqui se crea el flag que va a mantener la shell funcionando

	while(!concluir){ //crea un bucle que mantiene el programa funcionando mientras no sea 0.
		printf("PauladeCostaPereira@pegasus:~%s>",route); //se imprime la ruta
		__fpurge(stdin); //limpia los comandos
		memset(comandos,'\0',max_carac);
		scanf("%s",comandos); //aqui se ingresa el comando que el usuario quiera

		//aqui abajo estan los comandos
		//comando para salir del programa
		if(strcmp(comandos,"bajar")==0){
		 printf("Muchas graciar por venir aqui visitarnos! ¡Eres siempre bienvenido aqui!\n");
		 //Asignamos el valor 1 a la flag para que el bucle termine su ejecución
		 concluir=1;

		 //comando para lisar los comandos
	 	} else if(strcmp(comandos,"zeus")==0){
			puts("Un segundo que estoy llamando mi dueño!\n");
			zeus_ayuda();

		 //comando para enseñar los directorios posibles para viajar
	 	}else if(strcmp(comandos,"destinos")==0){
			strcpy(comandos,"ls");
			sist_comandos(); //en esa funcion se llama el execvp para ejecutar los comandos
			printf("Cuántos sitios guays tenemos para ir! ¡Belerofonte se quedaría loco con tantas posibilidades!\n");

			//comando para cambiar de directorio, se llama arre puesto que en lo que se dice a los caballos cuando quieres seguir adelante
	  }else if(strcmp(comandos,"arre")==0){
	 		strcpy(comandos,"cd");
	 		sist_comandos();
		 	printf("¡Segure-se bien que vamos a dar un paseo!\n");

		//comando para limpiar la consola, cuyo nombre es por la diosa de la limpieza
		}else if(strcmp(comandos,"higia")==0){
			strcpy(comandos,"clear");
			sist_comandos();
			printf("Higia ha limpiado todo y esta pidiendo que seas más ordenado...\n");


		//comando para decirnos la localizacion, correspondiente al pwd, cuyo nombre es por los oraculos griegos
		}else if(strcmp(comandos,"oraculo")==0){
			printf("El Oráculo nos dice que estamos aqui:\n");
			printf("%s\n",route);

		//comando para decir el nombre del usuario, inspirado por atenea, la diosa de la sabiduría
		}else if (strcmp(comandos,"atenea")==0){
			strcpy(comandos,"who");
			printf("Atenea me esta diciendo que eres ...\n");
			sist_comandos();

		//comando para matar un programa que se ejecuta mal, cuyo nombre esta inspirado en Hades, el dios que reina los muertos
		}else if (strcmp(comandos,"hades")==0){
				strcpy(comandos,"kill");
				printf("Hades ha llamado el programa para su reino y ahora ya está finalizado!\n");
				sist_comandos();

		//comando para enseñar el historico de comando previamente hechos, cuyo nombre esta inspirado en Cronos, el dios del tiempo
		}else if (strcmp(comandos,"cronos")==0){
			strcpy(comandos,"history");
			printf("Cronos nos enseña que hemos hecho eso antes: \n");
			sist_comandos();

		//comando para saber la fecha, cuyo nombre esta inspirado en la diosa que es la personificacion del dia
		}else if (strcmp(comandos,"hemera")==0){
			strcpy(comandos,"date");
			sist_comandos();

		//comando para saber como estan los procesos de la shell, inspirado en hefesto, el dios de los trabajadores
		}else if (strcmp(comandos,"hefesto")==0){
			strcpy(comandos,"ps");
			sist_comandos();

			//comando extra que contiene una arte muy conocida, inspirada en el dios de la arte
		}else if (strcmp(comandos,"dionisio")==0){
			puts("Dionisio esta escogiendo entre su colección...\n");
			arte_dionisio();

			//comando extra que contiene una magia de adivinar un numero entre 1-63, inspirado en la diosa de la victoria
		}else if (strcmp(comandos,"nike")==0){
			puts("Nike esta preparando su magia...\n");
			magia_nike();
		//error que enseña se la persona inserta un comando que no existe
		}else{
			perror("He buscado por todo el Olimpo y no encontré lo que me estás pidiendo... Igual por el Panteón lo encuntras!\n");
		}

	}

}

void sist_comandos(){
	//en esa funcion se iran ejecutar los comandos del sistema y todo estará por pipes
	pid_t hijo;
	int tuberia[2];
	pipe(tuberia);

	if((hijo=fork())<0){ //se crea el proceso hijo
		perror("Ha ocurrido un error\n");
	}
	if (hijo==0){ //proceso hijo
		FILE *datos;
		char * argumentos[] = {comandos, NULL};
		printf("%s\n", comandos);
		int cuadroProceso = execvp(comandos,argumentos); //ejecutamos el comando y almacenamos el estado
		//el execvp devuelve 0 si ha salido bien y -1 si ha salido mal
		close (tuberia[0]); //cerramos el lado de la tuberia que no utilizamos
		datos = fdopen(tuberia[1], "w");
		//pasa el estado al pipe
		fprintf(datos, "%d", cuadroProceso);
		fclose(datos);
		exit(-1); //terminamos el proceso para ese lado de la tuberia
	}else{
		//proceso padre esperando que el proceso hijo esté
		wait(NULL);
		FILE *datos;
		int cuadroProceso = 0;
		close(tuberia[1]); //cierra el lado de la tuberia que no utilizamos
		datos=fdopen(tuberia[0], "r"); //aqui se lee los datos que ha pasado el hijo por el pipe
		fscanf(datos, "%d", &cuadroProceso);
		if(cuadroProceso){ //si se sale mal se imprime un error por la consola
		  perror("He buscado por todo el Olimpo y no encontré lo que me estás pidiendo... Igual por el Panteón lo encuntras!\n");
		}
		fclose(datos);
	}
	//se termina la funcion
}
