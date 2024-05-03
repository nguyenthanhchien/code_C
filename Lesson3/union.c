#include<stdio.h>
#include<stdint.h>

typedef union DATA {
    uint8_t arr1[5];
    uint8_t arr2[3];
    uint8_t arr3[6];
}DATA;

int main() {
    
    DATA test1;
    test1.arr1[0] = 10;

    printf("%d\n", test1.arr1[0]);
    return 0;
}
