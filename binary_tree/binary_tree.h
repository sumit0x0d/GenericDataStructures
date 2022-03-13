#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdlib.h>
#include <string.h>

struct BinaryTreeNode {
    void *data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};

struct BinaryTree {
    struct BinaryTreeNode *root;
    size_t data_type_size;
    size_t size;
    struct BinaryTreeNode *(*insert)(struct BinaryTree *bt, void *data);
};

struct BinaryTree binary_tree_construct(size_t data_type_size);
void binary_tree_destruct(struct BinaryTree *bt);

#endif
