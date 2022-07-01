#ifndef HASH_TABLE_OPEN_ADDRESSING_H
#define HASH_TABLE_OPEN_ADDRESSING_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct HashTableOA {
    void* array;
    size_t key_size;
    size_t value_size;
    size_t bucket_count;
    size_t size;
    size_t (*hash)(void* key, size_t key_size, size_t bucket_count);
    int (*compare)(void* key1, void* key2);
} HashTableOA;

HashTableOA* HashTableOA_create(size_t key_size, size_t value_size, size_t bucket_count,
    size_t (*hash)(void* key, size_t key_size, size_t bucket_count),
    int (*compare)(void* key1, void* key2));
void HashTableOA_destroy(HashTableOA* HT);

void HashTableOA_insert(HashTableOA* HT, void* key, void* value);
void HashTableOA_remove(HashTableOA* HT, void* key);

void* HashTableOA_search(HashTableOA* HT, void* key);

#endif
