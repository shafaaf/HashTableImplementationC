// Item in hash table
typedef struct {
	char* key;
	char* value;
} hashTableItem;

typedef struct {
	int size;
	int itemCount;
	hashTableItem** items;
} hashTable;
