#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "prime.h"

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
