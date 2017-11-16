#include <stdio.h>
#include <stdlib.h>
#include "analytic.h"
#include <time.h>

void probability(int* freq, float* prob, int cats){
	int total = 0, i = 0;
	for(i = 0; i<cats; i++){
		total += freq[i];
	}
	for(i = 0; i<cats; i++){
		prob[i] = (float)freq[i]/(float)total;
	}
}

float expected(float* prob, int cats){
	float result = 0.0;
	int i = 0;
	for(i = 0; i<cats; i++){
		result += prob[i]*(i+1);
	}
	return result;
}

void cummulative(float* prob, float* partial , int cats){
	int i = 0;
	for(i = 0; i<cats; i++){
		if(i==0){
			partial[i] = prob[i];
		}else{
			partial[i] = partial[i-1] + prob[i];
		}
	}
}

void simulate(float* partial, int events, int cats, int sims){
	int s = 0, e = 0, i = 0; 
	for(s = 0; s<sims; s++){
		for(e = 0; e<events; e++){
			int r = rand();
			srand(time(NULL) + r);
			for(i = 0; i<cats-1; i++){
				r = (rand()*rand()*rand()*i)%100;
				printf("Rand:%d\n", r);
				if(r>partial[i] && r<partial[i+1]){
					printf("Between: %.2f && %.2f\n", partial[i] , partial[i+1]);
				}
			}
		}
	}
}
