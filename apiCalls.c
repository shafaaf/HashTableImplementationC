#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "hashTable.h"
#include "prime.h"

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
	printf("\n===Printing hash table detailis===\n");
	printf("size is: %d\n", myHashtable->size);
	printf("itemCount is: %d\n", myHashtable->itemCount);
	int i;
	for (i=0;i<HASHTABLESIZE;i++) {
		// Info
		hashTableItem* item = myHashtable->items[i];
		printf("item at index: %d has address: %p and points to: %p\n", i, (myHashtable->items) + i, myHashtable->items[i]);
		if (item != NULL) {
			printf("item is: %s : %s\n\n", item->key, item->value);
		}
	}
	printf("\n");
	return;
}


void ht_insert(hashTable* myHashtable, const char* key, const char* value) {
	hashTableItem* newItem = allocateNewItem(key, value);
	int index = getHash(newItem->key, myHashtable->size, 0);
	hashTableItem* currentItem = myHashtable->items[index];
	int i = 1;
	while (currentItem != NULL) { // Can insert here
		printf("Collision at index: %d", index);
		index = getHash(newItem->key, myHashtable->size, i);
        currentItem = myHashtable->items[index];
        i++;
	}
	printf("ht_insert: inserting at index: %d for pair: %s: %s\n", index, key, value);
	myHashtable->items[index] = newItem;
	myHashtable->itemCount++;
	return;
}
