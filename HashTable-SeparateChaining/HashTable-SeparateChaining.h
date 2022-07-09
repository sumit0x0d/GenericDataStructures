#ifndef HASH_TABLE_SEPARATE_CHAINING_H
#define HASH_TABLE_SEPARATE_CHAINING_H

#include <stdbool.h>
#include <stddef.h>

typedef struct HashTableSC HashTableSC;

HashTableSC* HashTableSC_create(size_t key_size, size_t value_size, size_t bucket_count,
    size_t (*hash)(void* key, size_t key_size, size_t bucket_count));
void HashTableSC_destroy(HashTableSC* HT);
size_t HashTableSC_size(HashTableSC* HT);
bool HashTableSC_empty(HashTableSC* HT);
void* HashTableSC_search(HashTableSC* HT, void* key);
bool HashTableSC_insert(HashTableSC* HT, void* key, void* value);
bool HashTableSC_remove(HashTableSC* HT, void* key);

#endif
