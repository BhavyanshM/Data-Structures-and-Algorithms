#include <stdio.h>
#include <stdlib.h>

int main (){
	
	FILE* fp = fopen("SimParameters.dat", "r+b");
	// FILE* fpw = fopen("SimParameters.dat", "wb");

	int a = 10;
	printf("%d\n", a);

	int ar = 0;
	int nums[a];

	if(fp!=NULL){
		fread(&ar, sizeof(int), 1, fp);
		fread(&nums, a*sizeof(int), 1, fp);
		printf("ar=%d\n", ar);
		for(int i = 0; i<a; i++){
			printf("N:%d\n", nums[i]);
		}
	}

	return 0;
}

void print(int* nums, int n){
	for(int i = 0; i<n; i++){
		printf("%d ", i);
	}
	printf("\n");
}