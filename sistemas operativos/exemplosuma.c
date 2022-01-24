#include <stdio.h>

int main(void) {
  /* code */
  int num1, num2, suma, producto, resta;

  printf("Ingrese el primer número\n"); //el \n es para una nueva línea
  scanf("%d", &num1); //el %d es para numeros
  printf("Ingrese el segundo número\n");
  scanf("%d", &num2);
  suma = num1 + num2;
  producto = num1*num2;
  resta= num1-num2;
  printf("La suma es %d\n", suma);
  printf("El producto es %d\n", producto);
  printf("La resta es %d\n", resta);

  return 0;
}
