#include <stdlib.h>
#include <stdio.h>

#include "hashTable.h"

int main (void) {
	hashTable* myTable = allocateNewTable();
	print_ht(myTable);
	ht_insert(myTable, "a BIG KEY", "a BIG VALUE");
	print_ht(myTable);
	// deleteHashTable(myTable);
	return 0;
}
