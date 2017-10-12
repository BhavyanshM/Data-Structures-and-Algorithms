#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "queue.h"
#include "priority.h"
#include "model.h"
/*
#define LAMBDA 2
#define MUE 3
#define SERVERS 2
*/
#define PQ_SIZE 201

void processNextEvent(customer** pq, int* serversAvailable, customer** FIFO, int size, int* last, int mu, float* absoluteTime);

float getNextRandomInterval(int avg){
	float result = (float)rand()/(float)RAND_MAX;
	//result = (-1)*(1.0/(float)avg)*log(result);
	return result;
}

void print(customer* event){
	printf("\tp=%.2f\t", event->pqtime);
	printf("\tat=%.2f\t", event->arrivalTime);
	printf("\tsos=%.2f\t", event->startOfService);
	printf("\tdt=%.2f\n", event->departureTime);
}

float totalTimeInSystem = 0;
float totalIdleTime = 0;
float totalTimeOfSim = 0;
float totalTimeInQueue = 0;
float totalServiceTime = 0;

int main(){
	customer* pq[PQ_SIZE];
	int last = 0;
	init_pq(pq, 0, PQ_SIZE);	
	customer* FIFO = NULL;
	int n = 25;

	int LAMBDA = 0;
	int MUE = 0;
	int SERVERS = 0;

//	Input from User on the parameters of the program
	printf("Please enter the total number of customers (n):");
	scanf("%d", &n);
	
	int totalCustomers = n;
	printf("Please enter the number of average arrivals in a time period (Lambda):");
	scanf("%d", &LAMBDA);

	printf("Please enter the number of customers served in unit time (mu):");
	scanf("%d", &MUE);

	printf("Please enter the total number of servers (M):");
	scanf("%d", &SERVERS);


//	Computer Simulation for the Service Center
//	BEGIN
	float absoluteTime = 0.0;
	float curTime = 0.0;
	float prevTime = 0.0;
	int serversAvailable = SERVERS;
	int lambda = LAMBDA;
	int mu = MUE;
	int i = 0;
	int pq_size = 0;
///*	
//	Place first arrivals in PQ

	char* temp = "";
	pq_size = 1;
	while(pq_size>0){
		if(pq_size == -1)pq_size = 0;
		// scanf("%s", temp);
		// if(strcmp(temp, "n")==0){
		init_pq(pq, pq_size+1, PQ_SIZE);
		// }else if(strcmp(temp, "p")==0){
			// print_pq(pq, PQ_SIZE, pq_size);
		// }
		// print_pq(pq, PQ_SIZE, pq_size);
		// printf("SERVERS_AVAIL:%d\n", serversAvailable);
		// print_queue(FIFO);
		

		// printf("n=%d, pq_size=%d, time=%.2f, M=%d\n", n, pq_size, absoluteTime, serversAvailable);
		processNextEvent(pq, &serversAvailable, &FIFO, PQ_SIZE, &pq_size, mu , &curTime);
		if(n>0 && pq_size <= SERVERS +1){
			//generateNextSetOfArrivals();
			while(n>0 && pq_size<PQ_SIZE-1){
				// printf("n:%d\n",n);
				// printf("INSIDE:n=%d, pq_size=%d, time=%.2f\n", n, pq_size, absoluteTime);
				// print_pq(pq, PQ_SIZE, pq_size);
				absoluteTime += getNextRandomInterval(lambda);
				insert(pq, NULL, absoluteTime, 0, PQ_SIZE, &pq_size);
				n--;
			}
			// printf("OUT\n");
		}
	}
	totalTimeOfSim = absoluteTime;

	printf("CurTime:%.2f, AbsTime:%.2f\n", curTime, absoluteTime);

	printf("\nResults from the Simulation:\n");
	printf("\tP0:.%.2f\n", 0.0);
	printf("\tW: %.2f\n", totalTimeInSystem/totalCustomers);
	printf("\tWq: %.2f\n", 0.0);
	printf("\trho: %f\n", totalServiceTime/(SERVERS*absoluteTime));
//	showResults();
//*/
//	Analytical Model and Calculations
//	BEGIN
	float P0 = getPercentIdleTime(LAMBDA, MUE, SERVERS);
	// printf("%f\n", getPercentIdleTime(LAMBDA, MUE, SERVERS));
	float L = getAveragePeopleInSystem(P0, LAMBDA, MUE, SERVERS);
	float W = getAverageTimeTaken(L, LAMBDA);
	float Lq = getAverageSizeQueue(L, LAMBDA, MUE);
	float Wq = getAverageTimeInQueue(Lq, LAMBDA);
	float rho = getUtilizationFactor(LAMBDA, MUE, SERVERS);


	printf("\nResults from the Analytical Calculations:\n");
	printf("\tP0: %f\n", P0);	
	printf("\tL: %f\n", L);
	printf("\tW: %f\n", W);
	printf("\tLq: %f\n", Lq);
	printf("\tWq: %f\n", Wq);
	printf("\trho: %f\n", rho);
	return 0;
}
///*
void processNextEvent(customer** queue, int* serversAvailable, customer** FIFO, int size, int* last, int mu, float* absoluteTime){
	// printf("CALLED:%d, %d, %d, %d\n", *serversAvailable, size, *last, mu);
	customer* event = top(queue, size, last);
	if(event == NULL || event->arrivalTime==-1)return;
	// print(event);

	if(event->arrivalTime != event->startOfService){//printf("Arrival Hit\n");
		if((*serversAvailable)>0){
			(*serversAvailable)--;
			*absoluteTime = event->arrivalTime;
			event->startOfService = event->arrivalTime;
			float tempTime = getNextRandomInterval(mu);
			totalServiceTime += tempTime;
			printf("%.2f\n", totalServiceTime);
			event->departureTime = event->arrivalTime + tempTime;
			// print_pq(queue, PQ_SIZE, *last);
			insert(queue, event, event->departureTime, 1, 201, last);
			// printf("CHANGED_M:%d\n", *serversAvailable);
			// print(event);
			// printf("Servers:%d\n", *serversAvailable);
		}else {
			enqueue(FIFO, event);
		}
	}else {//printf("Departure Hit\n");
		(*serversAvailable)++;
		*absoluteTime = event->departureTime;
		totalTimeInSystem += event->departureTime - event->arrivalTime;

		//processStatistics();
		if(*FIFO!=NULL){
			customer* newEvent = dequeue(FIFO);
			newEvent->startOfService = event->departureTime;
			float tempTime = getNextRandomInterval(mu);
			totalServiceTime += tempTime;
			newEvent->departureTime = newEvent->startOfService + tempTime;
			insert(queue, newEvent, newEvent->departureTime, 1, 201, last);
			(*serversAvailable)--;
		}
	}
}

//*/

