all: tree clean

tree: model.o sim.o main.o
	gcc -o tree model.o sim.o main.o
model.o: model.c
	gcc -c model.c

sim.o: sim.c
	gcc -c sim.c

main.o: main.c
	gcc -c main.c

clean:
	./tree
	rm tree *.o 
