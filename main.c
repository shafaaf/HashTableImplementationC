#include <stdlib.h>
#include <stdio.h>

#include "hashTable.h"

int main (void) {
	printf("Starting program.\n\n");
	hashTable* myTable = allocateNewTable();
	print_ht(myTable);
	ht_insert(myTable, "a BIG KEY", "a BIG VALUE");
	ht_insert(myTable, "12", "34");
	print_ht(myTable);


	char* searchedValue = ht_search(myTable, "a BIG KEY");
	printf("searchedValue is: %s\n", searchedValue);
	searchedValue = ht_search(myTable, "12");
	printf("searchedValue is: %s\n", searchedValue);
	
	deleteHashTable(myTable);
	return 0;
}
