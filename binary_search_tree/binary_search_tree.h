#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct BinarySearchTreeNode BinarySearchTreeNode;
typedef struct BinarySearchTree BinarySearchTree;

BinarySearchTree* binary_search_tree_create(size_t data_size,
    int (*compare)(void* data, void* node_data));
void binary_search_tree_destroy(BinarySearchTree* BST);

size_t binary_search_tree_size(BinarySearchTree* BST);

BinarySearchTreeNode* binary_search_tree_search(BinarySearchTree* BST, void* data);
bool binary_search_tree_insert(BinarySearchTree* BST, void* data);
bool binary_search_tree_remove(BinarySearchTree* BST, void* data);

#endif
