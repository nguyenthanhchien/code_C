// used "stdarg" library
#include<stdio.h>
#include<stdarg.h>

typedef struct 
{
   int x;
   int y;
}Points;

int sum(int count,...)
{
    va_list args;
    va_start(args,count);
    int sum=0;
    for(int i=0;i<count;i++)
    {
       sum+= va_arg(args,int);
    }
    printf("sum: %d\n",sum);
    va_end(args);
    return sum;
}
void DISLAY(int count,...)
{
    va_list args;
    va_start (args,count);
    // for(int i=0;i<count;i++)
    // {
    //     printf("vitri: %d, value:%d\n",i+1,va_arg(args,int));
    // }
    for(int i=0;i<count;i++)
    {
        Points tmp = va_arg(args,Points);
        printf("vitri: %d, valuex:%d,valuey:%d\n",i+1,tmp.x,tmp.y);
    }
    va_end(args);
}
int main()
{
    sum(4,1,2,3,4);
    //sum(3,1,2,3);
    //DISLAY(3,(Points){2,3},(Points){3,4},(Points){5,6});
    return 0;
}