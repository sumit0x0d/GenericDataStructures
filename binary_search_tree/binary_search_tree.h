#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct BinarySearchTreeNode {
    void *data;
    struct BinarySearchTreeNode *left;
    struct BinarySearchTreeNode *right;
};

struct BinarySearchTree {
    struct BinarySearchTreeNode *root;
    size_t data_type_size;
    size_t size;
};

struct BinarySearchTree binary_search_tree_construct(size_t data_type_size);
// void binary_search_tree_destruct(struct BinarySearchTree *BST);
struct BinarySearchTreeNode *binary_search_tree_search(struct BinarySearchTree *BST, void *data);
bool binary_search_tree_insert(struct BinarySearchTree *BST, void *data);
bool binary_search_tree_remove(struct BinarySearchTree *BST, void *data);

#endif
