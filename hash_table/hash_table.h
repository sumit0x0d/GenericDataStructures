#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "hash_functions.h"

struct HashTable {
    void *array;
    size_t data_type_size;
    size_t size;
    size_t capacity;
};

void hash_table_print(struct HashTable *HT);
struct HashTable *ht_construct();
void hash_table_insert(struct HashTable *HT, void *data, size_t data_type_size);
void hash_table_remove(struct HashTable *HT);

void hash_table_print(struct HashTable *HT)
{
    printf("Hash-Table: ");
    size_t i = 0;
    while(i < HT->capacity-1) {
        printf("%d ", HT->array[i]);
        i++;
    }
    printf("%d\n", HT->array[HT->capacity-1]);
    printf("Hash-Table Size: %zu\n", HT->size);
    printf("Hash-Table Capacity: %zu\n", HT->capacity);
}

struct HashTable *ht_construct(size_t capacity)
{
    struct HashTable *HT = malloc(sizeof (struct HashTable));
    assert(HT);
    HT->array = malloc(sizeof (int) * capacity);
    HT->size = 0;
    HT->capacity = capacity;
    
    return HT;
}

void hash_table_insert(struct HashTable *HT, int data)
{
    hash_mod(HT->capacity, data);
    if(!HT->array[mod])
    HT->array[mod] = data;
    ++HT->size;
}

void hash_table_remove(struct HashTable *HT)
{

}

#endif
