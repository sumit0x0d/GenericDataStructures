#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "hash_functions.h"

struct HashTable {
    void *array;
    size_t data_type_size;
    size_t size;
    size_t capacity;
};

void hash_table_print(struct HashTable *ht);
struct HashTable *ht_construct();
void hash_table_insert(struct HashTable *ht, void *data, size_t data_type_size);
void hash_table_remove(struct HashTable *ht);

void hash_table_print(struct HashTable *ht)
{
    printf("Hash-Table: ");
    size_t i = 0;
    while(i < ht->capacity-1) {
        printf("%d ", ht->array[i]);
        i++;
    }
    printf("%d\n", ht->array[ht->capacity-1]);
    printf("Hash-Table Size: %zu\n", ht->size);
    printf("Hash-Table Capacity: %zu\n", ht->capacity);
}

struct HashTable *ht_construct(size_t capacity)
{
    struct HashTable *ht = malloc(sizeof (struct HashTable));
    assert(ht);
    ht->array = malloc(sizeof (int) * capacity);
    ht->size = 0;
    ht->capacity = capacity;
    return ht;
}

void hash_table_insert(struct HashTable *ht, int data)
{
    hash_mod(ht->capacity, data);
    if(!ht->array[mod])
    ht->array[mod] = data;
    ++ht->size;
}

void hash_table_remove(struct HashTable *ht)
{

}

#endif
