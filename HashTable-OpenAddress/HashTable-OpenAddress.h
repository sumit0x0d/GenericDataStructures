#ifndef HASH_TABLE_OPEN_ADDRESS_H
#define HASH_TABLE_OPEN_ADDRESS_H

#include <stdlib.h>
#include <string.h>

typedef struct HashTableOA {
    void* array;
    size_t data_size;
    size_t capacity;
    size_t size;
} HashTableOA;

HashTableOA* HashTableOA_create(size_t data_size);

int HashTableOA_insert(HashTableOA* HT, void* key, void* value);
int HashTableOA_remove(HashTableOA* HT, void* key);

int HashTableOA_remove(HashTableOA* HT, void* key);

#endif
