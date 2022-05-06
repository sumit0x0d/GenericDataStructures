#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct HashTableSCPair {
    void* key;
    void* value;
    struct HashTableSCPair* next;
} HashTableSCPair;

typedef struct HashTableSC {
    HashTableSCPair* array;
    size_t key_size;
    size_t value_size;
    size_t buckets;
    size_t size;
    size_t (*hash)(void* key, size_t buckets);
    int (*compare)(void* key, void* node_key);
} HashTableSC;

HashTableSC* HashTableSC_create(size_t key_size, size_t value_size, size_t buckets,
    size_t (*hash)(void* key, size_t buckets), int (*compare)(void* key1, void* key2));
void HashTableSC_destroy(HashTableSC* HT);

bool HashTableSC_insert(HashTableSC* HT, void* key, void* value);
bool HashTableSC_remove(HashTableSC* HT, void* key);

void* HashTableSC_search(HashTableSC* HT, void* key);

#endif
