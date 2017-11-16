#include <stdio.h>
#include <stdlib.h>
#include "generate.h"
#include "analytic.h"
#include "monteCarlo.h"

void print(int* nums, int n);

int main (){
	int i = 0;
	FILE* fp = fopen("SimParameters.dat", "r+b");
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

	
			if(fp!=NULL){
				fread(&sims, sizeof(int), 1, fp);
				printf("sims=%d\n", sims);
				for(i = 0; i<sims; i++){
					fread(&cats, sizeof(int), 1, fp);
					printf("cats:%d\n", cats);
					int freq[cats];
					fread(&freq, cats*sizeof(int), 1, fp);
					print(freq, cats);
					fread(&events, sizeof(int), 1, fp);
					printf("events:%d\n", events);
				}
			}


		}else if(input == 1){
			printf("Algorithm Running>...\n");



			genDatasets(10, 10, 10);



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
