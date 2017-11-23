#include <stdio.h>
#include <stdlib.h>
#include "analytic.h"
#include <time.h>
#include <math.h>

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

void simulate(int* class, int* freq, int events, int cats){
	int s = 0, e = 0, i = 0; 
	for(e = 0; e<events; e++){
		int r = 0;
		srand(time(NULL)*sin(e));
		// printf("Event:%d\n", e);
		r = abs(rand()%100);
		for(i = 0; i<cats-1; i++){
			// printf("Rand:%d\n", r);
			if(r>class[i] && r<class[i+1]){
				freq[i]++;
			}
		}
	}
}
