#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "queue.h"
#include "priority.h"
#include "model.h"

#define LAMBDA 2
#define MUE 3
#define SERVERS 5
#define PQ_SIZE 21

void processNextEvent(customer** pq, int* serversAvailable, customer** FIFO, int size, int* last, int mu, float* absoluteTime);

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
	int n = 30;
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
	int lambda = LAMBDA;
	int mu = MUE;
	int i = 0;
	int pq_size = 0;
///*	
//	Place first arrivals in PQ
	insert(pq, absoluteTime, 0, PQ_SIZE, &pq_size);

	char* temp = "";

	while(pq_size>0){
		// scanf("%s", temp);
		// if(strcmp(temp, "n")==0){

		// }else if(strcmp(temp, "p")==0){
		// 	print_pq(pq, PQ_SIZE, pq_size);
		// }
		print_pq(pq, PQ_SIZE, pq_size);
		printf("n=%d, pq_size=%d, time=%.2f, M=%d\n", n, pq_size, absoluteTime, serversAvailable);
		processNextEvent(pq, &serversAvailable, &FIFO, PQ_SIZE, &pq_size, mu , &absoluteTime);
		if(n>0 && pq_size <= SERVERS +1){
			//generateNextSetOfArrivals();
			while(pq_size<PQ_SIZE-1){
				printf("INSIDE:n=%d, pq_size=%d, time=%.2f\n", n, pq_size, absoluteTime);
				print_pq(pq, PQ_SIZE, pq_size);
				insert(pq, absoluteTime + getNextRandomInterval(lambda), 0, PQ_SIZE, &pq_size);
				n--;
			}
			printf("OUT\n");
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
void processNextEvent(customer** queue, int* serversAvailable, customer** FIFO, int size, int* last, int mu, float* absoluteTime){
	printf("CALLED:%d, %d, %d, %d\n", *serversAvailable, size, *last, mu);
	customer* event = top(queue, size, last);

	printf("\tp=%.2f\t", event->pqtime);
	printf("\tat=%.2f\t", event->arrivalTime);
	printf("\tsos=%.2f\t", event->startOfService);
	printf("\tdt=%.2f\n", event->departureTime);

	if(event->departureTime == -1){printf("Arrival Hit\n");
		if((*serversAvailable)>0){
			(*serversAvailable)--;
			*absoluteTime = event->arrivalTime;
			event->startOfService = event->arrivalTime;
			event->departureTime = event->arrivalTime + getNextRandomInterval(mu);
			insert(queue, event->departureTime, 1, 201, last);
			printf("Servers:%d\n", *serversAvailable);
		}else {
			enqueue(FIFO, event);
		}
	}else {printf("Departure Hit\n");
		(*serversAvailable)++;
		*absoluteTime = event->departureTime;
		//processStatistics();
		if(*FIFO!=NULL){
			customer* newEvent = dequeue(FIFO);
			newEvent->startOfService = event->departureTime;
			newEvent->departureTime = newEvent->startOfService + getNextRandomInterval(mu);
			insert(queue, newEvent->departureTime, 1, 201, last);
			(*serversAvailable)--;
		}
	}
}

//*/

