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

<<<<<<< HEAD
	int* a = malloc(sizeof(int)*6);
	a[0] = 9;
	a[1] = 3;
	a[2] = 34;
	a[3] = 5;
	a[4] = 1;
	a[5] = 65;
	int* b = malloc(sizeof(int)*5);
	b[0] = 1;
	b[1] = 5;
	b[2] = 2; 
	b[3] = 9;
	b[4] = 12;

	// reset(a, 6, b, 5);	

	// print(a, 5);
	// print(b, 6);
=======
	FILE* msfp = fopen("multipleSequences.txt", "r");
	int num = 0;
	fscanf(msfp, "%d\n", &num);

	display(num, msfp);	
	printf("\n\n");

	int* starts = NULL;
	starts = (int*)malloc(num*sizeof(int));
	startings(num, msfp, starts);
	
	fclose(msfp);

	msfp = fopen("multipleSequences.txt", "r");
	char str[2000];
	fseek(msfp, 38  + OFFSET, SEEK_SET);
	fscanf(msfp, "%s\n", str);
	printf("%s\n", str);
>>>>>>> 13486f5e74fb603a8cf5a727fb1828f9bde47843

	return 0;
}
