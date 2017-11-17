#include <stdio.h>
#include <stdlib.h>
#include "generate.h"
#include "analytic.h"
#include "monteCarlo.h"
#include <math.h>

void toIntArray(float* partial, int* class, int size);
void fprint(float* nums, int n);
void print(int* nums, int n);
void initArray(int* arr, int size);

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
			printf("Simulation Running>...\n\n");

			FILE* fp = fopen("SimParameters.dat", "r+b");

			float* partial;
			float* prob;
			float expectedValue = 0.0;
			float simValue = 0.0;
			int* class;

			if(fp!=NULL){
				fread(&sims, sizeof(int), 1, fp);
				// printf("sims=%d\n", sims);
				for(i = 0; i<sims; i++){

					//Input number of parameters from SimParameters.dat
					fread(&cats, sizeof(int), 1, fp);


					//Alloacte memory to data structures
					partial = (float*)malloc(cats*sizeof(float));
					prob = (float*)malloc(cats*sizeof(float));
					class = (int*)malloc(cats*sizeof(int));

					//Input the rest of data
					// printf("cats:%d\n", cats);
					int freq[cats];
					fread(&freq, cats*sizeof(int), 1, fp);
					// print(freq, cats);
					fread(&events, sizeof(int), 1, fp);

					//Analytical Calculations
					probability(freq, prob, cats);
					// fprint(prob, cats);
					cummulative(prob, partial, cats);
					// fprint(partial, cats);
					expectedValue = expected(prob, cats);

					//Simulation and Calculations
					toIntArray(partial, class, cats);
					// print(class, cats);
					initArray(freq, cats);
					simulate(class, freq, events, cats);	
					// print(freq, cats);				
					probability(freq, prob, cats);
					simValue = expected(prob, cats);

					//Print the results
					printf("Simulation %d\n\n", i+1);
					printf("\tN:%d\n", events);
					printf("Simulated Result: %.2f\n", simValue);
					printf("Expected Value: %.2f\n", expectedValue);
					printf("Percent Error: %.5f\n", (float)(-1)*(simValue - expectedValue)/expectedValue);
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
				printf("\nRunning:\n");
				printf("\tNumber of batches of items: %d\n", batches);
				printf("\tNumber of items in each batch: %d\n", items);
				printf("\tPercentage of batches containing bad items: %d\n", batchPercentBad);
				printf("\tPercentage of items that are bad in a batch: %d\n", itemPercentBad);
				printf("\tItems sampled from each set: %d\n\n", samples);
				genDatasets(batches, items, itemPercentBad, batchPercentBad);

				// parse("files", batches, items, samples);


				printf("\n\nSummary\n\nRun: %d\n", i);
				printf("\tNumber of batches of items: %d\n", batches);
				printf("\tNumber of items in each batch: %d\n", items);
				printf("\tPercentage of batches containing bad items: %d\n", batchPercentBad);
				printf("\tPercentage of items that are bad in a batch: %d\n", itemPercentBad);
				printf("\tItems sampled from each set: %d\n\n", samples);
				printf("Base = %.2f exponent = %d\n", (100- itemPercentBad)/100.0, samples);
				printf("P(failure to detect bad item) = %.7f\n", pow((100- itemPercentBad)/100.0, (float)samples));
				printf("P(batch is good) = %.7f\n", 1.0 - pow((100- itemPercentBad)/100.0, (float)samples));
				printf("Percentage of bad batches detected = %d\n", (int)100 - (int)(pow((100- itemPercentBad)/100.0, (float)samples)*100));
			}


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

void toIntArray(float* partial, int* class, int size){
	int i = 0; 
	for(i = 0; i<size; i++){
		class[i] = partial[i]*100;
	}
}

void initArray(int* arr, int size){
	int i = 0;
	for(i = 0; i<size; i++){
		arr[i] = 0;
	}
}