#include <stdlib.h>
#include <stdio.h>

#include "hashTable.h"

int main (void) {
	printf("Running main.\n");
	hashTable* myTable = allocateNewTable();
	// hashTableItem* myItem = allocateNewItem("1", "2");
	// deleteItem(myItem);
	// deleteHashTable(myTable);
	ht_insert(myTable, "keyx", "valuz");
   	return 0;
}
