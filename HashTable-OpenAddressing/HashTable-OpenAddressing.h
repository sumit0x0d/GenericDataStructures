#ifndef HASH_TABLE_OPEN_ADDRESSING_H
#define HASH_TABLE_OPEN_ADDRESSING_H

#include <stdbool.h>
#include "stddef.h"

typedef struct HashTableOA HashTableOA;

HashTableOA* HashTableOA_create(size_t key_size, size_t value_size, size_t bucket_count,
    size_t (*hash)(void* key, size_t key_size, size_t bucket_count),
    int (*compare)(void* key1, void* key2));
void HashTableOA_destroy(HashTableOA* HT);
bool HashTableOA_empty(HashTableOA* HT);
bool HashTableOA_full(HashTableOA* HT);
size_t HashTableOA_size(HashTableOA* HT);

void HashTableOA_insert(HashTableOA* HT, void* key, void* value);
void HashTableOA_remove(HashTableOA* HT, void* key);

void* HashTableOA_search(HashTableOA* HT, void* key);

#endif
