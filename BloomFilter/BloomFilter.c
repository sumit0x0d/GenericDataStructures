#include "BloomFilter.h"

BloomFilter* BloomFilter_create(size_t data_size, size_t bucket_count,
    size_t (*hash)(void* data, size_t data_size, size_t bucket_count))
{
    BloomFilter* BF = (BloomFilter*)malloc(sizeof (BloomFilter));
    if(!BF) {
        return NULL;
    }
    BF->array = (char*)calloc(bucket_count, sizeof (char));
    if(!BF->array) {
        free(BF);
        return NULL;
    }
    BF->data_size = data_size;
    BF->bucket_count = bucket_count;
    BF->size = 0;
    BF->hash = hash;
    return BF;
}

void BloomFilter_destroy(BloomFilter* BF)
{
    free(BF->array);
    BF->array = NULL;
    free(BF);
    BF = NULL;
}

bool BloomFilter_search(BloomFilter* BF, void* data)
{
    size_t index = BF->hash(data, BF->data_size, BF->bucket_count);
    if(BF->array[index]) {
        return true;
    }
    return false;
}

void BloomFilter_insert(BloomFilter* BF, void* data)
{
    size_t index = BF->hash(data, BF->data_size, BF->bucket_count);
    memset(BF->array + index, 1, sizeof (char));
    BF->size = BF->size + 1;
}
