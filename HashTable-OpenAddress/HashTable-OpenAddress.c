#include "HashTable-OpenAddress.h"

HashTableOA* HashTableOA_create(size_t data_size);

int HashTableOA_insert(HashTableOA* HT, void* key, void* value);
int HashTableOA_remove(HashTableOA* HT, void* data);

HashTableOA* HashTableOA_create(size_t data_size)
{
    HashTableOA* HT = malloc(sizeof (HashTableOA));
    if(!HT) {
        return NULL;
    }
    return HT;
}

int HashTableOA_insert(HashTableOA* HT, void* key, void* value)
{

}

int HashTableOA_remove(HashTableOA* HT, void* data)
{

}
