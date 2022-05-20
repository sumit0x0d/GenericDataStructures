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
    HT->array = malloc(buckets * sizeof (HashTableOAPair*));
    if(!HT->array) {
        free(HT);
        HT = NULL;
        return NULL;
    }
    for(size_t i = 0; i < buckets; i++) {
        HT->array[i] = malloc(sizeof (HashTableOAPair));
        if(!HT->array[i]) {
            for(size_t j = 0; j < i; j++) {
                free(HT->array[j]);
                HT->array[j] = NULL;
            }
            free(HT->array);
            HT->array = NULL;
            free(HT);
            HT = NULL;
            return NULL;
        }
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

// static void* HashTableOA_at(HashTableOA* HT, size_t index)
// {
//     return (char*)HT->array + ((HT->key_size + HT->value_size) * index);
// }

void HashTableOA_insert(HashTableOA* HT, void* key, void* value)
{
    size_t index = HT->hash(key, HT->buckets);
    // while(*(size_t*)HashTableOA_at(HT, index)) {
    //     index = (index + 1) % HT->buckets;
    // }
    while(HT->array[index]->key) {
        index = index + 1;
    }
    memcpy(HT->array[index]->key, key, HT->key_size);
    memcpy(HT->array[index]->value, value, HT->value_size);
    // memcpy(HashTableOA_at(HT, index), key, HT->key_size);
    // memcpy((char*)HashTableOA_at(HT, index) + HT->key_size, value, HT->value_size);
}

// int HashTableOA_remove(HashTableOA* HT, void* data)
// {

// }

// void* HashTableOA_search(HashTableOA* HT, void* key)
// {

// }
