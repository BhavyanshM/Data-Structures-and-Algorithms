#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char sim(int lcs, int a, int b){
	if(a>=b){
		int temp = a;
		a = b;
		b = temp;
	}
	if(a>=90*b/100 && lcs>=80*a/100){
		return 'H';	
	}else if(a>=80*b/100 && lcs>=60*a/100){
		return 'M';
	}else if(a>=40*b/100 && lcs>=50*a/100){
		return 'L';
	}
	else return 'D';
	return '\0';
}

void display(int n, FILE* fp){
	int i = 1, j = 1;
	for(i = 1; i<=n; i++){
		for(j = 1; j<=i; j++){
			printf("  ");
		}

		for(j = i+1; j<=n; j++){
			printf("%c ", sim(i, (i+j)/2 ,j));
		}
		printf("\n");
	}
}

void print(int* a, int n){
        int i = 0;
        for(i = 0; i<n; i++)
        printf("%d ", a[i]);
        printf("\n");
}


void startings(int n, FILE* fp, int* s){
	int i = 0;
	for(i = 0; i<n; i++)s[i] = 0;
	char str[2000];
	int size = 0;
	for(i = 1; i<=n; i++){
		fscanf(fp, "%s\n", str);
	        int size = strlen(str);
		s[i] = s[i-1] + size + 2*(i-1);
		printf("%d ", size);
	}
	printf("\n");
	print(s, n);
}
