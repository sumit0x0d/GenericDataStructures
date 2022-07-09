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
    size_t (*hash)(void* key, size_t key_size, size_t bucket_count);
    int (*compare)(void* key1, void* key2);
};

HashTableOA* HashTableOA_create(size_t key_size, size_t value_size, size_t bucket_count,
    size_t (*hash)(void* key, size_t key_size, size_t bucket_count),
    int (*compare)(void* key1, void* key2))
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
    HT->hash = hash;
    HT->compare = compare;
    return HT;
}

void HashTableOA_destroy(HashTableOA* HT)
{
    free(HT->array);
    HT->array = NULL;
    free(HT);
    HT = NULL;
}

bool HashTableOA_empty(HashTableOA* HT)
{
    if(HT->size) {
        return false;
    }
    return true;
}

bool HashTableOA_full(HashTableOA* HT)
{
    if(HT->size != HT->bucket_count) {
        return false;
    }
    return true;
}

size_t HashTableOA_size(HashTableOA* HT)
{
    return HT->size;
}

static inline void* key_at(HashTableOA* HT, size_t index)
{
    return (char*)HT->array + ((HT->key_size + HT->value_size) * index);
}

static inline void* value_at(HashTableOA* HT, size_t index)
{
    return (char*)HT->array + ((HT->key_size + HT->value_size) * index) + HT->key_size;
}

void HashTableOA_insert(HashTableOA* HT, void* key, void* value)
{
    size_t index = HT->hash(key, HT->key_size, HT->bucket_count);
    while(*(size_t*)key_at(HT, index)) {
        index = (index + 1) % HT->bucket_count;
    }
    memcpy(key_at(HT, index), key, HT->key_size);
    memcpy(value_at(HT, index), value, HT->value_size);
}

void HashTableOA_remove(HashTableOA* HT, void* key)
{
    size_t index = HT->hash(key, HT->key_size, HT->bucket_count);
    while(*(size_t*)key_at(HT, index)) {
        int compare = HT->compare(key, key_at(HT, index));
        if(!compare) {
            memset(key_at(HT, index), 0, HT->key_size);
            break;
        }
        index = (index + 1) % HT->bucket_count;
    }
}

void* HashTableOA_search(HashTableOA* HT, void* key)
{
    size_t index = HT->hash(key, HT->key_size, HT->bucket_count);
    while(*(size_t*)key_at(HT, index)) {
        int compare = HT->compare(key, key_at(HT, index));
        if(!compare) {
            return key_at(HT, index);
        }
        index = (index + 1) % HT->bucket_count;
    }
    return NULL;
}
