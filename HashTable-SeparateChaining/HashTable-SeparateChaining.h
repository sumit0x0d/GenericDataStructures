#ifndef HASH_TABLE_SEPARATE_CHAINING_H
#define HASH_TABLE_SEPARATE_CHAINING_H

#include <stdbool.h>
#include <stddef.h>

typedef struct HashTableSC HashTableSC;

HashTableSC* HashTableSC_Create(size_t key_size, size_t value_size, size_t bucket_count,
    size_t (*hash_function)(void* key, size_t key_size, size_t bucket_count));
void HashTableSC_Destroy(HashTableSC* HT);
size_t HashTableSC_Size(HashTableSC* HT);
bool HashTableSC_Empty(HashTableSC* HT);
void* HashTableSC_Search(HashTableSC* HT, void* key);
bool HashTableSC_Insert(HashTableSC* HT, void* key, void* value);
bool HashTableSC_Remove(HashTableSC* HT, void* key);

#endif
