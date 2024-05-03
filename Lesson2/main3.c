#include<stdio.h>

//#define NDEBUG // bo qua loi va thuc thi chuong trinh
#include<assert.h>
// daaus "#" laf lay chuoi %s
#define LOG(condition,cmd) assert(condition && #cmd);
#define ASSERT_SIZE(type,size) assert(sizeof(type)==(size))
double thuong(int a,int b)
{
    LOG(b!=0,"ERROR")
    printf("thuong:%0.2f",(double)a/b);
    return (double)a/b;
}

int main(int argc,char const* argv[])
{
    
    thuong(5,0);
    ASSERT_SIZE(int,8);
    return 0;
}