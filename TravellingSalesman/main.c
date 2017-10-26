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

	int percentMutations = 0;
	printf("Please enter the perentage of Mutations to be generated (0-100):");
	scanf("%d", &percentMutations);

	//Perform Brute Force algorithm
	perm(graph, s,n);
	print(graph);

	// printf("REACHED\n");
	route* routes[ntours]; 
	route* newRoutes[ntours];
	init_gen(routes, ntours, n);

	//Find the Cost for all the paths in the Generation
	int k = 0;
	for(k = 0; k<ntours; k++){
		routes[k]->cost = travel(graph, routes[k]->path, n);
	}

	// print_routes(routes, ntours, n);
	selection_sort(routes, ntours, n);


	int numMutants = percentMutations*ntours/100;
	// printf("Total Mutations:%d\n", numMutants);

	printf("GENERATION : 1\n\n");
	print_routes(routes, ntours, n);

	// print_routes(routes, ntours, n);
	int i = 0;
	for(i = 0; i<ngen-1; i++){
		printf("GENERATION : %d\n\n", i+2);
		if(i%2==0){						
			create_gen(routes, newRoutes, ntours, n, numMutants);
			for(k = 0; k<ntours; k++){
				newRoutes[k]->cost = travel(graph, newRoutes[k]->path, n);
			}
			selection_sort(newRoutes, ntours, n);
			print_routes(newRoutes, ntours, n);
		}
		if(i%2==1){			
			create_gen(newRoutes, routes, ntours, n, numMutants);
			for(k = 0; k<ntours; k++){
				routes[k]->cost = travel(graph, routes[k]->path, n);
			}
			selection_sort(routes, ntours, n);
			print_routes(routes, ntours, n);
		}
	}
	

	// print_routes(routes, ntours, n);
	return 0;
}
