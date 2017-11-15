#include <stdio.h>
#include <stdlib.h>
#include "generate.h"
#include "analytic.h"
#include "monteCarlo.h"

int main (){
	int i = 0;
	FILE* fp = fopen("SimParameters.dat", "r+b");
	// FILE* fpw = fopen("SimParameters.dat", "wb");

	int a = 10;
	printf("%d\n", a);

	int ar = 0;
	int nums[a];

	int input = 0;
	while(input==0 || input==1){
		printf("Please enter a number from the set {0, 1, 2} to:\n");
		printf("\t0 : Run the Monte Carlo Simulation\n");
		printf("\t1 : Run the Monte Carlo Algorithm for the Chip Company\n");
		printf("\t2 : Exit");
		printf("\nInput:");
		scanf("%d", &input);

		if(input == 0){
			printf("Simulation Running>...\n");
		}else if(input == 1){
			printf("Algorithm Running>...\n");
		}else if(input == 2){
			break;
		}		
	}

	if(fp!=NULL){
		fread(&ar, sizeof(int), 1, fp);
		fread(&nums, a*sizeof(int), 1, fp);
		printf("ar=%d\n", ar);
		for(i = 0; i<a; i++){
			printf("N:%d\n", nums[i]);
		}
	}

	genDatasets(10, 10, 10);

	return 0;
}

void print(int* nums, int n){
	int i = 0;
	for(i = 0; i<n; i++){
		printf("%d ", i);
	}
	printf("\n");
}
