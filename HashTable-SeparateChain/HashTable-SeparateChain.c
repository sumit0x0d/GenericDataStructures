#include "HashTable-SeparateChain.h"

HashTableSC* HashTableSC_create(size_t key_size, size_t value_size, size_t buckets,
    size_t (*hash)(void* key, size_t buckets));
void HashTableSC_destroy(HashTableSC* HT);

HashTableSCPair* HashTableSCPair_create(size_t key_size, size_t value_size);
void HashTableSCPair_destroy(HashTableSCPair *pair);

int HashTableSC_insert(HashTableSC* HT, void* key, void* value);
int HashTableSC_remove(HashTableSC* HT, void* key);

void* HashTableSC_search(HashTableSC* HT, void* key);

HashTableSC* HashTableSC_create(size_t key_size, size_t value_size, size_t buckets,
    size_t (*hash)(void* key, size_t buckets))
{
    HashTableSC* HT = malloc(sizeof (HashTableSC));
    if(!HT) {
        return NULL;
    }
    HT->array = malloc(sizeof (HashTableSCPair) * buckets);
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

void HashTableSC_destroy(HashTableSC* HT)
{
    free(HT->array);
    HT->array = NULL;
    free(HT);
    HT = NULL;
}

HashTableSCPair* HashTableSCPair_create(size_t key_size, size_t value_size)
{
    HashTableSCPair* pair = malloc(sizeof (HashTableSCPair));
    if(!pair) {
        return NULL;
    }
    pair->key = malloc(key_size);
    if(!pair->key) {
        free(pair);
        pair = NULL;
        return NULL;
    }
    pair->value = malloc(value_size);
    if(!pair->value) {
        free(pair);
        pair = NULL;
        free(pair->key);
        pair->key = NULL;
        return NULL;
    }
    return pair;
}

void HashTableSCPair_destroy(HashTableSCPair *pair)
{
    free(pair->key);
    pair->key = NULL;
    free(pair->value);
    pair->value = NULL;
    free(pair);
    pair = NULL;
}

int HashTableSC_insert(HashTableSC* HT, void* key, void* value)
{
    HashTableSCPair* pair = HashTableSCPair_create(HT->key_size, HT->value_size);
    if(!pair) {
        return 0;
    }
    memcpy(pair->key, key, HT->key_size);
    memcpy(pair->value, value, HT->value_size);
    pair->next = NULL;
    size_t index = HT->hash(key, HT->buckets);
    if(&HT->array[index]) {
        HashTableSCPair* pointer = &HT->array[index];
        while(pointer->next) {
            pointer = pointer->next;
        }
        pointer->next = pair;
    }
    else {
        memcpy(&HT->array[index], pair, sizeof (HashTableSCPair));
    }
    HT->size = HT->size + 1;
    return 1;
}

// int HashTableSC_remove(HashTableSC* HT, void* key)
// {
//     size_t index = HT->hash(key, HT->buckets);
// }

void* HashTableSC_search(HashTableSC* HT, void* key)
{
    size_t index = HT->hash(key, HT->buckets);
    if(!HT->array[index].key) {
        return NULL;
    }
    return HT->array[index].value;
}
