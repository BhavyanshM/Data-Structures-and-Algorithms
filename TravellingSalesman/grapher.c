#include <stdio.h>
#include <stdlib.h>

int main(void){
	int i = 0;
	int N = 5;
	char string[10];
	FILE* fp = fopen("cityWeights.txt", "r");
	if(fp!=NULL){
		while(fscanf(fp, "%s\n", string)!=EOF){
			printf("%s\n", string);
		}
	}else{
		printf("The file was not found\n");
	}
	return 0;
}
