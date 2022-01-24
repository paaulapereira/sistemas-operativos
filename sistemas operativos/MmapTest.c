#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/mman.h>


static int *num1, *fact, *flag;

int main(void){


    pid_t son;
    num1 = mmap(NULL, sizeof *num1,PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1,0);
    fact = mmap(NULL, sizeof *fact,PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1,0);
    flag = mmap(NULL, sizeof *flag,PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1,0);

    *flag=0;
    int i = 0;
    son=fork();
    while(1){
      if(son<0){
          perror("Error al crear proceso\n");
          exit(-1);
      }
      if (son > 0)
      {

          while (*flag != 0);
          printf("Ingresa un numero:");
          scanf("%d",num1);
          if(*num1 < 0){
              kill(son,0);
              break;
          }
          *flag = 1;
          while(*flag !=2);
          printf("El factorial de %d es: %d\n",*num1,*fact);
          *flag =0;
      }
      else if (son == 0)
      {
          while(*flag != 1);
          *fact = 1;
          i=2;
          for(;i<=*num1;i++){
              *fact*=i;
          }
          *flag=2;
      }
    }


    return 0;

}
