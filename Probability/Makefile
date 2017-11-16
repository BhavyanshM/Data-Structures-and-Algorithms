all: prob clean

prob: main.o analytic.o monteCarlo.o generate.o
	gcc main.o analytic.o monteCarlo.o generate.o -o prob -lm

main.o: main.c
	gcc -c main.c

analytic.o: analytic.c
	gcc -c analytic.c

monteCarlo.o: monteCarlo.c
	gcc -c monteCarlo.c

generate.o: generate.c
	gcc -c generate.c

clean:
	rm *.o
