main: main.o max.o
	gcc -g -o main.exe main.o max.o
main.o: main.c max.h
	gcc -g -c main.c
max.o: max.c max.h
	gcc -g -c max.c