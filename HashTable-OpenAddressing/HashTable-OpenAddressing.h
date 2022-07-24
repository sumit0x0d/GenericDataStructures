#ifndef HASH_TABLE_OPEN_ADDRESSING_H
#define HASH_TABLE_OPEN_ADDRESSING_H

#include <stdbool.h>
#include "stddef.h"

typedef struct HashTableOA HashTableOA;

HashTableOA* HashTableOA_Create(size_t key_size, size_t value_size, size_t bucket_count,
    size_t (*hash)(void* key, size_t key_size, size_t bucket_count),
    int (*compare)(void* key1, void* key2));
void HashTableOA_Destroy(HashTableOA* HT);
size_t HashTableOA_Size(HashTableOA* HT);
bool HashTableOA_Empty(HashTableOA* HT);
bool HashTableOA_Full(HashTableOA* HT);
void* HashTableOA_Search(HashTableOA* HT, void* key);
void HashTableOA_Insert(HashTableOA* HT, void* key, void* value);
void HashTableOA_Remove(HashTableOA* HT, void* key);

#endif
