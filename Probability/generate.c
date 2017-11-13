#include <stdio.h>
#include <stdlib.h>

void readConf(char* file, int* batches, int* items, int* percentBad, int* samples){
	FILE* fp = fopen(file, "r");
}

void genDatasets(int batches, int items, int percentBad){
	FILE* fp = fopen("dsi", "w+");
	for(int i = 0; i<batches; i++){
		for(int j = 0; j<items; j++){
			if(rand()%100)
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
		fwrite(&a, sizeof(int), 1, fp);
		for(int i = 0; i<a; i++){
			fwrite(&cats, sizeof(int), 1, fp);
			fwrite(&freq, sizeof(freq), 1, fp);
			fwrite(&sims, sizeof(int), 1, fp);
		}
	}

	return 0;
}
