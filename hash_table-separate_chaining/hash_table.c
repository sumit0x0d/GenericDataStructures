#include "hash_table.h"

HashTable hash_table_create(size_t capacity);
void hash_table_destroy(HashTable *HT);

bool hash_table_insert(HashTable *HT, void *key, size_t key_size, void *value, size_t value_size);
bool hash_table_remove(HashTable *HT, void *key, size_t key_size, void *value, size_t value_size);

HashTable hash_table_create(size_t buckets)
{
    HashTable HT;

    HT.array = NULL;
    HT.buckets = buckets;
    HT.load_factor = 0;
    HT.size = 0;

    return HT;
}

void hash_table_destroy(HashTable *HT)
{
    free(HT->array);
    HT->array = NULL;

    HT->size = 0;
}

size_t hash_function(size_t buckets, void *key, size_t key_size)
{
    size_t *index;

    memcpy(index, key, key_size);

    return (*index % buckets);
}

bool hash_table_insert(HashTable *HT, void *key, size_t key_size, void *value, size_t value_size)
{
    size_t index = hash_function(HT->buckets, key, key_size);

    HT->array[index],;
}

bool hash_table_remove(HashTable *HT, void *key, size_t key_size, void *value, size_t value_size)
{

}
