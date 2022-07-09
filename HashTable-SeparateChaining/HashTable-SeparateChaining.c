#include "HashTable-SeparateChaining.h"
#include "Pair.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct HashTableSC {
    Pair* array;
    size_t key_size;
    size_t value_size;
    size_t bucket_count;
    size_t size;
    size_t (*hash)(void* key, size_t key_size, size_t bucket_count);
};

HashTableSC* HashTableSC_create(size_t key_size, size_t value_size, size_t bucket_count,
    size_t (*hash)(void* key, size_t key_size, size_t bucket_count))
{
    HashTableSC* HT = (HashTableSC*)malloc(sizeof (HashTableSC));
    if(!HT) {
        return NULL;
    }
    HT->array = (Pair*)malloc(sizeof (Pair) * bucket_count);
    if(!HT->array) {
        free(HT);
        return NULL;
    }
    HT->key_size = key_size;
    HT->value_size = value_size;
    HT->bucket_count = bucket_count;
    HT->size = 0;
    HT->hash = hash;
    return HT;
}

void HashTableSC_destroy(HashTableSC* HT)
{
    free(HT->array);
    HT->array = NULL;
    free(HT);
    HT = NULL;
}

bool HashTableSC_empty(HashTableSC* HT)
{
    if(HT->size) {
        return false;
    }
    return true;
}

size_t HashTableSC_size(HashTableSC* HT)
{
    return HT->size;
}


bool HashTableSC_insert(HashTableSC* HT, void* key, void* value)
{
    Pair* pair = Pair_create(HT->key_size, HT->value_size);
    if(!pair) {
        return false;
    }
    memcpy(pair->key, key, HT->key_size);
    memcpy(pair->value, value, HT->value_size);
    pair->next = NULL;
    size_t index = HT->hash(key, HT->key_size, HT->bucket_count);
    if(1) {
        Pair* pair_previous = HT->array + index;
        while(pair_previous->next) {
            pair_previous = pair_previous->next;
        }
        pair_previous->next = pair;
    }
    else {
        memcpy(HT->array + index, pair, sizeof (Pair));
    }
    HT->size = HT->size + 1;
    return true;
}

// int HashTableSC_remove(HashTableSC* HT, void* key)
// {
//     size_t index = HT->hash(key, HT->bucket_count);
// }

void* HashTableSC_search(HashTableSC* HT, void* key)
{
    size_t index = HT->hash(key, HT->key_size, HT->bucket_count);
    if(!HT->array[index].key) {
        return NULL;
    }
    return HT->array[index].value;
}
