#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "lcs.h"
#include "similarity.h"



int main(){
	FILE* fp = fopen("twoSequences.txt", "r");

	char* input;

	char X[2000];
	char Y[2000];
	char* LCS;

	fscanf(fp, "%s\n", X);
	fscanf(fp, "%s\n", Y);

	fclose(fp);

	// printf("%s , %s\n", X, Y);
	lcs(X, Y, LCS);
	printf("\n");


	FILE* msfp = fopen("multipleSequences.txt", "r");
	int num = 0;
	fscanf(msfp, "%d\n", &num);

	int* starts = NULL;
	starts = (int*)malloc(num*sizeof(int));
	startings(num, msfp, starts);

	display(num, msfp, starts);	
	printf("\n\n");

	
	
	fclose(msfp);

	

	// printf("LCS length is:%d\n", opt_lcs("colldegeclavpelk", "chocolateclvpk"));

	return 0;
}
