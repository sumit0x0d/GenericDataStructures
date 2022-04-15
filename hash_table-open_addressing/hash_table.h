#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct HashTable {
    void* array;
    size_t data_size;
    size_t size;
    size_t capacity;
} HashTable;

HashTable hash_table_create(size_t data_size);
bool hash_table_insert(HashTable* HT, void* data);
bool hash_table_remove(HashTable* HT, void* data);

#endif
