#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct BinarySearchTreeNode {
    void *data;
    size_t data_type_size;
    struct BinarySearchTreeNode *left;
    struct BinarySearchTreeNode *right;
} BinarySearchTreeNode;

typedef struct BinarySearchTree {
    BinarySearchTreeNode *root;
    size_t size;
} BinarySearchTree;

BinarySearchTree binary_search_tree_construct();
void binary_search_tree_destruct(BinarySearchTree *BST);

BinarySearchTreeNode *binary_search_tree_search(BinarySearchTree *BST, void *data, size_t data_type_size);
bool binary_search_tree_insert(BinarySearchTree *BST, void *data, size_t data_type_size);
bool binary_search_tree_remove(BinarySearchTree *BST, void *data, size_t data_type_size);

#endif
