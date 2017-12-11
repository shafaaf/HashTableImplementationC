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

void ht_insert(hashTable* myHashtable, const char* key, const char* value) {
	int index = getHash(key, HASHTABLESIZE, 0);
	printf("ht_insert: index is: %d for pair: %s: %s\n", index, key, value);
	printf("myHashtable->items: %p\n", *(myHashtable->items));
	if (myHashtable->items[index] == NULL) {
		printf("Index %d is fine.\n", index);
	}
	return;
}
