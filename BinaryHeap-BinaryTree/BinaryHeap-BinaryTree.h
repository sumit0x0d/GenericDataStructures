#ifndef BINARY_HEAP_BINARY_TREE_H
#define BINARY_HEAP_BINARY_TREE_H

#include <stdbool.h>
#include <stddef.h>

typedef struct BinaryHeapBT BinaryHeapBT;

BinaryHeapBT* BinaryHeapBT_Create(size_t data_size, int (*compare)(void* data1, void* data2));
void BinaryHeapBT_Destroy(BinaryHeapBT* BH);
size_t BinaryHeapBT_Size(BinaryHeapBT* BH);
void* BinaryHeapBT__Root(BinaryHeapBT* BH);
bool BinaryHeapBT_Insert(BinaryHeapBT* BH, void* data);
void BinaryHeapBT_Remove(BinaryHeapBT* BH);
void* BinaryHeapBT_Extract(BinaryHeapBT* BH);

#endif
