#include <stdio.h>
#include <stdlib.h>
#include "brutus.h"
#include "grapher.h"
#include "genetic.h"

const int nR = 20;
const int nC = 20;


int main(){
	int n = 0;
	printf("Please enter the number of Cities for this Travelling Salesman Problem solver:");
	scanf("%d", &n);

	int s[n];
	init_perm(s,n);


	float graph[nR][nC];
	readFile(graph);
	// print(graph);
	
	int ntours = 0;
	printf("Please enter the number of Tours Per Generation for the Genetic Algorithm:");
	scanf("%d", &ntours);

	int ngen = 0;
	printf("Please enter the number of Generations for the Genetic Algorithm:");
	scanf("%d", &ngen);

	//Perform Brute Force algorithm
	perm(graph, s,n);

	// printf("REACHED\n");
	route* routes[ntours]; 
	init_gen(routes, ntours, n);

	print_routes(routes, ntours, n);
	int k = 0;

	//Find the Cost for all the paths in the Generation
	for(k = 0; k<ntours; k++){
		routes[k]->cost = travel(graph, routes[k]->path, n);
	}

	print_routes(routes, ntours, n);

	selection_sort(routes, ntours, n);

	print_routes(routes, ntours, n);
	return 0;
}
