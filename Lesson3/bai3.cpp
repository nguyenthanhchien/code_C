// C Program to calculate size of an array using pointer arithmetic
#include <stdio.h>

int main()
{

	int Arr[] = { 12, 2, 3, 4, 5, 0 };
	// variable to store the size of Arr
	int length = (*(&Arr + 1) - Arr);
    printf( " %d\n",&Arr[0]);
	printf( " %d\n",&Arr[1]);
	printf( " %d\n",&Arr[2]);
	printf( " %d\n",&Arr[3]);
	printf( " %d\n",&Arr[4]);
	printf( " %d\n",&Arr[5]);
    printf( " %d\n", *(&Arr + 1));
	printf( " %d\n", &Arr + 1);
	printf( "Number of elements in Arr[] is: %d\n", length);
	return 0;
}
