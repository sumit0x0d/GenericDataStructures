#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct KeyValuePair {
    void *key;
    size_t key_size;
    void *value;
    size_t value_size;
} KeyValuePair;

typedef struct HashTable {
    KeyValuePair *array;
    size_t buckets;
    double load_factor;
    size_t size;
} HashTable;

HashTable hash_table_create(size_t buckets);
void hash_table_destroy(HashTable *HT);

size_t hash_table_size();

bool hash_table_insert(HashTable *HT, void *key, size_t key_size, void *value, size_t value_size);
bool hash_table_remove(HashTable *HT, void *key, size_t key_size, void *value, size_t value_size);

#endif
