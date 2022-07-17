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
    size_t (*hash_function)(void* key, size_t key_size, size_t bucket_count);
};

HashTableSC* HashTableSCCreate(size_t key_size, size_t value_size, size_t bucket_count,
    size_t (*hash_function)(void* key, size_t key_size, size_t bucket_count))
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
    HT->hash_function = hash_function;
    return HT;
}

void HashTableSCDestroy(HashTableSC* HT)
{
    free(HT->array);
    HT->array = NULL;
    free(HT);
    HT = NULL;
}

size_t HashTableSCSize(HashTableSC* HT)
{
    return HT->size;
}

bool HashTableSCEmpty(HashTableSC* HT)
{
    if(HT->size) {
        return false;
    }
    return true;
}

void* HashTableSCSearch(HashTableSC* HT, void* key)
{
    size_t index = HT->hash_function(key, HT->key_size, HT->bucket_count);
    if(!HT->array[index].key) {
        return NULL;
    }
    return HT->array[index].value;
}

bool HashTableSCInsert(HashTableSC* HT, void* key, void* value)
{
    Pair* pair = PairCreate(HT->key_size, HT->value_size);
    if(!pair) {
        return false;
    }
    memcpy(pair->key, key, HT->key_size);
    memcpy(pair->value, value, HT->value_size);
    pair->next = NULL;
    size_t index = HT->hash_function(key, HT->key_size, HT->bucket_count);
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

// int HashTableSCRemove(HashTableSC* HT, void* key)
// {
//     size_t index = HT->hash_function(key, HT->bucket_count);
// }
