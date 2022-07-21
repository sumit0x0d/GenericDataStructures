#include "HashTable-OpenAddressing.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct HashTableOA {
    void* array;
    size_t key_size;
    size_t value_size;
    size_t bucket_count;
    size_t size;
    size_t (*hash_function)(void* key, size_t key_size, size_t bucket_count);
    int (*compare_function)(void* key1, void* key2);
};

HashTableOA* HashTableOA_Create(size_t key_size, size_t value_size, size_t bucket_count,
    size_t (*hash_function)(void* key, size_t key_size, size_t bucket_count),
    int (*compare_function)(void* key1, void* key2))
{
    HashTableOA* HT = (HashTableOA*)malloc(sizeof (HashTableOA));
    if(!HT) {
        return NULL;
    }
    HT->array = calloc(bucket_count, (key_size + value_size));
    if(!HT->array) {
        free(HT);
        return NULL;
    }
    HT->key_size = key_size;
    HT->value_size = value_size;
    HT->bucket_count = bucket_count;
    HT->size = 0;
    HT->hash_function = hash_function;
    HT->compare_function = compare_function;
    return HT;
}

void HashTableOA_Destroy(HashTableOA* HT)
{
    free(HT->array);
    HT->array = NULL;
    free(HT);
    HT = NULL;
}

size_t HashTableOA_Size(HashTableOA* HT)
{
    return HT->size;
}

bool HashTableOA_Empty(HashTableOA* HT)
{
    if(HT->size) {
        return false;
    }
    return true;
}

bool HashTableOA_Full(HashTableOA* HT)
{
    if(HT->size != HT->bucket_count) {
        return false;
    }
    return true;
}

static inline void* Key_At(HashTableOA* HT, size_t index)
{
    return (char*)HT->array + ((HT->key_size + HT->value_size) * index);
}

static inline void* Value_At(HashTableOA* HT, size_t index)
{
    return (char*)HT->array + ((HT->key_size + HT->value_size) * index) + HT->key_size;
}

void* HashTableOA_Search(HashTableOA* HT, void* key)
{
    size_t index = HT->hash_function(key, HT->key_size, HT->bucket_count);
    while(*(size_t*)Key_At(HT, index)) {
        int compare_function = HT->compare_function(key, Key_At(HT, index));
        if(!compare_function) {
            return Key_At(HT, index);
        }
        index = (index + 1) % HT->bucket_count;
    }
    return NULL;
}

void HashTableOA_Insert(HashTableOA* HT, void* key, void* value)
{
    size_t index = HT->hash_function(key, HT->key_size, HT->bucket_count);
    while(*(size_t*)Key_At(HT, index)) {
        index = (index + 1) % HT->bucket_count;
    }
    memcpy(Key_At(HT, index), key, HT->key_size);
    memcpy(Value_At(HT, index), value, HT->value_size);
}

void HashTableOA_Remove(HashTableOA* HT, void* key)
{
    size_t index = HT->hash_function(key, HT->key_size, HT->bucket_count);
    while(*(size_t*)Key_At(HT, index)) {
        int compare_function = HT->compare_function(key, Key_At(HT, index));
        if(!compare_function) {
            memset(Key_At(HT, index), 0, HT->key_size);
            break;
        }
        index = (index + 1) % HT->bucket_count;
    }
}
