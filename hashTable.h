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
