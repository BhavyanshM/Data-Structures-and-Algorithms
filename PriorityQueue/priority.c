#include <stdio.h>
#include <stdlib.h>

typedef struct customer{
        float arrivalTime;
        float startOfService;
        float departureTime;
	float pqtime;
        struct customer* nextCust;
} customer;

void percolateUp(customer** queue, int last);
void insert(customer** queue, float time, short type, int size, int* last);
void print_pq(customer** queue, int size, int last);
customer* top(customer** queue, int size, int* last);
void percolateDown(customer** queue, int last);

int main(){
	printf("This works!\n");
	printf("Even this works!\n");
	customer* queue[201];

	int i = 0;
	for(i = 0; i<201; i++){
		queue[i] = (customer*)malloc(sizeof(customer));
		queue[i]->arrivalTime = -1;
	        queue[i]->startOfService = -1;
	        queue[i]->departureTime = -1;
	        queue[i]->pqtime = -1;
	        queue[i]->nextCust = NULL;
	}

	int last = 0;

	print_pq(queue, 201, last);

	insert(queue, 23.4, 0, 200, &last);
	print_pq(queue, 201, last);

	insert(queue, 14.9, 0, 200, &last);
        print_pq(queue, 201, last);

	insert(queue, 4.3, 0, 200, &last);
        print_pq(queue, 201, last);

	insert(queue, 233.9, 0, 200, &last);
        print_pq(queue, 201, last);

	insert(queue, 121.9, 0, 200, &last);
        print_pq(queue, 201, last);

	insert(queue, 20.9, 0, 200, &last);
        print_pq(queue, 201, last);

	insert(queue, 29.3, 0, 200, &last);
        print_pq(queue, 201, last);

	insert(queue, 94.34, 0, 200, &last);
        print_pq(queue, 201, last);

	insert(queue, 79.3, 0, 200, &last);
        print_pq(queue, 201, last);

	customer* min = top(queue, 201, &last);
	printf("\nTOP:%.2f", min->pqtime);
	print_pq(queue, 201, last);

	min = top(queue, 201, &last);
        printf("\nTOP:%.2f", min->pqtime);
        print_pq(queue, 201, last);

	min = top(queue, 201, &last);
        printf("\nTOP:%.2f", min->pqtime);
        print_pq(queue, 201, last);

	min = top(queue, 201, &last);
        printf("\nTOP:%.2f", min->pqtime);
        print_pq(queue, 201, last);

	min = top(queue, 201, &last);
        printf("\nTOP:%.2f", min->pqtime);
        print_pq(queue, 201, last);

	min = top(queue, 201, &last);
        printf("\nTOP:%.2f", min->pqtime);
        print_pq(queue, 201, last);
	
        min = top(queue, 201, &last);
        printf("\nTOP:%.2f", min->pqtime);
        print_pq(queue, 201, last);

        min = top(queue, 201, &last);
        printf("\nTOP:%.2f", min->pqtime);
        print_pq(queue, 201, last);
	
	return 0;
}

void insert(customer** queue, float time, short type, int size, int* last){
	printf("INSERT\n");
	queue[++(*last)]->pqtime = time;
	if(type==0)queue[(*last)]->arrivalTime = time;
	if(type==0)queue[(*last)]->departureTime = time;
	percolateUp(queue, *last);
}

void percolateUp(customer** queue, int last){
	printf("PERC\n");
	customer* temp = queue[last];
	int cur = last;
	int par = cur/2;
	printf("OUTSIDE:%d, %d\n", cur, par);
	while(queue[cur]->pqtime <= queue[par]->pqtime){
		printf("WHILE:%d, %d, %.2f, %.2f\n", cur, par, queue[cur]->pqtime, queue[par]->pqtime);
		if(par!=0){
			temp = queue[par];
			queue[par] = queue[cur];
			queue[cur] = temp;
			cur = par;
			par = cur/2;
		}else break;
	}
}

void print_pq(customer** queue, int size, int last){
	printf("\nPRINT PRIORITY QUEUE\n");
	int i = 0;
	for(i = 0; i<last+1; i++){
			printf("\t%d  %.2f\n", i, queue[i]->pqtime);
	}
}

customer* top(customer** queue, int size, int* last){
	if(last==0)return queue[0];
	customer* result = queue[1];
	queue[1] = queue[(*last)--];
	print_pq(queue, size, *last);
	percolateDown(queue, *last);
	return result;
}

void percolateDown(customer** queue, int last){
	int cur = 1;
	int child = 2;
	customer* temp;
	while(child+1 <= last){
		if(queue[child]->pqtime < queue[child+1]->pqtime && queue[child]->pqtime < queue[cur]->pqtime){
			temp = queue[cur];
			queue[cur] = queue[child];
			queue[child] = temp;
			cur = child;
		}else if(queue[child]->pqtime >= queue[child+1]->pqtime && queue[child+1]->pqtime < queue[cur]->pqtime){
			temp = queue[cur];
                        queue[cur] = queue[child+1];
                        queue[child+1] = temp;
			cur = child + 1;
		}
		child = cur*2;
	}
}
