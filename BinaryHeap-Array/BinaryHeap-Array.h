#ifndef BINARY_HEAP_ARRAY_H
#define BINARY_HEAP_ARRAY_H

#include <stdlib.h>
#include <string.h>

typedef struct BinaryHeapA {
    void* array;
    size_t data_size;
    size_t capacity;
    size_t size;
    int (*compare)(void* data1, void* data2);
} BinaryHeapA;

BinaryHeapA* BinaryHeapA_create(size_t data_size, size_t capacity,
    int (*compare)(void* data1, void* data2));

void BinaryHeapA_insert(BinaryHeapA* BH, void* data);
void BinaryHeapA_remove(BinaryHeapA* BH, void* data);

#endif
