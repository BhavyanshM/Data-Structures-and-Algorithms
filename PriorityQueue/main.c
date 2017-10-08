#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "queue.h"
#include "priority.h"
#include "model.h"

#define LAMBDA 2
#define MUE 3
#define SERVERS 2
#define PQ_SIZE 201

int main(){
	customer* queue[PQ_SIZE];
	int last = 0;

	init_pq(queue, PQ_SIZE);	

        print_pq(queue, 201, last);

        insert(queue, 23.4, 0, 200, &last);
        print_pq(queue, 201, last);

        insert(queue, 14.9, 0, 200, &last);
        print_pq(queue, 201, last);

        insert(queue, 4.3, 0, 200, &last);
	print_pq(queue, 201, last);

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
