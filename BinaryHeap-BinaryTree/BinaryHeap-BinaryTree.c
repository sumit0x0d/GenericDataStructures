#include "BinaryHeap-BinaryTree.h"
#include "Node.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

struct BinaryHeapBT {
    struct Node* root;
    size_t data_size;
    struct Node* leftmost_node;
    struct Node* rightmost_node;
    size_t size;
    int (*compare_function)(void* data1, void* data2);
};

BinaryHeapBT* BinaryHeapBT_Create(size_t data_size, int (*compare_function)(void* data1, void* data2))
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

void BinaryHeapBT_Destroy(BinaryHeapBT* BH)
{

}

size_t BinaryHeapBT_Size(BinaryHeapBT* BH)
{
    return BH->size;
}

void* BinaryHeapBT_Root(BinaryHeapBT* BH)
{
    return BH->root->data;
}

bool BinaryHeapBT_Insert(BinaryHeapBT* BH, void* data)
{
    return true;
}

void BinaryHeapBT_Remove(BinaryHeapBT* BH)
{

}
