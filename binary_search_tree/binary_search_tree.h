#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stddef.h>

struct BinarySearchTreeNode {
    void *data;
    size_t data_type_size;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
    struct BinaryTreeNode *parent;
};

struct BinarySearchTree {
    struct BinarySearchTree *root;
    size_t size;
    struct BinarySearchTreeNode *(*search)(struct BinarySearchTree *binary_search_tree, void *data, size_t data_type_size);
    struct BinarySearchTree *(*insert)(struct BinaryTree *binary_tree, void *data, size_t data_type_size);
    void (*remove)(struct BinaryTree *binary_tree, void *data, size_t data_type_size);
};

struct BinaryTree binary_search_tree_construct();
void binary_search_tree_distruct(struct BinarySearchTree *binary_search_tree);

#endif
