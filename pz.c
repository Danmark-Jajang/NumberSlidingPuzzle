/*
    최근 수정일: 2020-11-09
    수정자: 김민석/Kim Minseok
    수정내용: 링크기능을 몰라 일단 pz.c 파일 안에 모든 기능 넣어둠\
     현제 주석처리된 모든 부분 나중에 확인
*/
// pwer쉘이나 cmd에서 dir로 경로 확인 후 파일 저장 뒤 gcc pz.c로 컴파일
// 컴파일 후 a.exe 파일 생성되면 .\a.exe 입력으로 파일 테스트하기

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include <time.h>
//#include "pz.h" 

//나중에 링크 기능 배우면 삭제하기
typedef struct _Point{
    int point;
}Point;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_STOP 'q'
#define KEY_RESTART 'r'

int count, maxcount;
char name[80];

void init(Point *cPoint);
void display(int key);
int getKey();
void getIndex(int key, Point cPoint, Point *mPoint);
void change(Point *cPoint, Point mPoint);
int play(Point *cPoint);
int check();
//나중에 링크 기능 배우면 삭제하기

int *pz;
int main(int argc, char ** argv){
    FILE *fp;
    Point cPoint;
    //char date[20];
    //char time[20];
    int key=0;

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

//나중에 링크 기능 배우면 삭제하기
void init(Point *cPoint){
    int i,k;
    char arrow[10];
    count = 0;
    system("cls");
    printf("Enter Name: ");
    scanf(" %s",name);
    system("cls");
    printf("Set Maxcount: ");
    scanf("%d",&maxcount);
    for(i=0;i<9;i++){
        pz[i] = rand()%9;
        for(k=0;k<i;k++){
            if(pz[k]==pz[i]){
                i--;
                break;
            }
        }
        if(pz[i]==0){
                cPoint->point = i;
        }
    }    
}
void display(int key){
    int i;
    char *arrow;
    system("cls");
    for(i=0;i<9;i++){
        if(pz[i]==0){
            printf("%3c",'*');
        }
        else{
            printf("%3d",pz[i]);
        }
        if(i%3==2){
            printf("\n");
        }
    }
    switch(key){
        case KEY_UP:
            arrow = "UP";
            break;
        case KEY_DOWN:
            arrow = "DOWN";
            break;
        case KEY_LEFT:
            arrow = "LEFT";
            break;
        case KEY_RIGHT:
            arrow = "RIGHT";
            break;
        default:
            arrow = "Non";
            break;
    }

    printf("COUNT: %d\n",count);
    printf("INPUT: %s\n",arrow);
}
int getKey(){
    int key = getch();
    if(key==224) key = getch();
    return key;
}
void getIndex(int key, Point cPoint, Point *mPoint){
    mPoint->point = cPoint.point;
    switch(key){
        case KEY_UP:
            if(cPoint.point>=3) mPoint->point = cPoint.point - 3;
            break;
        case KEY_DOWN:
            if(cPoint.point<=6) mPoint->point = cPoint.point + 3;
            break;
        case KEY_LEFT:
            if(cPoint.point%3>0) mPoint->point = cPoint.point - 1;
            break;
        case KEY_RIGHT:
            if(cPoint.point%3<2) mPoint->point = cPoint.point + 1;
            break;
        default:
            break;
    }
}
void change(Point *cPoint, Point mPoint){
    int temp;
    temp = pz[cPoint->point];
    pz[cPoint->point] = pz[mPoint.point];
    pz[mPoint.point] = temp;
    cPoint->point = mPoint.point;
}
int play(Point *cPoint){
    Point mPoint;
    int key = getKey();
    if(key==KEY_STOP) return KEY_STOP;
    if(key==KEY_RESTART) return KEY_RESTART;
    getIndex(key,*cPoint,&mPoint);
    change(cPoint,mPoint);
    count++;
    display(key);  
    return key; 
}
int check(){
    int i;
    for(i=0;i<8;i++){
        if(pz[i]!=i+1) return 0;
    }
    return 1;
}
//나중에 링크 기능 배우면 삭제하기