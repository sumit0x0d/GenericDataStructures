#include "BinaryHeap-Array.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct BinaryHeapA {
    void* array;
    size_t data_size;
    size_t capacity;
    size_t size;
    int (*compare)(void* data1, void* data2);
};

BinaryHeapA* BinaryHeapA_create(size_t data_size, size_t capacity,
    int (*compare)(void* data1, void* data2))
{
    BinaryHeapA* BH;
    return BH;
}

void BinaryHeapA_insert(BinaryHeapA* BH, void* data)
{

}

void BinaryHeapA_remove(BinaryHeapA* BH, void* data)
{

}

void BinaryHeapA_extract(BinaryHeapA* BH)
{

}
