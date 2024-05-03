//ucln cua n so 
#include <stdio.h>
#include <stdarg.h>

int uclnb(int a, int b) {
    if (b == 0)
        return a;
    return uclnb(b, a % b);
}

int ucln(int count, ...) {
    va_list args;
    va_start(args, count);
    int uclnd = va_arg(args, int);
    for (int i = 1; i < count; i++) {
        uclnd = uclnb(uclnd, va_arg(args, int));
    }
    va_end(args);
    return uclnd;
}

int main() {
    printf("GCD: %d\n", ucln(4,4, 8, 16, 32));
    return 0;
}
