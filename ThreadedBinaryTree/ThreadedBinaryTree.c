#include "ThreadedBinaryTree.h"

ThreadedBinaryTree* ThreadedBinaryTree_create();

static ThreadedBinaryTreeNode* ThreadedBinaryTreeNode_create(size_t data_size);

ThreadedBinaryTreeNode* ThreadedBinaryTree_insert(ThreadedBinaryTree* BT, void* data, size_t data_size);

void* ThreadedBinaryTree_root(ThreadedBinaryTree* BT);

ThreadedBinaryTree* ThreadedBinaryTree_create()
{
    ThreadedBinaryTree* BT = malloc(sizeof (ThreadedBinaryTree));
    if(!BT) {
        return NULL;
    }
    BT->root = NULL;
    BT->size = 0;
    return BT;
}

static ThreadedBinaryTreeNode* ThreadedBinaryTreeNode_create(size_t data_size)
{
    ThreadedBinaryTreeNode* node = malloc(sizeof (ThreadedBinaryTreeNode));
    if(!node) {
        return NULL;
    }
    node->data = malloc(data_size);
    if(!node->data) {
        free(node);
        node = NULL;
        return NULL;
    }
    node->left = NULL;
    node->right = NULL;
    return node;
}

ThreadedBinaryTreeNode* ThreadedBinaryTree_insert(ThreadedBinaryTree* BT, void* data, size_t data_size)
{
    ThreadedBinaryTreeNode* node = ThreadedBinaryTreeNode_create(data_size);
    if(!node) {
        return NULL;
    }
    memcpy(node->data, data, data_size);
    BT->size = BT->size + 1;
    return node;
}

void* ThreadedBinaryTree_root(ThreadedBinaryTree* BT)
{
    return BT->root->data;
}
