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

HashTableOA* HashTableOACreate(size_t key_size, size_t value_size, size_t bucket_count,
    size_t (*hash_function)(void* key, size_t key_size, size_t bucket_count),
    int (*compare_function)(void* key1, void* key2))
{
    HashTableOA* HT = (HashTableOA*)malloc(sizeof (HashTableOA));
    if(!HT) {
        return NULL;
    }
    HT->array = (void*)calloc(bucket_count, (key_size + value_size));
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

void HashTableOADestroy(HashTableOA* HT)
{
    free(HT->array);
    HT->array = NULL;
    free(HT);
    HT = NULL;
}

size_t HashTableOASize(HashTableOA* HT)
{
    return HT->size;
}

bool HashTableOAEmpty(HashTableOA* HT)
{
    if(HT->size) {
        return false;
    }
    return true;
}

bool HashTableOAFull(HashTableOA* HT)
{
    if(HT->size != HT->bucket_count) {
        return false;
    }
    return true;
}

static inline void* KeyAt(HashTableOA* HT, size_t index)
{
    return (char*)HT->array + ((HT->key_size + HT->value_size) * index);
}

static inline void* ValueAt(HashTableOA* HT, size_t index)
{
    return (char*)HT->array + ((HT->key_size + HT->value_size) * index) + HT->key_size;
}

void* HashTableOASearch(HashTableOA* HT, void* key)
{
    size_t index = HT->hash_function(key, HT->key_size, HT->bucket_count);
    while(*(size_t*)KeyAt(HT, index)) {
        int compare_function = HT->compare_function(key, KeyAt(HT, index));
        if(!compare_function) {
            return KeyAt(HT, index);
        }
        index = (index + 1) % HT->bucket_count;
    }
    return NULL;
}

void HashTableOAInsert(HashTableOA* HT, void* key, void* value)
{
    size_t index = HT->hash_function(key, HT->key_size, HT->bucket_count);
    while(*(size_t*)KeyAt(HT, index)) {
        index = (index + 1) % HT->bucket_count;
    }
    memcpy(KeyAt(HT, index), key, HT->key_size);
    memcpy(ValueAt(HT, index), value, HT->value_size);
}

void HashTableOARemove(HashTableOA* HT, void* key)
{
    size_t index = HT->hash_function(key, HT->key_size, HT->bucket_count);
    while(*(size_t*)KeyAt(HT, index)) {
        int compare_function = HT->compare_function(key, KeyAt(HT, index));
        if(!compare_function) {
            memset(KeyAt(HT, index), 0, HT->key_size);
            break;
        }
        index = (index + 1) % HT->bucket_count;
    }
}
