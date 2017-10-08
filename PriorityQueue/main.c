#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LAMBDA 2
#define MUE 3
#define SERVERS 2

long f(int n);
float getPercentIdleTime(int lambda, int mu, int servers);
float getAveragePeopleInSystem(float P0, int lambda, int mu, int servers);
float power(float a, int n);
float getAverageTimeTaken(float L, int lambda);
float getAverageSizeQueue(float L, int lambda, int mu);
float getAverageTimeInQueue(float Lq, int lambda);
float getUtilizationFactor(int lambda, int mu, int servers);

int main(){
//	customer pq[200];
	float P0 = getPercentIdleTime(LAMBDA, MUE, SERVERS);
	printf("%f\n", getPercentIdleTime(LAMBDA, MUE, SERVERS));
	float L = getAveragePeopleInSystem(P0, LAMBDA, MUE, SERVERS);
	float W = getAverageTimeTaken(L, LAMBDA);
	float Lq = getAverageSizeQueue(L, LAMBDA, MUE);
	float Wq = getAverageTimeInQueue(Lq, LAMBDA);
	float rho = getUtilizationFactor(LAMBDA, MUE, SERVERS);
	printf("P0: %f\n", P0);	
	printf("L: %f\n", L);
	printf("W: %f\n", W);
	printf("Lq: %f\n", Lq);
	printf("Wq: %f\n", Wq);
	printf("rho: %f\n", rho);
	return 0;
}
