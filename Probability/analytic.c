#include <stdio.h>
#include <stdlib.h>

void probability(int* freq, float* prob, int n){
	int total = 0;
	for(int i = 0; i<n; i++){
		total += freq[i];
	}
	for(int i = 0; i<n; i++){
		prob[i] = (float)freq[i]/(float)total;
	}
}

void cummulative(float* prob, float* partial , int n){
	for(int i = 0; i<n; i++){
		if(i==0){
			partial[i] = prob[i];
		}else{
			partial[i] = partial[i-1] + prob[i];
		}
	}
}

void simulate(float* partial, int n){
	
}