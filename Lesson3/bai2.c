#include<stdio.h>
#include<setjmp.h>

jmp_buf buf;
int exception_code;

#define TRY if((exception_code=setjmp(buf))==0)
#define CATCH(x)  else if(exception_code==(x))  
#define THROW(x)    longjmp(buf,x)

double divide(int a,int b)
{
    if(b==0)
    {
        THROW(1);// Mã lỗi 1 cho lôi chia 0
    }
    return (double)a/b;
}

int main()
{
    int a=5;int b=0;
    double result = 0.0;
    // gans value exception_code = setjmp(buf)
    TRY
    {
        result=divide(a,b);
        printf("result: %f\n",result);
    }CATCH(1)
    {
        printf("Error\n");
    }
    return 0;
}