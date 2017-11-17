#include <stdio.h>
#include <stdlib.h>
#include "monteCarlo.h"
#include <time.h>

short sample(char* filename, int sampleSize);
void parse(char* dir, int batches, int items);
int randomNum(int* visited, int size);

void parse(char* dir, int batches, int items){
	int i = 0;
	char filename[50];
	for(i = 0; i<10; i++){
		sample(filename, items);
	}
}

short sample(char* filename, int sampleSize){
	int i = 0;
	FILE* fp = fopen(filename, "r");
	short result = -1; 
	char chip = 'c';
	for(i = 0; i<sampleSize; i++){
		fscanf(fp, "%c\n", &chip);
		if(chip=='b'){
			result = 0;
		}else if(chip=='g'){
			result = 1;
		}
	}
	return result;
}

int randomNum(int* visited, int size){
	srand(time(NULL)*size);
	return rand()%100;
}
