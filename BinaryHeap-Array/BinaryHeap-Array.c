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

BinaryHeapA* BinaryHeapA_Create(size_t data_size, size_t capacity,
    int (*compare)(void* data1, void* data2))
{
    BinaryHeapA* BH;
    return BH;
}

size_t BinaryHeapBT_Size(BinaryHeapA* BH)
{
    return BH->size;
}

void BinaryHeapA_Insert(BinaryHeapA* BH, void* data)
{

}

void BinaryHeapA_Remove(BinaryHeapA* BH, void* data)
{

}

void BinaryHeapA_extract(BinaryHeapA* BH)
{

}
