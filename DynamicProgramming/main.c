#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "lcs.h"
#include "similarity.h"

int main(){
	FILE* fp = fopen("twoSequences.txt", "r");

	char* input;

	printf("%s\n", getNextString(fp, input));
	printf("%s\n", getNextString(fp, input));
}


