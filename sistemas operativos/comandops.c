#include <stdio.h>
#include <unistd.h>

int main(void){
  execl("/bin/ps", "ps", NULL);
  puts("Si sale esta linea toda la clase aprueba Sistemas Operativos\n");
  return 0;
}
