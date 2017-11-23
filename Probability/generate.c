#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <math.h>

#define MAX_CATS 50
#define MAX_FREQ 10

void genDatasets(int batches, int items, int itemPercentBad, int batchPercentBad);
void readConf(char* file, int* batches, int* items, int* batchPercentBad, int* itemPercentBad, int* samples);
void genSimParams ();


void readConf(char* file, int* batches, int* items, int* batchPercentBad, int* itemPercentBad, int* samples){
	FILE* fp = fopen(file, "r");
	fscanf(fp, "%d\n", batches);
	fscanf(fp, "%d\n", items);
	fscanf(fp, "%d\n", batchPercentBad);
	fscanf(fp, "%d\n", itemPercentBad);
	fscanf(fp, "%d\n", samples);	
	fclose(fp);
}

void genDatasets(int batches, int items, int itemPercentBad, int batchPercentBad){
	FILE* fp;
	int dir = mkdir("files", 0777);
	char filename[10];
	int i = 0, j = 0, bad = 0, badFiles = 0;
	for(i = 0; i<batches; i++){
		bad = 0;
		srand(time(NULL)*sin(i));
		sprintf(filename, "files/ds%d.txt", i+1);	
		fp = fopen(filename, "w");
		int batchShot = (rand()%100);
		if(batchShot<batchPercentBad){
			badFiles++;
			for(j = 0; j<items; j++){
				int shot = (rand()%100);
				if(shot<itemPercentBad){
					fprintf(fp, "%c\n", 'b');
					bad++;
				}else{
					fprintf(fp, "%c\n", 'g');
				} 
			}
			printf("Create bad set batch # %d, totBad = %d, total = %d, badpct = %d\n", i, bad, items, itemPercentBad);

		}else{
			for(j = 0; j<items; j++){
				fprintf(fp, "%c\n", 'g');
			}
		}
		fclose(fp);
	}
	printf("Total bad sets = %d\n", badFiles);
}

void genSimParams (){
	
	FILE* fp = fopen("SimParameters.dat", "wb");
	// FILE* fpw = fopen("SimParameters.dat", "wb");

	int a = 10;
	printf("%d\n", a);

	int events = 500;
	int nums[a];
	int cats = 6;
	int sims = 10;

	int freq[] = {3, 5, 7, 5, 2, 3};

	int tempRand = 0;

	if(fp!=NULL){
		int i = 0, k = 0;
		fwrite(&sims, sizeof(int), 1, fp);
		for(i = 0; i<sims; i++){
			srand(time(NULL)*sin(i));
			tempRand = rand()%MAX_CATS;
			cats = tempRand;
			fwrite(&tempRand, sizeof(int), 1, fp);
			for(k = 0; k<cats; k++){
				srand(time(NULL)*sin(k));
				tempRand = rand()%MAX_FREQ;
				fwrite(&tempRand, sizeof(int), 1, fp);
			}				
			fwrite(&events, sizeof(int), 1, fp);
		}
	}
	fclose(fp);

}
