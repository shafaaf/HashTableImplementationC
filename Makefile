CC=gcc

all:
	$(CC) -Wall  hashTable.c apiCalls.c main.c -o hashTable

clean:
	rm -rf hashTable