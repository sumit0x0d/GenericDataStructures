#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdlib.h>
#include <string.h>

typedef struct BinaryTreeNode {
    void* data;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
} BinaryTreeNode;

typedef struct BinaryTree {
    BinaryTreeNode* root;
    size_t size;
} BinaryTree;

BinaryTree* BinaryTree_create();
void BinaryTree_destroy(BinaryTree* bt);

BinaryTreeNode* BinaryTree_insert(BinaryTree* bt, void* data, size_t data_size);

#endif
