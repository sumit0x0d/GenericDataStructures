#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct HashTableSCPair HashTableSCPair;
typedef struct HashTableSC HashTableSC;

HashTableSC* hash_table_separate_chaining_create(size_t key_size, size_t value_size, size_t buckets,
    size_t hash(void* key, size_t buckets), int (*compare)(void* key, void* pair_key));
void hash_table_separate_chaining_destroy(HashTableSC* HT);

size_t hash_table_separate_chaining_size(HashTableSC* HT);

bool hash_table_separate_chaining_insert(HashTableSC* HT, void* key, void* value);
bool hash_table_separate_chaining_remove(HashTableSC* HT, void* key);

void* hash_table_separate_chaining_search(HashTableSC* HT, void* key);

#endif
