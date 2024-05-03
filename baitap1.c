/*đây là bài tập code Macro c */
#include<stdio.h>
// liet ke gan value 1,2,3,4,5,6
typedef enum
{
    printError=1,
    printWarning,
    printInfo,
    printDebug,
    printCritical,
    printSuccess
} ACTION;


#define function(x) printf("%s\n", x)


#define CASE_OPTION(number, function, ...) \
    case number: function(__VA_ARGS__); break;

#define HANDLE_ERROR(condition, ACTION , ...) \
    do { \
        if (condition) { \
            switch (ACTION) { \
                CASE_OPTION(ACTION, function, #__VA_ARGS__) \
                default: printf("Invalid action!\n"); break; \
            } \
        } \
    } while(0)

int main() {
    int x = 1;
    ACTION type = printCritical;
    printf("value :%d\n", type);
    HANDLE_ERROR(x > 0,printError, "Error");
    HANDLE_ERROR(x > 0,printWarning, "Warning");
    HANDLE_ERROR(x > 0,printDebug, "Debug");
    HANDLE_ERROR(x > 0,printInfo, "Info");
    HANDLE_ERROR(x > 0,printCritical, "Critical");
    HANDLE_ERROR(x > 0,printSuccess, "Success");
    return 0;
}
