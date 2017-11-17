#include <stdio.h>
#include <stdlib.h>
#include "monteCarlo.h"
#include <time.h>
#include <math.h>

short sample(char* filename, int items, int sampleSize);
void parse(char* dir, int batches, int items, int sampleSize);
int randomNum(int* visited, int size);

void parse(char* dir, int batches, int items, int sampleSize){
	FILE* fp;
	int i = 0;
	char filename[50];
	printf("Analyzing Data Sets:\n\n");
	for(i = 0; i<batches; i++){
		printf("%s, %d, %d, %d\n", dir, batches, items, sampleSize);
		sprintf(filename, "files/ds%d.txt", i+1);	
		fp = fopen(filename, "r");
		if(sample(filename, items, sampleSize)==1);
		printf("batch #%d is bad\n", i);
		fclose(fp);
	}
}

short sample(char* filename, int items, int sampleSize){
	int i = 0;
	FILE* fp = fopen(filename, "r");
	short result = 0; 
	char chips[items];
	for(i = 0; i<sampleSize; i++){
		srand(time(NULL)*sin(i));
		int shot = rand()%items;
		fread(&chips, items*sizeof(int), 1, fp);
		if(chips[i]=='b'){
			fclose(fp);
			return 1;
		}else if(chips[i]=='g'){
			fclose(fp);
			return 0;
		}
	}
	fclose(fp);
	return result;
}

int randomNum(int* visited, int size){
	srand(time(NULL)*size);
	return rand()%100;
}
