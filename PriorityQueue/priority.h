void percolateUp(customer** queue, int last);
void insert(customer** queue, float time, short type, int size, int* last);
void print_pq(customer** queue, int size, int last);
customer* top(customer** queue, int size, int* last);
void percolateDown(customer** queue, int last);

