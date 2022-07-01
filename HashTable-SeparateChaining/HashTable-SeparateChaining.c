#include "HashTable-SeparateChaining.h"

typedef struct Pair {
    void* key;
    void* value;
    struct Pair* next;
} Pair;

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

Pair* pair_create(size_t key_size, size_t value_size)
{
    Pair* pair = (Pair*)malloc(sizeof (Pair));
    if(!pair) {
        return NULL;
    }
    pair->key = malloc(key_size);
    if(!pair->key) {
        free(pair);
        return NULL;
    }
    pair->value = malloc(value_size);
    if(!pair->value) {
        free(pair->key);
        free(pair);
        return NULL;
    }
    return pair;
}

void pair_destroy(Pair *pair)
{
    free(pair->key);
    pair->key = NULL;
    free(pair->value);
    pair->value = NULL;
    free(pair);
    pair = NULL;
}

bool HashTableSC_insert(HashTableSC* HT, void* key, void* value)
{
    Pair* pair = pair_create(HT->key_size, HT->value_size);
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
