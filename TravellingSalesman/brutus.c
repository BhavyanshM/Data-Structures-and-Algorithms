#include <stdio.h>
#include <stdlib.h>

long f(int n);
void perm(int* s, int n);
print_perm(int* s, int n);
void init_perm(int* s, int n);

int count = 0;

int main(){
	int n = 5;
	int s[n];
	init_perm(s,n);
	perm(s,n);
	return 0;
}

void init_perm(int* s, int n){
	int i = 0;
        for(i = 0; i<n; i++){
		s[i] = i;
        }
}

void perm(int* s, int n){
	int m,k,p,q,i;
	int temp = 0;
	long nfact = f(n);
	for(i = 0; i<nfact; i++){
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
		print_perm(s,n);
		count++;
	}
}

long f(int n){
	if(n<2)
		return 1;
	return f(n-1)*n;		
}

print_perm(int* s, int n){
	int i = 0;
	for(i = 0; i<n; i++){
		printf("%d ", s[i]);
	}
	printf("\n");
}
