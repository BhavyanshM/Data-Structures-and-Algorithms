all: tsp clean

tsp: main.o brutus.o genetic.o grapher.o
	gcc main.o brutus.o genetic.o grapher.o -o tsp 

main.o: Main.c
	gcc -c Main.c

brutus.o: Brutus.c
	gcc -c Brutus.c

genetic.o: Genetic.c
	gcc -c Genetic.c

grapher.o: Grapher.c
	gcc -c Grapher.c

clean:
	rm *.o
