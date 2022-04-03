#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct KeyValuePair {
    void *key;
    void *value;
    struct KeyValuePair *next;
} KeyValuePair;

typedef struct HashTable {
    KeyValuePair *array;
    size_t key_size;
    size_t value_size;
    size_t buckets;
    size_t size;
    size_t (*hash)(void *key);
} HashTable;

HashTable hash_table_separate_chaining_create(size_t key_size, size_t value_size, size_t buckets, size_t (*hash)(void *key, size_t buckets));
void hash_table_separate_chaining_destroy(HashTable *HT);

size_t hash_table_separate_chaining_size();

bool hash_table_separate_chaining_insert(HashTable *HT, void *key, void *value);
bool hash_table_separate_chaining_remove(HashTable *HT, void *key, void *value);

#endif
