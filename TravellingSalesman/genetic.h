#include <stdio.h>
#include <stdlib.h>

typedef struct route{
        float cost;
        int* path;
} route;


void init_gen(route** routes, int ntours, int n);
void create_gen(route** routes, route** newRoutes, int ntours, int n, int numMutants);
void selection_sort(route** routes, int ntours, int n);
void mutate(int* elite, int* mutant, int n);
void print_routes(route** routes, int ntours, int n);

