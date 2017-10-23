#include <stdio.h>
#include <stdlib.h>
#include "brutus.h"
#include "grapher.h"

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


	return 0;
}
