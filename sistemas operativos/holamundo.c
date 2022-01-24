#include <stdio.h>
#include <unistd.h> //libreria estándar siempre que se utilice UNIX
#include <sys/syscall.h> //libreria para llamadas del sistema

int main(void) {
  /* code */
  //syscall(SYS_write, 1, "Hola mundo de mierda\n", 21);
  printf("pablo bobão\n");
  return 0;
}
