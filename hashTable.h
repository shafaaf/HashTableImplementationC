#define HASHTABLESIZE 53

// Item in hash table
typedef struct {
	char* key;
	char* value;
} hashTableItem;

// Hashtable itself
typedef struct {
	int size;
	int itemCount;
	hashTableItem** items;
} hashTable;

hashTableItem* allocateNewItem (const char* key, const char* value);
hashTable* allocateNewTable();
void deleteItem(hashTableItem* myItem);
void deleteHashTable(hashTable* myTable);

//Api calls
void print_ht(hashTable* myHashtable);
void ht_insert(hashTable* myHashtable, const char* key, const char* value);
