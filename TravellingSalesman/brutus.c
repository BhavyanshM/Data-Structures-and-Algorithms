#include <stdio.h>
#include <stdlib.h>

const int rs = 20;
const int cs = 20;

long f(int n);
void perm(float adj[rs][cs], int* s, int n);
void print_perm(int* s, int n);
void init_perm(int* s, int n);
float travel(float adj[rs][cs], int* path, int n);

int count = 0;


// int main(){
// 	int n = 5;
// 	int s[n];
// 	init_perm(s,n);
// 	perm(s,n);
// 	return 0;
// }

void init_perm(int* s, int n){
	int i = 0;
        for(i = 0; i<n-1; i++){
		s[i] = i+1;
        }
}

void perm(float adj[rs][cs], int* s, int n){
	// printf("CALLED\n");
	int m,k,p,q,i;
	int temp = 0;
	long nfact = f(n);
	for(i = 0; i<nfact; i++){
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
		// printf("COST:%.2f\t", travel(adj, s, n));
		// print_perm(s,n);
		count++;
	}
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
