#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct BinarySearchTreeNode {
    void *data;
    struct BinarySearchTreeNode *left;
    struct BinarySearchTreeNode *right;
} BinarySearchTreeNode;

typedef struct BinarySearchTree {
    BinarySearchTreeNode *root;
    size_t data_type_size;
    size_t size;
} BinarySearchTree;

BinarySearchTree binary_search_tree_construct(size_t data_type_size);
// void binary_search_tree_destruct(BinarySearchTree *BST);
BinarySearchTreeNode *binary_search_tree_search(BinarySearchTree *BST, void *data);
bool binary_search_tree_insert(BinarySearchTree *BST, void *data);
bool binary_search_tree_remove(BinarySearchTree *BST, void *data);

#endif
