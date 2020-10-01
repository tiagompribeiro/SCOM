// bot curl -d fnumber=4 localhost:80/cgi-bin/func.py


#include <time.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>




int main (int argc , char *argv[]){
    clock_t start,end;
    if (argc<=2) {printf("usage: ./bot N J, N=nº_calls  J=nº_tries (int>0)\n\n"); return 0;}
    if (atoi(argv[1])<=0) {printf("usage: ./bot N J, N=nº_calls J=nº_tries (int>0)\n\n"); return 0;}
    if (atoi(argv[2])<=0) {printf("usage: ./bot N J, N=nº_calls J=nº_tries  (int>0)\n\n"); return 0;}

    char str1[]="curl --silent -d fnumber=X localhost:80/cgi-bin/func.py > /dev/null";
	double cpu_time_used_total= 0;
	int random,num_samples=0;
    double media=0,desvio_aux=0;
    float x=1; 
    char aux;
    FILE *f;
    f = fopen("tempos.txt", "w");
    if (f == NULL)
    {
        printf("Can't open file for reading.\n");
    }

    for (int j=0;j< atoi(argv[2]); j++){
        for (int i=0;i< atoi(argv[1]);i++){

            random = (rand() % (5 - 1 + 1)) + 1;
            str1[25]= random + '0';
            start=clock();
            system(str1);
            end=clock();
            double cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
            cpu_time_used_total+= cpu_time_used;
            
            
        }
        //printf("took %f seconds to execute \n", cpu_time_used_total);
        fprintf(f,"%f \n", cpu_time_used_total);
        cpu_time_used_total=0;
    }
    fclose(f);
    // colocar o apontador no inico do ficheiro
    f = fopen("tempos.txt", "r");
    if (f == NULL)
    {
        printf("Can't open file for reading.\n");
    }


    for (int y=0;y< atoi(argv[2]); y++){
        fscanf(f, "%f", &x);
        media += x;
    }
    media = media/atoi(argv[2]);
    fseek(f, 0, SEEK_SET);
    for (int y=0;y< atoi(argv[2]); y++){
        fscanf(f, "%f", &x);
        desvio_aux += pow(x-media,2);
    }
    printf(" \n Media : %lf",media);
    printf(" \n Desvio +-: %lf",sqrt(desvio_aux/atoi(argv[2])));
    printf(" \n Percentagem desvio +-: %lf", sqrt(desvio_aux/atoi(argv[2]))/media);
    printf(" \n");
    return 0;
}

// compliar com gcc -lm   
// compliar com gcc -lm  para math.h 


// antes para  1518 took 0.139613 seconds to execute 

// agora para  1518 took 0.137379 seconds to execute 
