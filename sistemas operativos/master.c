#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

//QUE HACE: leer un programa que esta en disco duro, ejecutarle y pasarle el pipe

int main(void){
  pid_t hijo;
  int tuberia[2];
  char buffer[4096];

  pipe(tuberia);

  if((hijo=fork())<0)
  { //hijo tiene que se menor que 0, si es menor el resultado es un error
    perror("Error al crar el proceso nuevo\n");
    exit(-1);
  }
  if(hijo>0) //proceso padre
  {
    close(tuberia[1]);
    read(tuberia[0], buffer,sizeof(buffer));
    printf("Soy el padre con PID %d. Mi hijo %d me envía: \n %s\n", getpid(), hijo, buffer);
    wait(NULL);
  }
  else if(hijo==0)
  {
    close(tuberia[0]);
    dup2(tuberia[1], STDOUT_FILENO);
    execl("./slaveexe", "slave", NULL);
    puts("Idiota el que lea esta linea");
  }
  puts("Soy el padre, adios");
  return 0;

}
