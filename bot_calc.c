// bot curl -d fnumber=4 localhost:80/cgi-bin/func.py


#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>





int main (int argc , char *argv[]){
    clock_t start,end;
    if (argc<=2) {printf("usage: ./bot N J, N=nº_calls  J=nº_tries (int>0)\n\n"); return 0;}
    if (atoi(argv[1])<=0) {printf("usage: ./bot N J, N=nº_calls J=nº_tries (int>0)\n\n"); return 0;}
    if (atoi(argv[2])<=0) {printf("usage: ./bot N J, N=nº_calls J=nº_tries  (int>0)\n\n"); return 0;}

    char str1[]="curl --silent -d fnumber=X localhost:80/cgi-bin/func.py > /dev/null";
	double cpu_time_used_total= 0;
	int random; 
    char aux;
    FILE *f;
    f = fopen("tempos.txt", "w");

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
        printf("took %f seconds to execute \n", cpu_time_used_total);
        fprintf(f,"%f \n", cpu_time_used_total);
        cpu_time_used_total=0;
    }
    return 0;
}

// antes para  1518 took 0.139613 seconds to execute 

// agora para  1518 took 0.137379 seconds to execute 
