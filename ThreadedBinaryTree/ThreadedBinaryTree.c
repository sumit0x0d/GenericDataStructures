#include "ThreadedBinaryTree.h"
#include "Node.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct ThreadedBinaryTree {
    struct Node* root;
    size_t data_size;
    size_t size;
};

ThreadedBinaryTree* ThreadedBinaryTree_Create(size_t data_size)
{
    ThreadedBinaryTree* BT = (ThreadedBinaryTree*)malloc(sizeof (ThreadedBinaryTree));
    if(!BT) {
        return NULL;
    }
    BT->root = NULL;
    BT->data_size = data_size;
    BT->size = 0;
    return BT;
}

Node* ThreadedBinaryTree_Insert(ThreadedBinaryTree* BT, void* data)
{
    Node* node = Node_Create(BT->data_size);
    if(!node) {
        return NULL;
    }
    memcpy(node->data, data, BT->data_size);
    BT->size = BT->size + 1;
    return node;
}

void* ThreadedBinaryTree_Root(ThreadedBinaryTree* BT)
{
    return BT->root->data;
}
