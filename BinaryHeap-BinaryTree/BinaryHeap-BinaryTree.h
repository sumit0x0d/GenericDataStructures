#ifndef BINARY_HEAP_BINARY_TREE_H
#define BINARY_HEAP_BINARY_TREE_H

#include <stdbool.h>
#include <stddef.h>

typedef struct BinaryHeapBT BinaryHeapBT;

BinaryHeapBT* BinaryHeapBT_create(size_t data_size, int (*compare)(void* data1, void* data2));
void BinaryHeapBT_destroy(BinaryHeapBT* BH);
size_t BinaryHeapBT_size(BinaryHeapBT* BH);
void* BinaryHeapBT_root(BinaryHeapBT* BH);
bool BinaryHeapBT_insert(BinaryHeapBT* BH, void* data);
void BinaryHeapBT_remove(BinaryHeapBT* BH);
void* BinaryHeapBT_extract(BinaryHeapBT* BH);

#endif
