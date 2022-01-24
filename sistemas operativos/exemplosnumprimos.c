#include <stdio.h>

int es_primo(int);

int main(void) {
  /* code */
  int max, cuenta=0;
  long unsigned int i;//declarar el prototipo de la funcion
  printf("Introduce el número\n");
  scanf("%d", &max);
  for (i = 1; ; i++) {
    /* code */
    if (es_primo(i)==1) {
      printf("%lu\n", i);
      cuenta++;
      if (cuenta==max)
        break;
    }
  }
  return 0;
}

int es_primo(int n){
  int i;
  int primo=1;

  for (i = 2; i < n && primo==1; i++) {
    if (n%i==0) {
      primo=0;
    }
  }
  return primo;
}
