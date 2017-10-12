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
void insert(customer** queue, customer* event, float time, short type, int size, int* last);
void print_pq(customer** queue, int size, int last);
customer* top(customer** queue, int size, int* last);
void percolateDown(customer** queue, int size);
void init_pq(customer** queue, int start, int size);

void init_pq(customer** queue, int start, int size){
        int i = start;
        for(i = start; i<size; i++){
                queue[i] = (customer*)malloc(sizeof(customer));
                queue[i]->arrivalTime = -1;
                queue[i]->startOfService = -1;
                queue[i]->departureTime = -1;
                queue[i]->pqtime = -1;
                queue[i]->nextCust = NULL;
        }
}

void print_e(customer* event){
	printf("\tp=%.2f\t", event->pqtime);
	printf("\tat=%.2f\t", event->arrivalTime);
	printf("\tsos=%.2f\t", event->startOfService);
	printf("\tdt=%.2f\n", event->departureTime);
}

/*
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
*/
void insert(customer** queue, customer* event, float time, short type, int size, int* last){
	// printf("INSERT\n");
	
	if(*last<size){
		if(type==0){
			queue[++(*last)]->pqtime = time;
			queue[(*last)]->arrivalTime = time;
            queue[(*last)]->startOfService = -1;
            queue[(*last)]->departureTime = -1;
		}
		if(type==1){
			queue[++(*last)]->arrivalTime = event->arrivalTime;
			queue[(*last)]->pqtime = event->departureTime;
			queue[(*last)]->departureTime = event->departureTime;
			queue[(*last)]->startOfService = event->startOfService;
		}	
		percolateUp(queue, *last);
	}
	else return;
}

void percolateUp(customer** queue, int last){
	// printf("PERC\n");
	customer* temp = queue[last];
	int cur = last;
	int par = cur/2;
	// printf("OUTSIDE:%d, %d\n", cur, par);
	while(queue[cur]->pqtime <= queue[par]->pqtime){
		// printf("WHILE:%d, %d, %.2f, %.2f\n", cur, par, queue[cur]->pqtime, queue[par]->pqtime);
		if(par!=0){
			// printf("Swapping:%.2f, %.2f\n", queue[par]->pqtime, queue[cur]->pqtime);
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
	for(i = 1; i<last+1; i++){
			printf("\t%d  p=%.2f\t", i, queue[i]->pqtime);
			printf("\tat=%.2f\t", queue[i]->arrivalTime);
			printf("\tsos=%.2f\t", queue[i]->startOfService);
			printf("\tdt=%.2f\n", queue[i]->departureTime);

	}
}

customer* top(customer** queue, int size, int* last){
	if(last==0)return queue[0];
	customer* result = queue[1];
	queue[1] = queue[(*last)--];
	percolateDown(queue, *last);
	print_pq(queue, size, *last);
	return result;
}

void percolateDown(customer** queue, int last){
	int cur = 1;
	int child = 2;
	customer* temp;
	while(child+1 <= last){
		// printf("SLIDING:%d, %d\n", cur, child);
		// print_e(queue[cur]);
		// print_e(queue[child]);
		// print_e(queue[child+1]);
		if(queue[child]->pqtime < queue[child+1]->pqtime && queue[child]->pqtime < queue[cur]->pqtime){
			// printf("FIRST\n");
			// printf("Down, Swapping:%.2f, %.2f\n", queue[child]->pqtime, queue[cur]->pqtime);

			temp = queue[cur];
			queue[cur] = queue[child];
			queue[child] = temp;
			cur = child;
		}else if(queue[child]->pqtime >= queue[child+1]->pqtime && queue[child+1]->pqtime < queue[cur]->pqtime){
			// printf("SECOND\n");
			// printf("Down, Swapping:%.2f, %.2f\n", queue[child+1]->pqtime, queue[cur]->pqtime);

			temp = queue[cur];
            queue[cur] = queue[child+1];
            queue[child+1] = temp;
			cur = child + 1;
		}else if(queue[child+1]->pqtime >= queue[cur]->pqtime && queue[child]->pqtime >= queue[cur]->pqtime){
		// }else{
			// printf("THIRD\n");
			return;
		}
		child = cur*2;
	}
}
