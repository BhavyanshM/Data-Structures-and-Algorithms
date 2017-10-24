#include "genetic.h"
// #include "brutus.h"

void init_route(int* path, int n);
void init_gen(route** routes, int ntours, int n);
void create_gen(route** routes, int ntours, int n);
void selection_sort(route** routes, int ntours, int n);
void mutate(int* path, int n);
void init_gen(route** routes, int ntours, int n);
void print_perm(int* s, int n);


void init_route(int* path, int n){
	int i = 0;
	path = (int*)malloc(n*sizeof(int));
	for(i = 0; i<n; i++){
		path[i] = 0;
	}
}

void copy_route(int* orig, int* copy, int n){
	int i = 0; 
	for(i = 0; i<n; i++){
		copy[i] = orig[i];
	}
}

void init_gen(route** routes, int ntours, int n){
	int i = 0;
	for(i = 0; i<ntours; i++){
		routes[i]->cost = 0.0;		
		init_route(routes[i]->path, n);
	}
	i = 0;
        int m,k,p,q;
        int temp = 0;
        long nfact = f(n);
	int s[n];
	for(i = 0; i<n; i++){
		s[i] = i;
	}
        for(i = 0; i<ntours; i++){
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
		copy_route(s, routes[i]->path, n);
        }

}

void create_gen(route** routes, int ntours, int n){

}

void selection_sort(route** routes, int ntours, int n){

}

void mutate(int* path, int n){

}

void print_routes(route** routes, int ntours, int n){
	int i = 0; 
	for(i = 0; i<ntours; i++){
		print_perm(routes[i]->path, n);
	}
	printf("\n");
}
