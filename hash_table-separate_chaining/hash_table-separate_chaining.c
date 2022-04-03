#include "hash_table-separate_chaining.h"

HashTable hash_table_separate_chaining_create(size_t key_size, size_t value_size, size_t buckets, size_t (*hash)(void *key, size_t buckets));
void hash_table_separate_chaining_destroy(HashTable *HT);

bool hash_table_separate_chaining_insert(HashTable *HT, void *key, void *value);
bool hash_table_separate_chaining_remove(HashTable *HT, void *key, void *value);

HashTable hash_table_separate_chaining_create(size_t key_size, size_t value_size, size_t buckets, size_t (*hash)(void *key, size_t buckets))
{
    HashTable HT;

    HT.array = NULL;
    HT.key_size = key_size;
    HT.value_size = value_size;
    HT.buckets = buckets;
    HT.size = 0;

    HT.hash = hash;

    return HT;
}

void hash_table_separate_chaining_destroy(HashTable *HT)
{
    free(HT->array);
    HT->array = NULL;

    HT->size = 0;
}

bool hash_table_separate_chaining_insert(HashTable *HT, void *key, void *value)
{
    if(!HT->array) {
        if(!HT->key_size || !HT->value_size || !HT->buckets) return false;

        HT->array = calloc(HT->buckets, sizeof (KeyValuePair));
        if(!HT->array) return false;
    }

    KeyValuePair pair = {key, value, NULL};
    size_t index = hash_function(key, HT->buckets);

    memcpy(HT->array + index, &pair, sizeof (KeyValuePair));

    HT->size = HT->size + 1;

    return true;
}

// bool hash_table_separate_chaining_remove(HashTable *HT, void *key, void *value)
// {

// }
