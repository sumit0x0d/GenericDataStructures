#ifndef HASH_TABLE_OPEN_ADDRESSING_H
#define HASH_TABLE_OPEN_ADDRESSING_H

#include <stdlib.h>
#include <string.h>

typedef struct HashTableOA {
    void* array;
    size_t key_size;
    size_t value_size;
    size_t buckets;
    size_t size;
    size_t (*hash)(void* key, size_t buckets);
} HashTableOA;

HashTableOA* HashTableOA_create(size_t key_size, size_t value_size, size_t buckets,
    size_t (*hash)(void* key, size_t buckets));
void HashTableOA_destroy(HashTableOA* HT);

int HashTableOA_insert(HashTableOA* HT, void* key, void* value);
int HashTableOA_remove(HashTableOA* HT, void* key);

void* HashTableOA_search(HashTableOA* HT, void* key);

#endif
