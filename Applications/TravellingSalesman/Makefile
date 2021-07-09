all: tsp clean

tsp: main.o brutus.o genetic.o grapher.o
	gcc main.o brutus.o genetic.o grapher.o -o tsp 

main.o: main.c
	gcc -c main.c

brutus.o: brutus.c
	gcc -c brutus.c

genetic.o: genetic.c
	gcc -c genetic.c

grapher.o: grapher.c
	gcc -c grapher.c

clean:
	rm *.o
