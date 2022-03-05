#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdlib.h>
#include <string.h>

struct BinaryTreeNode {
    void *data;
    size_t data_type_size;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};

struct BinaryTree {
    struct BinaryTreeNode *root;
    size_t size;
    struct BinaryTreeNode *(*insert)(struct BinaryTree *tree, void *data, size_t data_type_size);
};

struct BinaryTree binary_tree_construct();
void binary_tree_destruct(struct BinaryTree *tree);

#endif
