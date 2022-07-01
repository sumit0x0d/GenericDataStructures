#ifndef BINARY_HEAP_BINARY_TREE_H
#define BINARY_HEAP_BINARY_TREE_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct BinaryHeapBT {
    struct Node* root;
    size_t data_size;
    struct Node* leftmost_node;
    struct Node* rightmost_node;
    size_t size;
    int (*compare)(void* data1, void* data2);
} BinaryHeapBT;

BinaryHeapBT* BinaryHeapBT_create(size_t data_size, int (*compare)(void* data1, void* data2));
void BinaryHeapBT_destroy(BinaryHeapBT* BH);

void* BinaryHeapBT_root(BinaryHeapBT* BH);

bool BinaryHeapBT_insert(BinaryHeapBT* BH, void* data);
void BinaryHeapBT_remove(BinaryHeapBT* BH);
void* BinaryHeapBT_extract(BinaryHeapBT* BH);

#endif
