#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>



#define IZQUIERDA (i+nfil-1)%nfil     
#define DERECHA (i+1)%nfil		

#define PENSANDO	0
#define HAMBRE		1
#define COMIENDO	2

int nfil=5; 
int shmid, 
    semid; 
int *estado;  

void sintaxis(void)
{
  printf("Uso: filosofo <nï¿œmero>\n");
  return;
}

void muestra_estados(void)
{
  struct sembuf op;
  int i;

  op.sem_num=0;
  op.sem_op=-1;
  op.sem_flg=0;
  semop(semid, &op, 1);  

  for(i=0;i<nfil;i++)
    printf("F0:%d ",estado[i]);

  printf("\n");
  op.sem_num=0;
  op.sem_op=+1;
  op.sem_flg=0;
  semop(semid, &op, 1);  
}


void probar(int i)
{
  struct sembuf op;

  if(estado[i] == HAMBRE && estado[IZQUIERDA]!=COMIENDO && estado[DERECHA]!=COMIENDO)
  {
       estado[i]=COMIENDO;

       op.sem_num=i+1;
       op.sem_op=1;
       op.sem_flg=0;
       semop(semid, &op, 1);  
     }
}

void coger_tenedores(int i)
{
  struct sembuf op;

  op.sem_num=0;
  op.sem_op=-1;
  op.sem_flg=0;
  semop(semid, &op, 1);  

  estado[i]=HAMBRE;
  probar(i);

  op.sem_num=0;
  op.sem_op=+1;
  op.sem_flg=0;
  semop(semid, &op, 1);  

  op.sem_num=i+1;
  op.sem_op=-1;
  op.sem_flg=0;
  semop(semid, &op, 1);  

}

void dejar_tenedores(int i)
{
  struct sembuf op;

  op.sem_num=0;
  op.sem_op=-1;
  op.sem_flg=0;
  semop(semid, &op, 1);  

  estado[i]=PENSANDO;
  probar(IZQUIERDA);
  probar(DERECHA);

  op.sem_num=0;
  op.sem_op=+1;
  op.sem_flg=0;
  semop(semid, &op, 1);  
}


void pensar(void)
{
  muestra_estados();
  sleep(1); 
}

void comer(void)
{
  
  muestra_estados();
  sleep(1); 
}

int main(int argc, char *argv[])
{
  int i,a;
  struct sembuf op;

  if(argc!=2)
  {
    sintaxis();
    exit(0);
  }

  nfil=atoi(argv[1]);
  if(nfil<2 | nfil>10)
  {
    printf("Parametro incorrecto\n");
    printf("puede haber entre 2 y 10 filosofos\n");
    sintaxis();
    exit(0);
  }

  shmid=shmget(IPC_PRIVATE,nfil*sizeof(int), IPC_CREAT | 0600);
  if(shmid==-1)
  {
    perror("No pude reservar memoria compartida.\n");
    exit(0);
  }


  semid=semget(IPC_PRIVATE, nfil+1, IPC_CREAT | 0600);
  if(semid==-1)
  {
    perror("No pude reservar los semaforos.\n");
    exit(0);
  }

  

  op.sem_num=0;
  op.sem_op=1;
  op.sem_flg=0;
  semop(semid, &op, 1);  


  for(i=0;i<nfil;i++)
  {
    a=fork();
    switch(a)
    {
      case 0: 
        
	estado=(int *)shmat(shmid, 0, 0);
        while(1)  
	{
	  pensar(); 
	  coger_tenedores(i);
	  comer();
	  dejar_tenedores(i);
	}
        break;
      default: 
        break;
    }
  }

}