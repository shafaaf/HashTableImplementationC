#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "hashTable.h"

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

// typedef struct {
// 	char* key;
// 	char* value;
// } hashTableItem;

// typedef struct {
// 	int size;
// 	int itemCount;
// 	hashTableItem** items;
// } hashTable;
