#include "BinaryHeap-Array.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct BinaryHeapA {
    void* array;
    size_t data_size;
    size_t capacity;
    size_t size;
    int (*compare_function)(void* data1, void* data2);
};

BinaryHeapA* BinaryHeapACreate(size_t data_size, size_t capacity,
    int (*compare_function)(void* data1, void* data2))
{
    BinaryHeapA* BH;
    return BH;
}

size_t BinaryHeapBTSize(BinaryHeapA* BH)
{
    return BH->size;
}

void BinaryHeapAInsert(BinaryHeapA* BH, void* data)
{

}

void BinaryHeapARemove(BinaryHeapA* BH, void* data)
{

}

void BinaryHeapA_extract(BinaryHeapA* BH)
{

}
