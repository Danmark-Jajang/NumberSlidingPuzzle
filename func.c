#include "pz.h"

extern int *pz;
void init(Point *cPoint){
    int i,k;
#ifdef __DEBUG__
    int test[9] ={1,2,3,4,5,6,7,0,8};
#endif
    char arrow[10];
    count = 0;
    system("cls");
    printf("ENTER NAME: ");
    scanf(" %s",name);
    system("cls");
    printf("SET MAXCOUNT: ");
    scanf("%d",&maxcount);
    for(i=0;i<9;i++){
        pz[i] = rand()%9;
#ifdef __DEBUG__
        pz[i] = test[i];
#endif
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
    char arrow[10];
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
            strcpy(arrow,"UP");
            break;
        case KEY_DOWN:
            strcpy(arrow,"DOWN");
            break;
        case KEY_LEFT:
            strcpy(arrow,"LEFT");
            break;
        case KEY_RIGHT:
            strcpy(arrow,"RIGHT");
            break;
        default:
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
    count+=1;
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