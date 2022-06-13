#include "BloomFilter.h"

BloomFilter* BloomFilter_create(size_t data_size, size_t buckets,
    int (*hash)(void* data, size_t buckets))
{
    BloomFilter* BF = (BloomFilter*)malloc(sizeof (BloomFilter));
    if(!BF) {
        return NULL;
    }
    BF->array = (char*)calloc(buckets, sizeof (char));
    if(!BF->array) {
        free(BF);
        return NULL;
    }
    BF->data_size = data_size;
    BF->buckets = buckets;
    BF->size = 0;
    BF->hash = hash;
    return BF;
}

BloomFilter* BloomFilter_destroy(BloomFilter* BF)
{
    free(BF->array);
    BF->array = NULL;
    free(BF);
    BF = NULL;
}

int BloomFilter_search(BloomFilter* BF, void* data)
{
    size_t index = BF->hash(data, BF->buckets);
    if(BF->array[index]) {
        return 1;
    }
    return 0;
}

void BloomFilter_insert(BloomFilter* BF, void* data)
{
    size_t index = BF->hash(data, BF->buckets);
    memset(BF->array + index, 1, sizeof (char));
    BF->size = BF->size + 1;
}
