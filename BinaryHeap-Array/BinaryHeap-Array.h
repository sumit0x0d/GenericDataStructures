#ifndef BINARY_HEAP_ARRAY_H
#define BINARY_HEAP_ARRAY_H

#include <stdbool.h>
#include <stddef.h>

typedef struct BinaryHeapA BinaryHeapA;

BinaryHeapA* BinaryHeapA_create(size_t data_size, size_t capacity,
    int (*compare)(void* data1, void* data2));
size_t BinaryHeapA_size(BinaryHeapA* BH);
void BinaryHeapA_insert(BinaryHeapA* BH, void* data);
void BinaryHeapA_remove(BinaryHeapA* BH, void* data);
void BinaryHeapA_extract(BinaryHeapA* BH);

#endif
