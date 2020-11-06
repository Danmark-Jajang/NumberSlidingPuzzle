#ifndef __PZ_H
#define __PZ_H

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

#endif