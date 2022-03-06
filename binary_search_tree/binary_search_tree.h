#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdlib.h>
#include <string.h>

struct BinarySearchTreeNode {
    void *data;
    size_t data_type_size;
    struct BinarySearchTreeNode *left;
    struct BinarySearchTreeNode *right;
};

struct BinarySearchTree {
    struct BinarySearchTreeNode *root;
    size_t size;
    struct BinarySearchTreeNode *(*search)(struct BinarySearchTree *bst, void *data, size_t data_type_size);
    void (*insert)(struct BinarySearchTree *bst, void *data, size_t data_type_size);
    void (*remove)(struct BinarySearchTree *bst, void *data, size_t data_type_size);
};

struct BinarySearchTree binary_search_tree_construct();
// void binary_search_tree_destruct(struct BinarySearchTree *bst);

#endif
