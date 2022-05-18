#include "HashTable-OpenAddressing.h"

HashTableOA* HashTableOA_create(size_t key_size, size_t value_size, size_t buckets,
    size_t (*hash)(void* key, size_t buckets));
void HashTableOA_destroy(HashTableOA* HT);

void HashTableOA_insert(HashTableOA* HT, void* key, void* value);
void HashTableOA_remove(HashTableOA* HT, void* key);

void* HashTableOA_search(HashTableOA* HT, void* key);

HashTableOA* HashTableOA_create(size_t key_size, size_t value_size, size_t buckets,
    size_t (*hash)(void* key, size_t buckets))
{
    HashTableOA* HT = malloc(sizeof (HashTableOA));
    if(!HT) {
        return NULL;
    }
    HT->array = calloc(buckets, key_size + value_size);
    if(!HT->array) {
        free(HT);
        HT = NULL;
        return NULL;
    }
    HT->key_size = key_size;
    HT->value_size = value_size;
    HT->buckets = buckets;
    HT->size = 0;
    HT->hash = hash;
    return HT;
}

// void HashTableOA_destroy(HashTableOA* HT)
// {

// }

static void* HashTableOA_at(HashTableOA* HT, size_t index)
{
    return (char*)HT->array + ((HT->key_size + HT->value_size) * index);
}

void HashTableOA_insert(HashTableOA* HT, void* key, void* value)
{
    size_t index = HT->hash(key, HT->buckets);
    while(*(size_t*)HashTableOA_at(HT, index)) {
        index = (index + 1) % HT->buckets;
    }
    memcpy(HashTableOA_at(HT, index), key, HT->key_size);
    memcpy((char*)HashTableOA_at(HT, index) + HT->key_size, value, HT->value_size);
}

// int HashTableOA_remove(HashTableOA* HT, void* data)
// {

// }

// void* HashTableOA_search(HashTableOA* HT, void* key)
// {

// }
