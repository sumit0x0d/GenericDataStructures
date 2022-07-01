#ifndef BLOOM_FILTER_H
#define BLOOM_FILTER_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct BloomFilter {
    char* array;
    size_t data_size;
    size_t bucket_count;
    size_t size;
    size_t (*hash)(void* data, size_t data_size, size_t bucket_count);
} BloomFilter;

BloomFilter* BloomFilter_create(size_t data_size, size_t bucket_count,
    size_t (*hash)(void* data, size_t data_size, size_t bucket_count));
void BloomFilter_destroy(BloomFilter* BF);

bool BloomFilter_search(BloomFilter* BF, void* data);

void BloomFilter_insert(BloomFilter* BF, void* data);

#endif
