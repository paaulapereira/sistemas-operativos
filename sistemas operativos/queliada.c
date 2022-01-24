#include <stdio.h>
#include <unistd.h>

int main(void)
{
  fork();
  int num1, num2, resta;
  printf("Ingrese el primer número\n"); //el \n es para una nueva línea
  scanf("%d", &num1); //el %d es para numeros
  printf("Ingrese el segundo número\n");
  scanf("%d", &num2);
  resta = num1 - num2;
  
  printf("La resta es %d\n", resta);
  return 0;
}
