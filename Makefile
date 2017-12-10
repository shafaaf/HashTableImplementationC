CC=gcc

all:
	$(CC) -Wall  hashTable.c main.c -o hashTable

clean:
	rm -rf hashTable