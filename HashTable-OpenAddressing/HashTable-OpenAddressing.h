#ifndef HASH_TABLE_OPEN_ADDRESSING_H
#define HASH_TABLE_OPEN_ADDRESSING_H

#include <stdbool.h>
#include "stddef.h"

typedef struct HashTableOA HashTableOA;

HashTableOA* HashTableOACreate(size_t key_size, size_t value_size, size_t bucket_count,
    size_t (*hash_function)(void* key, size_t key_size, size_t bucket_count),
    int (*compare_function)(void* key1, void* key2));
void HashTableOADestroy(HashTableOA* HT);
size_t HashTableOASize(HashTableOA* HT);
bool HashTableOAEmpty(HashTableOA* HT);
bool HashTableOAFull(HashTableOA* HT);
void* HashTableOASearch(HashTableOA* HT, void* key);
void HashTableOAInsert(HashTableOA* HT, void* key, void* value);
void HashTableOARemove(HashTableOA* HT, void* key);

#endif
