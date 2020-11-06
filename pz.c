#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include <time.h>
#include "pz.h"

int *pz;
int main(int argc, char ** argv){
    FILE *fp;
    Point cPoint;
    char date[20];
    char time[20];
    int key=0;
    pz = (int *)malloc(sizeof(int)*9);
    init(&cPoint);
    display(key);
    while(1){
        key = play(&cPoint);
        if(check()||count>=maxcount){
            if(check()){
                printf("FINISH :)\n");
            }
            if(count>maxcount){
                printf("COUNT OVER :(\n");
            }
            printf("CONTINUE?(Y/N): ");
            scanf(" %c",&key);
            if(key=='y'||key=='Y'){
                init(&cPoint);
                display(0);
            }
        }
        if(key==KEY_STOP) break;
        if(key==KEY_RESTART){
            init(&cPoint);
            display(0);
        }
    }
    
    free(pz);
    pz = NULL;
}