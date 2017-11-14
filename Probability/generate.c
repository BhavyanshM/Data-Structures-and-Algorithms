#include <stdio.h>
#include <stdlib.h>

void readConf(char* file, int* batches, int* items, int* percentBad, int* samples);
void genDatasets(int batches, int items, int percentBad);
void genSimParams ();


void readConf(char* file, int* batches, int* items, int* percentBad, int* samples){
	FILE* fp = fopen(file, "r");
}

void genDatasets(int batches, int items, int percentBad){
	FILE* fp;
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

	int ar = 0;
	int nums[a];
	int cats = 12;
	int sims = 50;

	int freq[] = {3, 5, 7, 5, 2, 3, 1, 0, 4, 8, 9, 4};



	if(fp!=NULL){
		int i = 0;
		fwrite(&a, sizeof(int), 1, fp);
		for(i = 0; i<a; i++){
			fwrite(&cats, sizeof(int), 1, fp);
			fwrite(&freq, sizeof(freq), 1, fp);
			fwrite(&sims, sizeof(int), 1, fp);
		}
	}

}
