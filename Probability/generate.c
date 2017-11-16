#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

void readConf(char* file, int* batches, int* items, int* percentBad, int* samples);
void genDatasets(int batches, int items, int percentBad);
void genSimParams ();


void readConf(char* file, int* batches, int* items, int* percentBad, int* samples){
	FILE* fp = fopen(file, "r");
	
}

void genDatasets(int batches, int items, int percentBad){
	FILE* fp;
	int dir = mkdir("files", 0777);
	char filename[10];
	int i = 0, j = 0;
	for(i = 0; i<batches; i++){
		sprintf(filename, "files/ds%d.txt", i+1);	
		fp = fopen(filename, "w");
		for(j = 0; j<items; j++){
			fprintf(fp, "%c\n", 'g');
		}
	}
}

void genSimParams (){
	
	FILE* fp = fopen("SimParameters.dat", "wb");
	// FILE* fpw = fopen("SimParameters.dat", "wb");

	int a = 10;
	printf("%d\n", a);

	int events = 500;
	int nums[a];
	int cats = 6;
	int sims = 4;

	int freq[] = {3, 5, 7, 5, 2, 3};

	if(fp!=NULL){
		int i = 0, k = 0;
		fwrite(&sims, sizeof(int), 1, fp);
		for(i = 0; i<sims; i++){
			fwrite(&cats, sizeof(int), 1, fp);
			for(k = 0; k<cats; k++)
				fwrite(&freq[k], sizeof(int), 1, fp);
			fwrite(&events, sizeof(int), 1, fp);
		}
	}
	fclose(fp);

}
