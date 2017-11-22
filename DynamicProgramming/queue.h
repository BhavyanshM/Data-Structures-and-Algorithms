typedef struct customer{
         float arrivalTime;
         float startOfService;
         float departureTime;
         float pqtime;
         struct customer* nextCust;
} customer;

void enqueue(customer** FIFO, customer* cust);
customer* dequeue(customer** FIFO);
void print_queue(customer* FIFO);

