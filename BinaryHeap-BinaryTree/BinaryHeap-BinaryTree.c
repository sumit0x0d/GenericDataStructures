#include "BinaryHeap-BinaryTree.h"

typedef struct Node {
    void* data;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
} Node;

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

static Node* node_create(size_t data_size)
{
    Node* node = (Node*)malloc(sizeof (Node));
    if(!node) {
        return NULL;
    }
    node->data = malloc(data_size);
    if(!node->data) {
        free(node);
        return NULL;
    }
    node->left = NULL;
    node->right = NULL;
    return node;
}

bool BinaryHeapBT_insert(BinaryHeapBT* BH, void* data)
{
    return true;
}

void BinaryHeapBT_remove(BinaryHeapBT* BH)
{

}
