#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getNextString(FILE* fp, char* input);

char* getNextString(FILE* fp, char* input){
	char result[2000];
	fscanf(fp, "%s\n", result);
	printf("%d\n", (int)strlen(result));
	input = result;
	return input;
}