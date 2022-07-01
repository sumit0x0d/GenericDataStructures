#include "ThreadedBinaryTree.h"

typedef struct Node {
    void* data;
    struct Node* left;
    struct Node* right;
} Node;

static Node* node_create(size_t data_size);

ThreadedBinaryTree* ThreadedBinaryTree_create(size_t data_size)
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

Node* ThreadedBinaryTree_insert(ThreadedBinaryTree* BT, void* data)
{
    Node* node = node_create(BT->data_size);
    if(!node) {
        return NULL;
    }
    memcpy(node->data, data, BT->data_size);
    BT->size = BT->size + 1;
    return node;
}

void* ThreadedBinaryTree_root(ThreadedBinaryTree* BT)
{
    return BT->root->data;
}
