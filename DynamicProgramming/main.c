#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "lcs.h"
#include "similarity.h"



int main(){
	printf("\nPART 1\n\nReading local file: twoSequences.txt\n");
	FILE* fp = fopen("twoSequences.txt", "r");

	char* input;

	char X[2000];
	char Y[2000];
	char* LCS;

	fscanf(fp, "%s\n", X);
	fscanf(fp, "%s\n", Y);

	fclose(fp);

	// printf("%s , %s\n", X, Y);
	printf("\n");
	lcs(X, Y, LCS);
	printf("\n\n");


	printf("PART 2\n\nReading local file: multipleSequences.txt");
	FILE* msfp = fopen("multipleSequences.txt", "r");
	int num = 0;
	fscanf(msfp, "%d\n", &num);

	int* starts = NULL;
	starts = (int*)malloc(num*sizeof(int));
	startings(num, msfp, starts);

	printf("Performing similarity comparison on all unique pairings: multipleSequences.txt\n\n");
	display(num, msfp, starts);	
	printf("\n\n");

	
	
	fclose(msfp);

	

	// printf("LCS length is:%d\n", opt_lcs("colldegeclavpelk", "chocolateclvpk"));

	return 0;
}
