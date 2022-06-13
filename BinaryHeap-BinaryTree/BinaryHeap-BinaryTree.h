#ifndef BINARY_HEAP_BINARY_TREE_H
#define BINARY_HEAP_BINARY_TREE_H

#include <stdlib.h>
#include <string.h>

typedef struct BinaryHeapBTNode {
    void* data;
    struct BinaryHeapBTNode* left;
    struct BinaryHeapBTNode* right;
    struct BinaryHeapBTNode* parent;
} BinaryHeapBTNode;

typedef struct BinaryHeapBT {
    BinaryHeapBTNode* root;
    size_t data_size;
    BinaryHeapBTNode* leftmost_node;
    BinaryHeapBTNode* rightmost_node;
    size_t size;
    int (*compare)(void* data1, void* data2);
} BinaryHeapBT;

BinaryHeapBT* BinaryHeapBT_create(size_t data_size, int (*compare)(void* data1, void* data2));
void BinaryHeapBT_destroy(BinaryHeapBT* BH);

void* BinaryHeapBT_root(BinaryHeapBT* BH);

int BinaryHeapBT_insert(BinaryHeapBT* BH, void* data);
void BinaryHeapBT_remove(BinaryHeapBT* BH);

#endif
