// bot curl -d fnumber=4 localhost:80/cgi-bin/func.py


#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc , char argv[]){

    if (argc<=1) {printf("usage: ./bot N , N=nº_calls (int>0)\n\n"); return 0;}
    //if (argv[1]<0) {printf("usage: ./bot N , N=nº_calls (int>0)\n\n"); return 0;}
    int arg = (int) strtol(argv[1], NULL, 10);
    printf("%d sfve", arg);
/*
    for (int i=0;i<(int) argv[1];i++){
        system("curl -d fnumber=4 localhost:80/cgi-bin/func.py");
    }
*/
    return 0;
}