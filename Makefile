CC=gcc

test:
	$(CC) -Wall  hashTable.c apiCalls.c prime.c main.c -o test

all: main.o apiCalls.o hashTable.o prime.o
	gcc -o myprogram main.o apiCalls.o hashTable.o prime.o

memoryTest: 
	valgrind --tool=memcheck ./myprogram

clean:
	rm -rf ./test
	rm -rf ./myprogram*
	rm -rf *.o

main.o: main.c hashTable.h
	gcc -c main.c

apiCalls.o: apiCalls.c
	gcc -c apiCalls.c

hashTable.o: hashTable.c hashTable.h
	gcc -c hashTable.c

prime.o: prime.c prime.h
	gcc -c prime.c
