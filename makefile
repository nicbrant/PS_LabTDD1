all: programa

programa: main.o listas.o
	gcc main.o listas.o -o main

main.o: main.c
	gcc -c main.c

listas.o: listas.c
	gcc -c listas.c

clean:
	rm *o main
