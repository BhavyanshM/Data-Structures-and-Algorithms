#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "lcs.h"
#include "similarity.h"

void print(int* a, int n){
        int i = 0;
        for(i = 0; i<n; i++)
        printf("%d ", a[i]);
        printf("\n");
}

int main(){
	FILE* fp = fopen("twoSequences.txt", "r");

	char* input;

	//printf("%s\n", getNextString(fp, input));
	//printf("%s\n", getNextString(fp, input));

	char X[2000];
	char Y[2000];
	char* LCS;

	// getNextString(fp, X);
	// getNextString(fp, Y);

	fscanf(fp, "%s\n", X);
	fscanf(fp, "%s\n", Y);

	fclose(fp);

	printf("%s , %s\n", X, Y);

	lcs(X, Y, LCS);

	printf("\n");

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

	return 0;
}
