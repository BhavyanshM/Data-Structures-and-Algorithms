#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "lcs.h"
#include "similarity.h"

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


}


