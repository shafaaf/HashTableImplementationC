#define HT_PRIME_1 89
#define HT_PRIME_2 97

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

int hashFunction(const char* s, const int a, const int m);
int getHash(const char* s, const int num_buckets, const int attempt);
hashTableItem* allocateNewItem (const char* key, const char* value);
hashTable* allocateNewTable();
void deleteItem(hashTableItem* myItem);
void deleteHashTable(hashTable* myTable);


//api calls
void print_ht(hashTable* myHashtable);
void ht_insert(hashTable* myHashtable, const char* key, const char* value);