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
    size_t size;
    int (*compare_data)(void *data, void *node_data);
} BinarySearchTree;

BinarySearchTree binary_search_tree_create(int (*compare_data)(void *data, void *node_data));
void binary_search_tree_destroy(BinarySearchTree *BST);

BinarySearchTreeNode *binary_search_tree_search(BinarySearchTree *BST, void *data, size_t data_size);
bool binary_search_tree_insert(BinarySearchTree *BST, void *data, size_t data_size);
bool binary_search_tree_remove(BinarySearchTree *BST, void *data, size_t data_size);

#endif
