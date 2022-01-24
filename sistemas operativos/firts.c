#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <wait.h>
#include <sys/types.h>
#include <sys/mman.h>

#define limite 1000
static int *variable,*flag;

int main(void)  {
  pid_t father,process2;
  
  variable=mmap(NULL,sizeof *variable, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS,-1,0);
  flag=mmap(NULL,sizeof *flag, PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS,-1,0);
  *variable = 0;
  *flag=0;
  father=fork();

    if(father<0){
      perror("Error señores!");
      exit(-1);
    }
    if(father >0){
      process2 = fork();
    }
    if(father != 0 && process2 != 0){
      //Aqui es el padre
      while(wait(NULL)>0){
        printf("final a %d",*variable);
      }
    }
    if(father == 0){    
      int i;
      //Aqui hay que bloquear
      for (i=0;i< limite ;i++){
        while(*flag==0);
        *variable = *variable +1;
        *flag=0;
      }
        
        exit(1);
      //Este hijo va a sumar
    }
      else if(process2 == 0){
        //Esteste hijo va a restar
        int i;
        //Aqui va a bloquear
        for(i = 0;i<= limite;i++){
          while((*flag)==1);
          *variable = *variable-1;
          *flag=1;
        }
        exit(1);
      }
    
  
}
