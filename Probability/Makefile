all: prob clean

prob: main.o analytic.o monteCarlo.o
	gcc main.o analytic.o monteCarlo.o -o prob 

main.o: main.c
	gcc -c main.c

analytic.o: analytic.c
	gcc -c analytic.c

monteCarlo.o: monteCarlo.c
	gcc -c monteCarlo.c

clean:
	rm *.o
