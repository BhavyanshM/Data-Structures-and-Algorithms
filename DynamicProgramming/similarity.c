#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lcs.h"

#define NL 1
#define OFFSET 2

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

void getString(int n, char* name, int* starts, char* str){
	FILE* msfp = fopen(name , "r");
	// char str[2000];
	fseek(msfp, starts[n]  + OFFSET, SEEK_SET);
	fscanf(msfp, "%s\n", str);
	// printf("%s\n", str);
	fclose(msfp);
}

void display(int n, FILE* fp, int* starts){
	int i = 1, j = 1, len = 0;
	char X[2000],Y[2000];
	for(i = 1; i<=n; i++){
		for(j = 1; j<=i; j++){
			printf("- ");
		}

		for(j = i+1; j<=n; j++){
			getString(i-1, "multipleSequences.txt", starts, X);
			getString(j-1, "multipleSequences.txt", starts, Y);
			// printf("%s , %s\n", X, Y);
			len = opt_lcs(X,Y);
			printf("%c ", sim(len, strlen(X) , strlen(Y)));
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
		s[i] = s[i-1] + size + NL;
		printf("%d ", size);
	}
	printf("\n");
	print(s, n);
}

