CC=gcc
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: main.o hashTable.o prime.o
	$(CC) -o myprogram main.o hashTable.o prime.o

test:
	$(CC) -Wall hashTable.c prime.c main.c -o test

memoryTest: 
	valgrind --tool=memcheck ./myprogram

.PHONY: run
run: 
	make all
	./myprogram

.PHONY: clean
clean:
	rm -rf ./test
	rm -rf ./myprogram*
	rm -rf *.o

main.o: main.c hashTable.h
	gcc -c main.c

hashTable.o: hashTable.c hashTable.h
	gcc -c hashTable.c

prime.o: prime.c prime.h
	gcc -c prime.c
