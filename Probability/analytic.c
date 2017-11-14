#include <stdio.h>
#include <stdlib.h>
#include "analytic.h"

void probability(int* freq, float* prob, int n){
	int total = 0, i = 0;
	for(i = 0; i<n; i++){
		total += freq[i];
	}
	for(i = 0; i<n; i++){
		prob[i] = (float)freq[i]/(float)total;
	}
}

float expected(float* prob, int cats, int n){
	
}

void cummulative(float* prob, float* partial , int n){
	int i = 0;
	for(i = 0; i<n; i++){
		if(i==0){
			partial[i] = prob[i];
		}else{
			partial[i] = partial[i-1] + prob[i];
		}
	}
}

void simulate(float* partial, int n){
	
}
