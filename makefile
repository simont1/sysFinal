all: main.o pets.o
	gcc main.o pets.o

main.o: main.c pets.h
	gcc -c main.c

clas.o: pets.c pets.h
	gcc -c pets.c
