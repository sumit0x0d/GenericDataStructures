#ifndef HASH_TABLE_SEPARATE_CHAINING_H
#define HASH_TABLE_SEPARATE_CHAINING_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct HashTableSC {
    struct Pair* array;
    size_t key_size;
    size_t value_size;
    size_t bucket_count;
    size_t size;
    size_t (*hash)(void* key, size_t key_size, size_t bucket_count);
} HashTableSC;

HashTableSC* HashTableSC_create(size_t key_size, size_t value_size, size_t bucket_count,
    size_t (*hash)(void* key, size_t key_size, size_t bucket_count));
void HashTableSC_destroy(HashTableSC* HT);

bool HashTableSC_insert(HashTableSC* HT, void* key, void* value);
bool HashTableSC_remove(HashTableSC* HT, void* key);

void* HashTableSC_search(HashTableSC* HT, void* key);

#endif
