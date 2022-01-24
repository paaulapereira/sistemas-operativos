#include <stdio.h>
int main(void)
{
  int array[10000], i;

  for (i = 0; i < 10000; i++) {
    /* code */
    array[i]= 1;
  }
  for (i = 0; i < 10000; i++) {
    /* code */
    printf("%d", array[i]);
  }

  return 0;
}
