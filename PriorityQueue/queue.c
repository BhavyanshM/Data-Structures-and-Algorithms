#include <stdio.h>
#include <stdlib.h>

typedef struct customer{
         float arrivalTime;
         float startOfService;
         float departureTime;
         float pqtime;
         struct customer* nextCust;
} customer;

int main(){

	customer* FIFO;
	customer* newCustomer = (customer*)malloc(sizeof(customer));
	newCustomer->pqtime = -1;
	newCustomer->nextCust = NULL;
	enqueue(FIFO, newCustomer);
	customer* one = (customer*)malloc(sizeof(customer));
        newCustomer->pqtime = 0;
	one(FIFO, one);
	customer* two = (customer*)malloc(sizeof(customer));
        two->pqtime = -1;
	enqueue(FIFO, two);

}

void enqueue(customer* FIFO, customer* cust){
	while(FIFO->nextCust!=NULL){
		FIFO = FIFO->nextCust;
	}
	FIFO->nextCust = cust;
}

void print_queue(){

}
