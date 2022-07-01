#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct ThreadedBinaryTree {
    struct Node* root;
    size_t data_size;
    size_t size;
} ThreadedBinaryTree;

ThreadedBinaryTree* ThreadedBinaryTree_create(size_t data_size);
void ThreadedBinaryTree_destroy(ThreadedBinaryTree* bt);

// ThreadedBinaryTreeNode* ThreadedBinaryTree_insert(ThreadedBinaryTree* bt, void* data);

void* ThreadedBinaryTree_root(ThreadedBinaryTree* BT);

#endif
