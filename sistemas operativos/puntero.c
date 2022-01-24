#include <stdio.h>

int main (void)
{
  int num, *p; //un puntero que tiene 4 bytes cuando pone asterisco antes del
  //un puntero es una variable que almacena una posicion de memoria
  num = 5;
  p=&num; //&devuelve la direccion de memoria de un elemento
  printf("el numero es %d y su direccion de memoria es %p\n", num, p);
  return 0;


}
