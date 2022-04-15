#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct KeyValuePair KeyValuePair;
typedef struct HashTable HashTable;

HashTable* hash_table_separate_chaining_create(size_t key_size, size_t value_size, size_t buckets,
    size_t hash(void* key, size_t buckets), int (*compare)(void* key, void* pair_key));
void hash_table_separate_chaining_destroy(HashTable* HT);

size_t hash_table_separate_chaining_size(HashTable* HT);

void* hash_table_separate_chaining_search(HashTable* HT, void* key);

bool hash_table_separate_chaining_insert(HashTable* HT, void* key, void* value);
bool hash_table_separate_chaining_remove(HashTable* HT, void* key);

#endif
