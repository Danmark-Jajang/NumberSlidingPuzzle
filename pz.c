/*
    최근 수정일: 2020-11-09 
    수정자: 김민석/Kim Minseok
    수정내용: c파일 분할
*/
// power쉘이나 cmd에서 dir로 경로 확인 후 파일 저장 뒤 gcc pz.c로 컴파일
// 컴파일 후 a.exe 파일 생성되면 .\a.exe 입력으로 파일 테스트하기
// gcc는 자동링크가 되어 여러 c파일을 파라메터로 주면 알아서 해줌
// gcc -c 하면 오브젝트파일이 생성(컴파일만 함)
// gcc -o 하면 이름 변경하면서 .exe 파일 생성
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
    char Date[20];
    char Time[20];
    int key=0;
    srand(time(NULL));
    fp = fopen("score.txt","r");
    if(fp==NULL){
        fclose(fp);
        fp = fopen("score.txt","w");
        fprintf(fp,"%10s %10s %10s %10s\n","Date","Time","Name","Score");
        fprintf(fp,"===================================================\n");
    }
    fclose(fp);
    fp = fopen("score.txt","a");
    pz = (int *)malloc(sizeof(int)*9);
    if(pz==NULL){
        free(pz);
        pz = NULL;
        return 1;
    }
    init(&cPoint);
    display(key);
    while(1){
        key = play(&cPoint);
        if(check()||count>maxcount){
            if(check()){
                printf("FINISH :)\n");
                _strtime(Time);
                _strdate(Date);
                fprintf(fp,"%10s %10s %10s %10d\n",Date, Time, name, count);
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
            else break;
        }
        if(key==KEY_STOP) break;
        if(key==KEY_RESTART){
            init(&cPoint);
            display(0);
        }
    }
    
    fclose(fp);
    free(pz);
    pz = NULL;

    return 0;
}