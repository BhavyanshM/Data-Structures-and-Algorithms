#include <stdio.h>
#include <stdlib.h>

const int R = 5;
const int C = 5;

void readFile(float adj[R][C]);
void print(float adj[R][C]);


int main(void){
	float graph[R][C];
	readFile(graph);
	print(graph);
	return 0;
}

void readFile(float adj[R][C]){
	int i = 0;
	int j = 0;
	int N = 5;
	char string[10];
	FILE* fp = fopen("cityWeights.txt", "r");
	if(fp!=NULL){
		for(i = 0; i<R; i++){
			for(j = 0; j<C; j++){
				fscanf(fp, "%s\n", string);
				// printf("%s\n", string);
				adj[i][j] = atof(string);
			}
		}
	}else{
		printf("The file was not found\n");
	}
}

void print(float adj[R][C]){
	int i = 0;
	int j = 0;
	printf("\n");
	for(i = 0; i<R; i++){
		printf("\t");
		for(j = 0; j<C; j++){
			printf("%.2f\t", adj[i][j]);
		}
		printf("\n\n\n");
	}
}
