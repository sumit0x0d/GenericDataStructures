#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdlib.h>
#include <string.h>

typedef struct BinaryTreeNode {
    void *data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
} BinaryTreeNode;

typedef struct BinaryTree {
    BinaryTreeNode *root;
    size_t data_type_size;
    size_t size;
} BinaryTree;

BinaryTree binary_tree_construct(size_t data_type_size);
void binary_tree_destruct(BinaryTree *bt);
BinaryTreeNode *binary_tree_insert(BinaryTree *bt, void *data);

#endif
