#include <stdio.h>
#include <stdlib.h>
#include "brutus.h"
#include "grapher.h"
#include "genetic.h"

const int nR = 5;
const int nC = 5;


int main(){
	int n = 5;
	int s[n];
	init_perm(s,n);


	float graph[nR][nC];
	readFile(graph);
	print(graph);

	perm(graph, s,n);
	
	int ntours = 10;

	route* routes[ntours]; 
	init_gen(routes, ntours, n);

	return 0;
}
