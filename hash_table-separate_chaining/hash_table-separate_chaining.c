#include "hash_table-separate_chaining.h"

typedef struct KeyValuePair {
    void *key;
    void *value;
    struct KeyValuePair *left;
    struct KeyValuePair *right;
    struct KeyValuePair *parent;
    enum {RED, BLACK} color;
} KeyValuePair;

typedef struct HashTable {
    KeyValuePair *array;
    size_t key_size;
    size_t value_size;
    size_t buckets;
    size_t size;
    size_t (*hash)(void *key, size_t buckets);
    int (*compare)(void *key, void *node_key);
} HashTable;

HashTable *hash_table_separate_chaining_create(size_t key_size, size_t value_size, size_t buckets,
    size_t hash(void *key, size_t buckets), int (*compare)(void *key, void *pair_key));
void hash_table_separate_chaining_destroy(HashTable *HT);

void *hash_table_separate_chaining_search(HashTable *HT, void *key);

bool hash_table_separate_chaining_insert(HashTable *HT, void *key, void *value);
bool hash_table_separate_chaining_remove(HashTable *HT, void *key);

HashTable *hash_table_separate_chaining_create(size_t key_size, size_t value_size, size_t buckets,
    size_t hash(void *key, size_t buckets), int (*compare)(void *key, void *pair_key))
{
    HashTable *HT = malloc(sizeof (HashTable));
    if(!HT)
        return NULL;

    HT->array = NULL;
    HT->key_size = key_size;
    HT->value_size = value_size;
    HT->buckets = buckets;
    HT->size = 0;

    HT->hash = hash;
    HT->compare = compare;

    return HT;
}

void hash_table_separate_chaining_destroy(HashTable *HT)
{
    free(HT->array);
    HT->array = NULL;

    HT->size = 0;
}

void *hash_table_separate_chaining_search(HashTable *HT, void *key)
{
    size_t index = HT->hash(key, HT->buckets);
    if(!HT->array[index].key)
        return NULL;

    return HT->array[index].value;
}

bool hash_table_separate_chaining_insert(HashTable *HT, void *key, void *value)
{
    if(!HT->array) {
        if(!HT->key_size || !HT->value_size || !HT->buckets)
        return false;

        HT->array = calloc(HT->buckets, sizeof (KeyValuePair));
        if(!HT->array)
        return false;
    }

    KeyValuePair pair = {key, value, NULL, NULL, NULL, RED};
    size_t index = HT->hash(key, HT->buckets);

    memcpy(HT->array + index, &pair, sizeof (KeyValuePair));

    HT->size = HT->size + 1;

    return true;
}

// bool hash_table_separate_chaining_remove(HashTable *HT, void *key, void *value)
// {

// }
