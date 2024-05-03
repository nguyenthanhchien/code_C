// C program to illustrate fopen()

#include <stdio.h>
#include <stdlib.h>

int main()
{

	// pointer demo to FILE
	FILE* demo;
    int display;
	// Creates a file "demo_file"
	// with file access as write-plus mode
	demo = fopen("demo_file.txt", "r");
    while (1)
    {
        display = fgetc(demo);
        if(feof(demo))
        {break;}
        printf("%c",display);

    }
    
	
	fclose(demo);

	return 0;
}
