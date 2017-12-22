#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "hashTable.h"
#include "prime.h"

// Allocation
hashTableItem* allocateNewItem (const char* key, const char* value) {
	hashTableItem* newItem = malloc(sizeof(hashTableItem));
	newItem->key = strdup(key);
	newItem->value = strdup(value);
	//printf("===Item details===\n%s:%s\n\n", newItem->key, newItem->value);
	return newItem;
}

hashTable* allocateNewTable() {
	hashTable* myTable = malloc(sizeof(hashTable));
	myTable->size = HASHTABLESIZE;
	myTable->itemCount = 0;
	// A NULL entry in the bucket array indicates that it is empty
	myTable->items = calloc(HASHTABLESIZE, (sizeof(hashTableItem*)));;
	return myTable;
}

// Deleting
void deleteItem(hashTableItem* myItem) {
	// Note: strdup allocates new memory for those items and so needs to be freed
	free(myItem->key);
	free(myItem->value);
	free(myItem);
	return;
}

void deleteHashTable(hashTable* myTable) {
	int i;
	for(i = 0; i<HASHTABLESIZE; i++) {	// Delete all item objects
		hashTableItem* item = myTable->items[i];
		if(item != NULL) {
			deleteItem(item);
		}
	}
	free(myTable->items);	// Delete the array of pointers to items object
	free(myTable);	// Delete struct object
	return;
}

//------------------------------------------------------------------------


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

char* ht_search(hashTable* myHashtable, const char* key) {
	int index = getHash(key, myHashtable->size, 0);
	printf("index is: %d\n", index);
	hashTableItem* item = myHashtable->items[index];
	int i = 1;
	while (myHashtable->items[index] != NULL) {	// Keep searching until hit a NULL in which case its not there.
		if (strcmp(item->key, key) == 0) {
            return item->value;
        }
        index = getHash(key, myHashtable->size, i);
        item = myHashtable->items[index];
        i++;
	}
	return NULL;
}

// typedef struct {
// 	char* key;
// 	char* value;
// } hashTableItem;

// typedef struct {
// 	int size;
// 	int itemCount;
// 	hashTableItem** items;
// } hashTable;
