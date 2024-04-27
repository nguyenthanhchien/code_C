//Bài 1: Cải Tiến Hàm THROW
#include<stdio.h>
#include<setjmp.h>

jmp_buf buf;
int exception_code;
const char* error_messages[] = {
    "Division by zero",
    "No error"
};

#define TRY if((exception_code=setjmp(buf))==0)
#define CATCH(x)  else if(exception_code==(x))
#define THROW(x,y)    do{\
    printf("%s\n",#y);\
    longjmp(buf,x);\
    }while(0);
double divide(int a,int b)
{
    if(b==0)
    {
        THROW(1,"Error");// Mã lỗi 1 cho lỗi chia 0
    }
    else if (b==10)
    {
       THROW(10,"b = 10");
    }
    
    return (double)a/b;
}

int main()
{
    int a=5;int b=10;
    double result = 0.0;
    // gans value exception_code = setjmp(buf)
    TRY
    {
        result=divide(a,b);
        printf("result: %f\n",result);
    }CATCH(1)
    {
        printf("%s\n",error_messages[0]);
    }
    CATCH(10)
    {
        printf("%s\n",error_messages[1]);
    }
    return 0;
}