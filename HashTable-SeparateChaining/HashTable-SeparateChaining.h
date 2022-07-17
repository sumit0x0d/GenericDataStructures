#ifndef HASH_TABLE_SEPARATE_CHAINING_H
#define HASH_TABLE_SEPARATE_CHAINING_H

#include <stdbool.h>
#include <stddef.h>

typedef struct HashTableSC HashTableSC;

HashTableSC* HashTableSCCreate(size_t key_size, size_t value_size, size_t bucket_count,
    size_t (*hash_function)(void* key, size_t key_size, size_t bucket_count));
void HashTableSCDestroy(HashTableSC* HT);
size_t HashTableSCSize(HashTableSC* HT);
bool HashTableSCEmpty(HashTableSC* HT);
void* HashTableSCSearch(HashTableSC* HT, void* key);
bool HashTableSCInsert(HashTableSC* HT, void* key, void* value);
bool HashTableSCRemove(HashTableSC* HT, void* key);

#endif
