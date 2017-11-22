#include <stdio.h>
#include <stdlib.h>

typedef struct customer{
         float arrivalTime;
         float startOfService;
         float departureTime;
         float pqtime;
         struct customer* nextCust;
} customer;

void enqueue(customer** FIFO, customer* cust);
customer* dequeue(customer** FIFO);
void print_queue(customer* FIFO);

/*
int main(){

	customer* FIFO = NULL;
	customer* newCustomer = (customer*)malloc(sizeof(customer));
	newCustomer->pqtime = -1;
	newCustomer->nextCust = NULL;
	enqueue(&FIFO, newCustomer);
	customer* one = (customer*)malloc(sizeof(customer));
        one->pqtime = 0.32;	
	one->nextCust = NULL;
	enqueue(&FIFO, one);
	customer* two = (customer*)malloc(sizeof(customer));
        two->pqtime = 2.48;
	two->nextCust = NULL;
	enqueue(&FIFO, two);

	print_queue(FIFO);
	
	printf("DEQUEUE:%.2f\n", dequeue(&FIFO)->pqtime);

	print_queue(FIFO);

	printf("DEQUEUE:%.2f\n", dequeue(&FIFO)->pqtime);

        print_queue(FIFO);

	printf("DEQUEUE:%.2f\n", dequeue(&FIFO)->pqtime);

	print_queue(FIFO);

	return 0;
}

*/

void enqueue(customer** FIFO, customer* cust){
	// printf("ENQUEUEING\n");
	if(*FIFO==NULL){
		*FIFO = cust;
		return;
	}
	customer* root = *FIFO;
	while(root->nextCust!=NULL){
		root = root->nextCust;
	}
	root->nextCust = cust;
	root->nextCust->nextCust = NULL;
}

void print_queue(customer* FIFO){
	if(FIFO==NULL)return;
	printf("CUST:%.2f\n", FIFO->pqtime);
	while(FIFO->nextCust!=NULL){
		FIFO = FIFO->nextCust;
		printf("CUST:%.2f\n", FIFO->pqtime);
	}
}

customer* dequeue(customer** FIFO){
	// printf("DEQUEUEING\n");
	if(*FIFO == NULL)return NULL;
	customer* result;
	if((*FIFO)->nextCust==NULL){
		result = (*FIFO);
		(*FIFO) = NULL;
	}else{
		customer* temp = *FIFO;
		while(temp->nextCust->nextCust!=NULL){
			temp = temp->nextCust;
		}
		result = temp->nextCust;
		temp->nextCust = NULL;
	}
	return result;
}
