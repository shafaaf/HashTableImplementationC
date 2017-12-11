#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "hashTable.h"

#define HASHTABLESIZE 53

int hashFunction(const char* s, const int a, const int m) {
    long hash = 0;
    const int len_s = strlen(s);
    for (int i = 0; i < len_s; i++) {
        hash += (long)pow(a, len_s - (i+1)) * s[i];
        hash = hash % m;
    }
    return (int)hash;
}

int getHash(const char* s, const int num_buckets, const int attempt) {
    const int hash_a = hashFunction(s, HT_PRIME_1, num_buckets);
    const int hash_b = hashFunction(s, HT_PRIME_2, num_buckets);
    return (hash_a + (attempt * (hash_b + 1))) % num_buckets;
}

// Allocation
hashTableItem* allocateNewItem (const char* key, const char* value) {
	printf("Allocating new item.\n");
	hashTableItem* newItem = malloc(sizeof(hashTableItem));
	newItem->key = strdup(key);
	newItem->value = strdup(value);
	printf("===Item details===\n%s:%s\n\n", newItem->key, newItem->value);
	return newItem;
}

hashTable* allocateNewTable() {
	printf("Allocating new hash table.\n");
	hashTable* myTable = malloc(sizeof(hashTable));
	myTable->size = HASHTABLESIZE;
	myTable->itemCount = 0;
	// A NULL entry in the bucket array indicates that it is empty
	myTable->items = calloc(HASHTABLESIZE, (sizeof(hashTableItem*)));;
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
