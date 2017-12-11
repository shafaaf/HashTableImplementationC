#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "hashTable.h"

// // Item in hash table
// typedef struct {
// 	char* key;
// 	char* value;
// } hashTableItem;

// // Hashtable itself
// typedef struct {
// 	int size;
// 	int itemCount;
// 	hashTableItem** items;
// } hashTable;

void print_ht(hashTable* myHashtable) {
	printf("===Printing hash table detailis===\n");
	printf("size is: %d\n", myHashtable->size);
	printf("itemCount is: %d\n\n", myHashtable->itemCount);
	int i;
	for (i=0;i<HASHTABLESIZE;i++) {
		// Info
		hashTableItem* item = myHashtable->items[i];
		printf("item at index: %d has address: %p and points to: %p\n", i, (myHashtable->items) + i, myHashtable->items[i]);
		if (item == NULL) {
			printf("item doenst exist\n\n");
		}
	}
	return;
}


void ht_insert(hashTable* myHashtable, const char* key, const char* value) {
	hashTableItem* newItem = allocateNewItem(key, value);
	int index = getHash(key, HASHTABLESIZE, 0);

	printf("ht_insert: index is: %d for pair: %s: %s\n", index, key, value);
	if (myHashtable->items[index] == NULL) {
		printf("Inserting into index: %d\n", index);
		myHashtable->items[index] = newItem;
	}
	return;
}
