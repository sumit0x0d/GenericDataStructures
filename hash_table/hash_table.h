#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "hash_functions.h"

struct HashTable {
    void *array;
    size_t data_type_size;
    size_t size;
    size_t capacity;
};

void hash_table_print(struct HashTable *hash_table);
struct HashTable *hash_table_construct();
void hash_table_insert(struct HashTable *hash_table, void *data, size_t data_type_size);
void hash_table_remove(struct HashTable *hash_table);

void hash_table_print(struct HashTable *hash_table)
{
    printf("Hash-Table: ");
    size_t i = 0;
    while(i < hash_table->capacity-1) {
        printf("%d ", hash_table->array[i]);
        i++;
    }
    printf("%d\n", hash_table->array[hash_table->capacity-1]);
    printf("Hash-Table Size: %zu\n", hash_table->size);
    printf("Hash-Table Capacity: %zu\n", hash_table->capacity);
}

struct HashTable *hash_table_construct(size_t capacity)
{
    struct HashTable *hash_table = malloc(sizeof (struct HashTable));
    assert(hash_table);
    hash_table->array = malloc(sizeof (int) * capacity);
    hash_table->size = 0;
    hash_table->capacity = capacity;
    return hash_table;
}

void hash_table_insert(struct HashTable *hash_table, int data)
{
    hash_mod(hash_table->capacity, data);
    if(!hash_table->array[mod])
    hash_table->array[mod] = data;
    ++hash_table->size;
}

void hash_table_remove(struct HashTable *hash_table)
{

}

#endif
