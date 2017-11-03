#include <stdio.h>
#include <stdlib.h>
#include "brutus.h"
#include "grapher.h"
#include "genetic.h"
#include <time.h>

const int nR = 20;
const int nC = 20;


int main(){

	clock_t start, end;
    double cpu_time_used;

	int n = 0;
	printf("Please enter the number of Cities for this Travelling Salesman Problem solver:");
	scanf("%d", &n);
	n--;

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
	percentMutations %= 101;

	// printf("Permuting ...\n");
	//Perform Brute Force algorithm
	start = clock();
	float bruteForceCost = perm(graph, s,n);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\nTime Taken by Brute Force: %.2lf s\n\n", cpu_time_used);
	// print(graph);

	// printf("REACHED\n");
	start = clock();

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

	// printf("GENERATION : 1\n\n");
	// print_routes(routes, ntours, n);

	// print_routes(routes, ntours, n);
	int optimus[n];
	float minCost = 1000000.0;
	int i = 0, j=0;
	for(i = 0; i<ngen-1; i++){
		// printf("GENERATION : %d\n\n", i+2);
		if(i%2==0){						
			create_gen(routes, newRoutes, ntours, n, numMutants);
			for(k = 0; k<ntours; k++){
				newRoutes[k]->cost = travel(graph, newRoutes[k]->path, n);
			}
			selection_sort(newRoutes, ntours, n);
			// print_routes(newRoutes, ntours, n);
			if(i==ngen-2){
				minCost = routes[0]->cost;
				for(j = 0; j<n; j++){
					optimus[j] = newRoutes[0]->path[j];
				}
			}
		}
		if(i%2==1){			
			create_gen(newRoutes, routes, ntours, n, numMutants);
			for(k = 0; k<ntours; k++){
				routes[k]->cost = travel(graph, routes[k]->path, n);
			}
			selection_sort(routes, ntours, n);
			// print_routes(routes, ntours, n);
			if(i==ngen-2){
				minCost = routes[0]->cost;
				for(j = 0; j<n; j++){
					optimus[j] = routes[0]->path[j];
				}
			}
		}
	}
	
	

	printf("(Genetic Algo)\tOPTIMAL COST:%.2f\t", minCost);
	print_perm(optimus,n);

	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\nTime Taken by Genetic Algorithm: %.2lf s\n\n", cpu_time_used);

	printf("Genetic Algorithm was %.2f percent of optimal.\n", minCost/bruteForceCost * 100);

	// print_routes(routes, ntours, n);
	return 0;
}
