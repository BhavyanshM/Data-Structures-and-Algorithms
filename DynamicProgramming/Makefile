all: dp clean

dp: lcs.o similarity.o main.o 
	gcc lcs.o similarity.o main.o -o dp -l m

lcs.o: lcs.c
	gcc -c lcs.c

similarity.o: similarity.c
	gcc -c similarity.c

main.o: main.c
	gcc -c main.c

clean:
	rm *.o 
