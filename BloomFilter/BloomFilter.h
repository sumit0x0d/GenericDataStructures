#ifndef BLOOM_FILTER_H
#define BLOOM_FILTER_H

#include <stdbool.h>
#include <stddef.h>

typedef struct BloomFilter BloomFilter;

BloomFilter* BloomFilter_create(size_t data_size, size_t bucket_count,
    size_t (*hash)(void* data, size_t data_size, size_t bucket_count));
void BloomFilter_destroy(BloomFilter* BF);
bool BloomFilter_search(BloomFilter* BF, void* data);
void BloomFilter_insert(BloomFilter* BF, void* data);

#endif
