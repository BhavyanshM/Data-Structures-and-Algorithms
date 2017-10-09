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

void processNextEvent(customer** pq, int* serversAvailable, customer** FIFO, int size, int* last);

float getNextRandomInterval(int avg){
	float result = (float)rand()/(float)RAND_MAX;
	//result = (-1)*(1.0/(float)avg)*log(result);
	return result;
}

int main(){
	customer* pq[PQ_SIZE];
	int last = 0;
	init_pq(pq, PQ_SIZE);	
	customer* FIFO = NULL;
	int n = 5000;
/*
	int LAMBDA = 0;
	int MUE = 0;
	int SERVERS = 0;

//	Input from User on the parameters of the program
	printf("Please enter the total number of customers (n):");
	scanf("%d", &n);
	
	
	printf("Please enter the number of average arrivals in a time period (Lambda):");
	scanf("%d", &LAMBDA);

	printf("Please enter the number of customers served in unit time (mu):");
	scanf("%d", &MUE);

	printf("Please enter the total number of servers (M):");
	scanf("%d", &SERVERS);
*/

//	Computer Simulation for the Service Center
//	BEGIN
	float absoluteTime = 0.0;
	int serversAvailable = SERVERS;
	int i = 0;
	int pq_size = 0;
///*	
//	Place first arrivals in PQ
	
	while(pq_size>0){
		processNextEvent(pq, &serversAvailable, FIFO, PQ_SIZE, &pq_size);
		if(n>0 && pq_size <= SERVERS +1){
			//generateNextSetOfArrivals();
			while(pq_size<PQ_SIZE){
				absoluteTime += getNextRandomInterval(lambda);
				insert(pq, absoluteTime, 0, PQ_SIZE, &pq_size);
				n--;
			}
		}
	}
//	showResults();
//*/
//	Analytical Model and Calculations
//	BEGIN
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
///*
void processNextEvent(customer** queue, int* serversAvailable, customer** FIFO, int size, int* last){
	customer* event = top(queue, size, last);
	if(event.departureTime == -1){
		if(*serversAvailable>0){
			*serversAvailable--;
			event->startOfService = event->arrivalTime;
			event->departureTime = event->startOfService + getNextRandomInterval(mu);
			insert(queue, event->departureTime, 1, 201, &last);
		}else {
			enqueue(FIFO, event);
		}
	}else {
		*serversAvailable++;
		//processStatistics();
		if(*FIFO!=NULL){
			customer* newEvent = dequeue(FIFO);
			newEvent->startOfService = event->departureTime;
			newEvent->departureTime = newEvent->startOfService + getNextRandomInterval(mu);
			insert(queue, newEvent->departureTime, 1, 201, &last);
			*serversAvailable--;
		}
	}
}

//*/

