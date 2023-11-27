//2.// Identify the system calls to copy the content of one file to another and illustrate the same using a C progra
#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *fptr1, *fptr2;
	char sourceName[]="prg02.c";
	char destName[]="new_prg02.c";
	char c;
	fptr1 = fopen(sourceName, "r");
	if (fptr1 == NULL)
	{
		printf("Cannot open file %s \n", sourceName);
		exit(0);
	}
	fptr2 = fopen(destName, "w");
	if (fptr2 == NULL)
	{
		printf("Cannot open file %s \n", destName);
		exit(0);
	}
	c = fgetc(fptr1);
	while (c != EOF)
	{
		fputc(c, fptr2);
		c = fgetc(fptr1);
	}
	printf("\nContents copied to %s", destName);
	fclose(fptr1);
	fclose(fptr2);
	return 0;
}
