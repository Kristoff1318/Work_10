main: main.o construction.o
	gcc -o main main.o construction.o

main.o: main.c construction.h
	gcc -c main.c

construction.o: construction.h
	gcc -c construction.c

run:
	./main
