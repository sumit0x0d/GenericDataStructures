#include "hash_table-separate_chaining.h"

struct HashTableSCPair {
    void* key;
    void* value;
    struct HashTableSCPair* next;
};

struct HashTableSC {
    HashTableSCPair* array;
    size_t key_size;
    size_t value_size;
    size_t buckets;
    size_t size;
    size_t (*hash)(void* key, size_t buckets);
    int (*compare)(void* key, void* node_key);
};

HashTableSC* hash_table_separate_chaining_create(size_t key_size, size_t value_size, size_t buckets,
    size_t hash(void* key, size_t buckets), int (*compare)(void* key, void* pair_key));
void hash_table_separate_chaining_destroy(HashTableSC* HT);

void* hash_table_separate_chaining_search(HashTableSC* HT, void* key);

bool hash_table_separate_chaining_insert(HashTableSC* HT, void* key, void* value);
bool hash_table_separate_chaining_remove(HashTableSC* HT, void* key);

HashTableSC* hash_table_separate_chaining_create(size_t key_size, size_t value_size, size_t buckets,
    size_t hash(void* key, size_t buckets), int (*compare)(void* key, void* pair_key))
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
    HT->compare = compare;
    return HT;
}

void hash_table_separate_chaining_destroy(HashTableSC* HT)
{
    free(HT->array);
    HT->array = NULL;
    free(HT);
    HT = NULL;
}

HashTableSCPair* pair_create(size_t key_size, size_t value_size)
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

bool hash_table_separate_chaining_insert(HashTableSC* HT, void* key, void* value)
{
    HashTableSCPair* pair = pair_create(HT->key_size, HT->value_size);
    if(!pair) {
        return false;
    }
    memcpy(pair->key, key, HT->key_size);
    memcpy(pair->value, value, HT->value_size);
    pair->next = NULL;
    size_t index = HT->hash(key, HT->buckets);
    if(HT->array + index) {
        HashTableSCPair* ptr = HT->array + index;
        while(ptr->next) {
            ptr = ptr->next;
        }
        ptr->next = pair;
    }
    else {
        memcpy(HT->array + index, pair, sizeof (HashTableSCPair));
    }
    HT->size = HT->size + 1;
    return true;
}

// bool hash_table_separate_chaining_remove(HashTableSC* HT, void* key, void* value)
// {

// }

void* hash_table_separate_chaining_search(HashTableSC* HT, void* key)
{
    size_t index = HT->hash(key, HT->buckets);
    if(!HT->array[index].key) {
        return NULL;
    }
    return HT->array[index].value;
}
