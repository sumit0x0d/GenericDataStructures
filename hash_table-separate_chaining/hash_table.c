#include "hash_table.h"

HashTable hash_table_create(size_t key_size, size_t value_size, size_t buckets);
void hash_table_destroy(HashTable *HT);

bool hash_table_insert(HashTable *HT, void *key, void *value);
bool hash_table_remove(HashTable *HT, void *key, void *value);

HashTable hash_table_create(size_t key_size, size_t value_size, size_t buckets)
{
    HashTable HT;

    HT.array = NULL;
    HT.key_size = key_size;
    HT.value_size = value_size;
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

size_t hash_function(void *key, size_t key_size, size_t buckets)
{
    size_t index;

    memcpy(&index, key, key_size);

    return (index % buckets);
}

bool hash_table_insert(HashTable *HT, void *key, void *value)
{
    KeyValuePair pair = {key, value};
    size_t index = hash_function(key, HT->key_size, HT->buckets);

    memcpy((char *)HT->array + index, &pair, sizeof (KeyValuePair));
}

bool hash_table_remove(HashTable *HT, void *key, void *value)
{

}
