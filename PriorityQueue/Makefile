all: tree clean

tree: model.o priority.o queue.o main.o 
	gcc model.o priority.o queue.o main.o -o tree -l m

model.o: model.c
	gcc -c model.c

priority.o: priority.c
	gcc -c priority.c

queue.o: queue.c
	gcc -c queue.c

main.o: main.c
	gcc -c main.c

clean:
	./tree
	rm tree *.o 
