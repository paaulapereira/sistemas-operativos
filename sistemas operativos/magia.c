#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int main(void){
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
  printf("El número que has pensado es %d\n", num);
  printf("Si el número que he dicho no es el mismo que has pensado, me has ganado, y por eso te regalo un búho\n");


  printf("                  , _ ,\n");
  printf("                 ( o o )\n");
  printf("                /'` ' `'\\\n");
  printf("                |'''''''|\n");
  printf("                |\\\\'''//|\n");
  printf("                   \"\"\"\n");

  return 0;
}
