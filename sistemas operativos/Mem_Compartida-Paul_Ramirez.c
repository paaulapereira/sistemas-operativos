#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <wait.h>
#include <sys/types.h>
#include <sys/mman.h>

static int *num1, *num2, *flag;

int main(void){


    pid_t son;
    num1 = mmap(NULL, sizeof *num1,PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1,0);
    num2 = mmap(NULL, sizeof *num2,PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1,0);
    flag = mmap(NULL, sizeof *flag,PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1,0);

    *flag=0;
    son=fork();
    if(son<0){
        perror("Error al crear proceso\n");
        exit(-1);
    }
    if (son > 0)
    {   
        while(*flag == 0) {};
            int sum = *num1+*num2;
            printf("La suma es de: %d\n",sum);
    }
    else if (son == 0)
    {
        printf("Ingrese dos numeros\n");
        scanf("%d%d",num1,num2);
        *flag=1;
        exit(0);
    }

    
    
    return 0;

}