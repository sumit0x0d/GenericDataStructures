#ifndef BINARY_HEAP_BINARY_TREE_H
#define BINARY_HEAP_BINARY_TREE_H

#include <stdbool.h>
#include <stddef.h>

typedef struct BinaryHeapBT BinaryHeapBT;

BinaryHeapBT* BinaryHeapBTCreate(size_t data_size, int (*compare_function)(void* data1, void* data2));
void BinaryHeapBTDestroy(BinaryHeapBT* BH);
size_t BinaryHeapBTSize(BinaryHeapBT* BH);
void* BinaryHeapBT_root(BinaryHeapBT* BH);
bool BinaryHeapBTInsert(BinaryHeapBT* BH, void* data);
void BinaryHeapBTRemove(BinaryHeapBT* BH);
void* BinaryHeapBT_extract(BinaryHeapBT* BH);

#endif
