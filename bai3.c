#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;
int exception_code;
char *error_message;
enum ErrorCodes { NO_ERROR, FILE_ERROR, NETWORK_ERROR, CALCULATION_ERROR } test_code;

char* ERROR_CODE[] = {"NO_ERROR", "FILE_ERROR", "NETWORK_ERROR", "CALCULATION_ERROR"};

#define TRY if ((exception_code = setjmp(buf)) == 0)
#define CATCH(x) else if (exception_code == (x))
#define THROW(x, y) do {\
    printf("%s\n", #y);\
    longjmp(buf, x);\
} while (0)

#define condition_test(x, y) if (test_code == x) { THROW(x, y); }
#define PRINTF_CATCH(x)    CATCH(x){\
        printf("%s\n", error_message);}
void readFile() {
    printf("Đọc file...\n");
    error_message = ERROR_CODE[FILE_ERROR];
    condition_test(FILE_ERROR, "Lỗi đọc file: File không tồn tại.")
}

void networkOperation() {
    printf("networkOperation...\n");
    error_message = ERROR_CODE[NETWORK_ERROR];
    condition_test(NETWORK_ERROR, "Lỗi xử lý mạng: hãy kết nối lại !")
}

void calculateData() {
    printf("calculateData...\n");
    error_message = ERROR_CODE[CALCULATION_ERROR];
    condition_test(CALCULATION_ERROR, "Lỗi tính toán dữ liệu: kết quả không chính xác!")
}

int main() {
    error_message = ERROR_CODE[2];
    test_code = 2;
    TRY {
        readFile();
        networkOperation();
        calculateData();
    }PRINTF_CATCH(FILE_ERROR)
    PRINTF_CATCH(NETWORK_ERROR)
    PRINTF_CATCH(NO_ERROR)
    PRINTF_CATCH(CALCULATION_ERROR)
    return 0;
}
