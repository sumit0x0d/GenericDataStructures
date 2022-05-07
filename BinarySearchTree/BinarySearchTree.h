#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

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
    int (*compare)(void* data1, void* data2);
} BinarySearchTree;

BinarySearchTree* BinarySearchTree_create(size_t data_size,
    int (*compare)(void* data1, void* data2));
void BinarySearchTree_destroy(BinarySearchTree* BST);

int BinarySearchTree_insert(BinarySearchTree* BST, void* data);
int BinarySearchTree_remove(BinarySearchTree* BST, void* data);

void* BinarySearchTree_root(BinarySearchTree* BST);

BinarySearchTreeNode* BinarySearchTree_search(BinarySearchTree* BST, void* data);

#endif
