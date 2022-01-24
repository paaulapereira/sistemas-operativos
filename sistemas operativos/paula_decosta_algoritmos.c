#include<stdio.h>
#include<conio.h>

void present(){
  printf("\n");
  for( int i=0;i<3;i++)
  printf("%d\t",fr[i]);
}

int encontrarLRU(int time[], int n){  //hecho para encontrar el LRU
	int i, minimum = time[0], pos = 0;

	for(i = 1; i < n; ++i){
		if(time[i] < minimum){
			minimum = time[i];
			pos = i;
		}
	}

	return pos;
}

int full(int a[],int n)
{
    int k;
    for(k=1; k<=n; k++)
    {
        if(a[k]==-1)
            return 0;
    }
    return 1;
}


int main(void)
{
    //aqui empieza el OPT
    //declaracion de las variables
    int fr[5],t[5],page[25],u[5];
    int i,j,k,p, flag, pgn , np, t1;
    p=0;
    flag=0;
    clrscr();
    printf("Inserte el número de páginas:");
    scanf("%d",&np);
    printf("Inserte el tamaño de las páginas"\n);
    scanf("%d",&pgn);

    printf("Inserte la secuencia de las páginas"\n);
    for(i=1; i<=pgn; i++)
        scanf("%d",&page[i]);
    for(i=1; i<=np; i++)
        fr[i]=-1;
    for(i=1; i<=pgn; i++)
    {
        if(full(fr,np)==1)
           break;
        else
        {
            flag=0;
            for(j=1; j<=np; j++)
            {
               if(page[i]==fr[j])
                {
                    flag=1;
                    printf("          \t%d:\t",page[i]);
                    break;
                }
            }
            if(flag==0)
            {
                fr[p]=page[i];
                printf("          \t%d:\t",page[i]);
                p++;
            }

            for(j=1; j<=np; j++)
                printf(" %d  ",fr[j]);
            printf("\n");
        }
    }
    p=0;
    for(; i<=pgn; i++)
    {
        flag=0;
        for(j=1; j<=np; j++)
        {
            if(page[i]==fr[j])
            {
                flag=1;
                break;
            }
        }
       if(flag==0)
        {
            p++;
            for(j=1; j<=np; j++)
            {
                for(k=i+1; k<=pgn; k++)
                {
                    if(fr[j]==page[k])
                    {
                        u[j]=k;
                        break;
                    }
                    else
                        u[j]=21;
                }
            }
            for(j=1; j<=np; j++)
                t[j]=u[j];
            for(j=1; j<=np; j++)
            {
                for(k=j+1; k<=np; k++)
                {
                    if(t[j]<t[k])
                    {
                        t1=t[j];
                        t[j]=t[k];
                        t[k]=t1;
                    }
                }
            }
            for(j=1; j<=np; j++)
            {
                if(t[1]==u[j])
                {
                    fr[j]=page[i];
                    u[j]=i;
                }
            }
            printf("page fault\t");
        }
        else
            printf("          \t");
        printf("%d:\t",page[i]);
        for(j=1; j<=np; j++)
            printf(" %d  ",fr[j]);
        printf("\n");
    }
    printf("\n Número de fallos OPT:  %d",p+3);

    //aqui empieza el LRU
    int num_fr, num_pg, contador = 0, time[10], pos, faults = 0;
    	printf("Inserte número de fr:"\n);
    	scanf("%d", &num_fr);

    	printf("Inserte el número de páginas:"\n);
    	scanf("%d", &num_pg);

    	printf("Inserte referencia: "\n);

        for(i = 0; i < num_pg; ++i){
        	scanf("%d", &page[i]);
        }

    	for(i = 0; i < num_fr; ++i){
        	fr[i] = -1;
        }

        for(i = 0; i < num_pg; ++i){
        	flag1 = flag2 = 0;

        	for(j = 0; j < num_fr; ++j){
        		if(fr[j] == page[i]){
    	    		contador++;
    	    		time[j] = contador;
    	   			flag1 = flag2 = 1;
    	   			break;
       			}
        	}

        	if(flag1 == 0){
    			for(j = 0; j < num_fr; ++j){
    	    		if(fr[j] == -1){
    	    			contador++;
    	    			faults++;
    	    			fr[j] = page[i];
    	    			time[j] = contador;
    	    			flag2 = 1;
    	    			break;
    	    		}
        		}
        	}

        	if(flag2 == 0){
        		pos = encontrarLRU(time, num_fr);
        		contador++;
        		faults++;
        		fr[pos] = page[i];
        		time[pos] = contador;
        	}

        	printf("\n");

        	for(j = 0; j < num_fr; ++j){
        		printf("%d\t", fr[j]);
        	}
    	}

    	printf("\n Número de fallos del LRU = %d", faults);

    return 0;

}
