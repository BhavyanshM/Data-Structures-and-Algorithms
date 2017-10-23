#include "genetic.h"
// #include "brutus.h"

void init_route(int* path, int n);
void init_gen(route** routes, int ntours, int n);
void create_gen(route** routes, int ntours, int n);
void selection_sort(route** routes, int ntours, int n);
void mutate(int* path, int n);

void init_route(int* path, int n){
	int i = 0;
	path = (int*)malloc(n*sizeof(int));
    for(i = 0; i<n; i++){
		path[i] = 0;
    }
}

void init_gen(route** routes, int ntours, int n){
	int i = 0;
	for(i = 0; i<ntours; i++){		
		init_route(routes[i]->path, n);
	}
}

void create_gen(route** routes, int ntours, int n){

}

void selection_sort(route** routes, int ntours, int n){

}

void mutate(int* path, int n){

}