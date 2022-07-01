#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct BinarySearchTree {
    struct Node* root;
    size_t data_size;
    size_t size;
    int (*compare)(void* data1, void* data2);
} BinarySearchTree;

BinarySearchTree* BinarySearchTree_create(size_t data_size,
    int (*compare)(void* data1, void* data2));
void BinarySearchTree_destroy(BinarySearchTree* BST);

bool BinarySearchTree_insert(BinarySearchTree* BST, void* data);
bool BinarySearchTree_remove(BinarySearchTree* BST, void* data);

void* BinarySearchTree_root(BinarySearchTree* BST);

void* BinarySearchTree_search(BinarySearchTree* BST, void* data);

#endif
