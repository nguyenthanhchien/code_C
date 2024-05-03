#include<stdio.h>
#define PRINT_MENU_ITEM(number,item) printf("%d.%s\n",number,item);
#define PRINT_MENU(...)\
    do{\
        const char* items[] = {__VA_ARGS__};\
        int n = sizeof(items)/sizeof(items[0]);\
        for(int i=0;i<n;i++){\
            PRINT_MENU_ITEM(i+1,items[i])\
        }\
    }while (0)

#define CASE_OPTION(number,function)    case number: function();break;
#define HANDLE_OPTION(option, ...) \
    switch (option) { \
    __VA_ARGS__ \
    default: printf("Invalid option!\n"); \
    }

void feature1() { printf("Feature 1 selected\n"); }
void feature2() { printf("Feature 2 selected\n"); }
void feature3() { printf("Feature 3 selected\n"); }
void feature4() { printf("Feature 4 selected\n"); }

int main()
{
    int option;
    scanf("%d",&option);
    PRINT_MENU("Option1","Option2");
    HANDLE_OPTION(option,CASE_OPTION(1,feature1) CASE_OPTION(2,feature2))
    return 0;
}