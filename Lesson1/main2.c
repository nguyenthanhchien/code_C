#include<stdio.h>

#define DISPLAY_SUM(a,b)\
printf("this is macro to sum 2 number\n");\
printf("Result is:%d\n",a+b);

#define MAX(x,y) ((x)>(y) ? (x) : (y))
int main(){
    DISPLAY_SUM(2,3);
    //MAX(3,4);
    printf("max:%d",MAX(3,4));
}