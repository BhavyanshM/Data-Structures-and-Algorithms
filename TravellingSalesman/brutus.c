#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int rs = 20;
const int cs = 20;

long f(int n);
void perm(float adj[rs][cs], int* s, int n);
void print_perm(int* s, int n);
void init_perm(int* s, int n);
float travel(float adj[rs][cs], int* path, int n);

long count = 0;


// int main(){
// 	int n = 5;
// 	int s[n];
// 	init_perm(s,n);
// 	perm(s,n);
// 	return 0;
// }

void init_perm(int* s, int n){
	int i = 0;
        for(i = 0; i<n; i++){
		s[i] = i+1;
        }
}

void perm(float adj[rs][cs], int* s, int n){
	// printf("CALLED\n");
	int m,k,p,q,i,j;
	int temp = 0;
	float minCost = 1000000.0;
	float cost = 1000000.0;
	int optimus[n];
	long nfact = f(n);
	// printf("perm(%d)\n", n);
	// print_perm(s,n);
	for(i = 0; i<nfact-1; i++){
		// printf("%ld\n", nfact/100);
		// printf("PERM:%d/%ld\n", i,nfact);
		m = n - 2;
		while(s[m]>s[m+1]){
			m = m-1;
		}
		k = n-1;
		while(s[m]>s[k]){
			k=k-1;
		}
		//swap(m,k)
		temp = s[m];
		s[m] = s[k];
		s[k] = temp;
		p = m + 1;
		q = n-1;
		while(p<q){
			//swap(p,q)
			temp = s[p];
			s[p] = s[q];
			s[q] = temp;
			p++;q--;
		}
		// printf("Copying !\n");
		cost = travel(adj, s, n);
		if(cost<minCost){
			minCost = cost;
			for(j = 0; j<n; j++){
				optimus[j] = s[j];
			}
			// printf("Copying !\n");
			// memcpy(optimus, s, n*sizeof(int));
		}
		// print_perm(s,n);
		// printf("COST:%.2f\t", travel(adj, s, n));
		
		count++;
	}
	printf("\nCOST:%.2f\t", minCost);
	print_perm(optimus,n);
}

long f(int n){
	// printf("REACHED:fact(%d)\n", n);
	long result = 1;
	int i = 0;
	for(i = 1; i<=n; i++){
		result *= i;
	}
	return result;		
}

void print_perm(int* s, int n){
	int i = 0;
	printf("%d ", 0);
	for(i = 0; i<n; i++){
		printf("%d ", s[i]);
	}
	printf("%d ", 0);
	printf("\n");
}
