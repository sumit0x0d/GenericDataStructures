#ifndef BINARY_HEAP_ARRAY_H
#define BINARY_HEAP_ARRAY_H

#include <stdbool.h>
#include <stddef.h>

typedef struct BinaryHeapA BinaryHeapA;

BinaryHeapA* BinaryHeapACreate(size_t data_size, size_t capacity,
    int (*compare_function)(void* data1, void* data2));
size_t BinaryHeapASize(BinaryHeapA* BH);
void BinaryHeapAInsert(BinaryHeapA* BH, void* data);
void BinaryHeapARemove(BinaryHeapA* BH, void* data);
void BinaryHeapA_extract(BinaryHeapA* BH);

#endif
