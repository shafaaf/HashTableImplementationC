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
