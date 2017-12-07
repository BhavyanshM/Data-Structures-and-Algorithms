#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "lcs.h"
#include "similarity.h"

#define NEWLINE 1
#define OFFSET 3


int main(){
	FILE* fp = fopen("twoSequences.txt", "r");

	char* input;

	char X[2000];
	char Y[2000];
	char* LCS;

	fscanf(fp, "%s\n", X);
	fscanf(fp, "%s\n", Y);

	fclose(fp);

	printf("%s , %s\n", X, Y);
	lcs(X, Y, LCS);
	printf("\n");


	FILE* msfp = fopen("multipleSequences.txt", "r");
	int num = 0;
	fscanf(msfp, "%d\n", &num);

//	display(num, msfp);	
	printf("\n\n");

	int* starts = NULL;
	starts = (int*)malloc(num*sizeof(int));
	startings(num, msfp, starts);
	
	fclose(msfp);

	msfp = fopen("multipleSequences.txt", "r");
	char str[2000];
	fseek(msfp, 40  + OFFSET, SEEK_SET);
	fscanf(msfp, "%s\n", str);
	printf("%s\n", str);

	return 0;
}
