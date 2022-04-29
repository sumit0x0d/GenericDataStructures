#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct BinarySearchTreeNode {
    void* data;
    struct BinarySearchTreeNode* left;
    struct BinarySearchTreeNode* right;
} BinarySearchTreeNode;

typedef struct BinarySearchTree {
    BinarySearchTreeNode* root;
    size_t data_size;
    size_t size;
    int (*compare)(void* data, void* node_data);
} BinarySearchTree;

BinarySearchTree* BinarySearchTree_create(size_t data_size,
    int (*compare)(void* data, void* node_data));
void BinarySearchTree_destroy(BinarySearchTree* BST);

void* BinarySearchTree_root(BinarySearchTree* BST);
size_t BinarySearchTree_size(BinarySearchTree* BST);

bool BinarySearchTree_insert(BinarySearchTree* BST, void* data);
bool BinarySearchTree_remove(BinarySearchTree* BST, void* data);

BinarySearchTreeNode* BinarySearchTree_begin(BinarySearchTree* BST);
BinarySearchTreeNode* BinarySearchTree_search(BinarySearchTree* BST, void* data);

#endif
