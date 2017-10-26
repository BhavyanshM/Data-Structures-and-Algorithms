#include <time.h>
#include <stdio.h>
#include <string.h>
#include "genetic.h"

void print_perm(int* s, int n);
long f(int n);
void init_gen(route** routes, int ntours, int n);
void create_gen(route** routes, route** newRoutes, int ntours, int n, int numMutants);
void selection_sort(route** routes, int ntours, int n);
void mutate(int* elite, int* mutant, int n);
void print_routes(route** routes, int ntours, int n);

int cnt = 1;


void init_gen(route** routes, int ntours, int n){
	int i = 0;
	for(i = 0; i<ntours; i++){
		routes[i] = (route*) malloc(sizeof(route));
		routes[i]->cost = 0.0;		
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
		routes[i]->path = (int*)malloc(n*sizeof(int));
		memcpy(routes[i]->path,s, n*sizeof(int));
        }

}

void create_gen(route** routes, route** newRoutes, int ntours, int n, int numMutants){
	int i = 0;
        for(i = 0; i<ntours; i++){
                newRoutes[i] = (route*) malloc(sizeof(route));
                newRoutes[i]->cost = 0.0;
        }
	
	//Copy the elite route structs into the newRoutes
	memcpy(newRoutes[0]->path, routes[0]->path, n*sizeof(int));
	memcpy(newRoutes[1]->path, routes[1]->path, n*sizeof(int));

	//Generate 'numMutants' mutations of the elite
	for(i = 2; i<2+numMutants; i++){
		if(i%2==0){
			
		}else{
			
		}
	}

	//Fill rest of newRoutes with fresh mutations of a mutation
	i = 0;
        int m,k,p,q;
        int temp = 0;
        long nfact = f(n);
        int* s = newRoutes[numMutants+1]->path;
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
                routes[i]->path = (int*)malloc(n*sizeof(int));
                memcpy(routes[i]->path,s, n*sizeof(int));
        }
}

void selection_sort(route** routes, int ntours, int n){
	int i = 0, j = 0;
	route* temp;
	for(i = 0; i<ntours-1; i++){
		for(j = 0; j<ntours-1; j++){
			if(routes[j]->cost > routes[j+1]->cost){
				temp = routes[j];
                		routes[j] = routes[j+1];
                		routes[j+1] = temp;
			}
		}
	}
}

void mutate(int* elite, int* mutant, int n){
	int i=0,j=0, temp;
	srand(time(NULL) * cnt++);
	i = abs(rand()) % (n/2);
	srand(rand()*time(NULL) * cnt++);
	j = n/2 + abs(rand()) % (n/2);
	// printf("%d, %d\n", i, j);

        //Copy the elite into the mutant
        memcpy(mutant, elite, n);

        //swap(i,j)
        temp = mutant[i];
        mutant[i] = mutant[j];
        mutant[j] = temp;


	

}

void print_routes(route** routes, int ntours, int n){
	int i = 0; 
	for(i = 0; i<ntours; i++){
		printf("%.2f\t", routes[i]->cost);
		print_perm(routes[i]->path, n);
	}
	printf("\n");
}
