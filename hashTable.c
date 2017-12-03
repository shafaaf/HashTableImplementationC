#include <stdio.h>
#include "hashTable.h"

// Allocation
static hashTableItem* allocateNewItem (const char* key, const char* value) {
	hashTableItem* newItem = malloc(sizeof(hashTableItem));
	newItem->key = strdup(key);
	newItem->value = strdup(value);
	printf("===Item details===\n%s:%s\n", key, value);
	return newItem;
}

hashTable* allocateNewTable() {
	hashTable* myTable = malloc(sizeof(hashTable));
	myTable->size = 53;
	myTable->itemCount = 0;
	// A NULL entry in the bucket array indicates that it is empty
	myTable->items = (hashTableItem*) calloc(53, (sizeof(hashTableItem*)));;
	return myTable;
}

// Deleting
void deleteItem(hashTableItem* myItem) {
	// strdup allocates new memory for those items and so needs to be freed
	free(myItem->key);
	free(myItem->value);
	free(myItem);
	return;
}

void deleteHashTable(hashTable* myTable) {
	int i;
	for(i = 0; i<53; i++) {	// Delete all item objects
		deleteItem(myTable->items[i]);
	}
	free(myTable->items);	// Delete the array of pointers to items object
	free(myTable);	// Delete struct object
	return;
}

int main (void) {
   hashTableItem* myItem = allocateNewItem("1", "2");
   hashTable* myTable = allocateNewTable();
   return 0;
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
