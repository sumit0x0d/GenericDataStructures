#ifndef BLOOM_FILTER_H
#define BLOOM_FILTER_H

#include <stdlib.h>
#include <string.h>

typedef struct BloomFilter {
    char* array;
    size_t data_size;
    size_t buckets;
    size_t size;
    int (*hash)(void* data, size_t capacity);
} BloomFilter;

BloomFilter* BloomFilter_create(size_t data_size, size_t buckets,
    int (*hash)(void* data, size_t buckets));

int BloomFilter_search(BloomFilter* BF, void* data);

void BloomFilter_insert(BloomFilter* BF, void* data);

#endif
