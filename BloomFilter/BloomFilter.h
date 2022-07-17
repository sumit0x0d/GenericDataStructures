#ifndef BLOOM_FILTER_H
#define BLOOM_FILTER_H

#include <stdbool.h>
#include <stddef.h>

typedef struct BloomFilter BloomFilter;

BloomFilter* BloomFilterCreate(size_t data_size, size_t bucket_count,
    size_t (*hash_function)(void* data, size_t data_size, size_t bucket_count));
void BloomFilterDestroy(BloomFilter* BF);
bool BloomFilterSearch(BloomFilter* BF, void* data);
void BloomFilterInsert(BloomFilter* BF, void* data);

#endif
