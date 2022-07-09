#include "BinaryHeap-BinaryTree.h"
#include "Node.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct BinaryHeapBT {
    struct Node* root;
    size_t data_size;
    struct Node* leftmost_node;
    struct Node* rightmost_node;
    size_t size;
    int (*compare)(void* data1, void* data2);
};

BinaryHeapBT* BinaryHeapBT_create(size_t data_size, int (*compare)(void* data1, void* data2))
{
    BinaryHeapBT* BH = (BinaryHeapBT*)malloc(sizeof (BinaryHeapBT));
    if(!BH) {
        return NULL;
    }
    BH->root = NULL;
    BH->data_size = data_size;
    BH->size = 0;
    return BH;
}

void BinaryHeapBT_destroy(BinaryHeapBT* BH)
{

}

void* BinaryHeapBT_root(BinaryHeapBT* BH)
{
    return BH->root->data;
}

bool BinaryHeapBT_insert(BinaryHeapBT* BH, void* data)
{
    return true;
}

void BinaryHeapBT_remove(BinaryHeapBT* BH)
{

}
