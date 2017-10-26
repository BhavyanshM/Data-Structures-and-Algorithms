#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int i = 0;
	srand(time(NULL));
	for(i = 0; i<380; i++){
		printf("%.1f\n", ((float)(abs(rand())%500)/(float)10));
	}
	return 0;
}
