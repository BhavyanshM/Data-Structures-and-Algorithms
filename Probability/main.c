#include <stdio.h>
#include <stdlib.h>
#include "generate.h"
#include "analytic.h"
#include "monteCarlo.h"

void fprint(float* nums, int n);
void print(int* nums, int n);

int main (){
	int i = 0;
	//FILE* fp = fopen("SimParameters.dat", "r+b");
	// FILE* fpw = fopen("SimParameters.dat", "wb");

	genSimParams();

	int cats = 0;
	int sims = 0;
	int events = 0;
	

	int input = 0;
	while(input==0 || input==1){
		printf("\nPlease enter a number from the set {0, 1, 2} to:\n");
		printf("\t0 : Run the Monte Carlo Simulation\n");
		printf("\t1 : Run the Monte Carlo Algorithm for the Chip Company\n");
		printf("\t2 : Exit");
		printf("\nInput:");
		scanf("%d", &input);

		if(input == 0){
			printf("Simulation Running>...\n");

			FILE* fp = fopen("SimParameters.dat", "r+b");

			float* partial;
			float* prob;
			float expectedValue = 0.0;

			if(fp!=NULL){
				fread(&sims, sizeof(int), 1, fp);
				printf("sims=%d\n", sims);
				for(i = 0; i<sims; i++){
					fread(&cats, sizeof(int), 1, fp);
					partial = (float*)malloc(cats*sizeof(float));
					prob = (float*)malloc(cats*sizeof(float));
					printf("cats:%d\n", cats);
					int freq[cats];
					fread(&freq, cats*sizeof(int), 1, fp);
					print(freq, cats);
					fread(&events, sizeof(int), 1, fp);
					printf("events:%d\n", events);
					probability(freq, prob, cats);
					fprint(prob, cats);
					cummulative(prob, partial, cats);
					fprint(partial, cats);
					//simulate(partial, events, cats);					
				}
			}

			fclose(fp);

		}else if(input == 1){
			printf("Algorithm Running>...\n");
			int batches, items, batchPercentBad, itemPercentBad, samples;
			int d = 0;
			char filename[50];
			for(d = 0; d<4; d++){
				sprintf(filename, "c%d.txt", d+1);
				readConf(filename, &batches, &items, &batchPercentBad, &itemPercentBad, &samples);
				printf("Running:\n");
				printf("Number of batches of items: %d\n", batches);
				printf("Number of items in each batch: %d\n", items);
				printf("Percentage of batches containing bad items: %d\n", batchPercentBad);
				printf("Percentage of items that are bad in a batch: %d\n", itemPercentBad);
				printf("Items sampled from each set: %d\n", samples);
			}

			genDatasets(100, 100, 10, 8);



		}else if(input == 2){
			break;
		}		
	}
	return 0;
}

void print(int* nums, int n){
	int i = 0;
	for(i = 0; i<n; i++){
		printf("%d ", nums[i]);
	}
	printf("\n");
}

void fprint(float* nums, int n){
        int i = 0;
        for(i = 0; i<n; i++){
                printf("%.2f ", nums[i]);
        }
        printf("\n");
}

