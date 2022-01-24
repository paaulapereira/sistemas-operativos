#include <stdio.h>
#include <unistd.h>
#include <time.h>
int main (void)
{

  // sizeof(); //devuelve el tamaño de algo
  double tiempo1=0.0, tiempo2=0.0;
  clock_t inicio,final, inicio2, final2;

  int array[10000], i, *p;
  p=array;

  for (i = 0; i < 10000; i++)
    array[i]= i;

  inicio=clock();
  for (i = 0; i < 10000; i++)
    printf("%d", array[i]);
  final=clock();
  tiempo1 +=(double)(final-inicio)/(CLOCKS_PER_SEC);

  inicio2=clock();
  for (p=array;p!=&array[10000];p++)
    printf("%d ", *p);
  final2=clock();
  tiempo2=(double)(final2-inicio2)/(CLOCKS_PER_SEC);

  printf("El tiempo 1 vale %f y el tiempo 2 vale %f\n", tiempo1, tiempo2);
  
  return 0;
}
