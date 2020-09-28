// bot curl -d fnumber=4 localhost:80/cgi-bin/func.py


#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main (int argc , char *argv[]){
    clock_t start,end;
    if (argc<=1) {printf("usage: ./bot N , N=nº_calls (int>0)\n\n"); return 0;}
    if (atoi(argv[1])<0) {printf("usage: ./bot N , N=nº_calls (int>0)\n\n"); return 0;}

	
	start=clock();
    for (int i=0;i< atoi(argv[1]);i++){
        system("curl -d fnumber=4 localhost:80/cgi-bin/func.py > /dev/null");
    }
	end=clock();
	double cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;
	printf("took %f seconds to execute \n", cpu_time_used);
    return 0;
}
