#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdbool.h>
#include <stddef.h>

typedef struct BinarySearchTree BinarySearchTree;

BinarySearchTree* BinarySearchTree_create(size_t data_size, int (*compare)(void* data1, void* data2));
void BinarySearchTree_destroy(BinarySearchTree* BST);
size_t BinarySearchTree_size(BinarySearchTree* BST);
bool BinarySearchTree_empty(BinarySearchTree* BST);
void* BinarySearchTree_root(BinarySearchTree* BST);
void* BinarySearchTree_search(BinarySearchTree* BST, void* data);
bool BinarySearchTree_insert(BinarySearchTree* BST, void* data);
bool BinarySearchTree_remove(BinarySearchTree* BST, void* data);
void BinarySearchTree_traverse_preorder(BinarySearchTree* BST, void (*function)(void* data));
void BinarySearchTree_traverse_inorder(BinarySearchTree* BST, void (*function)(void* data));
void BinarySearchTree_traverse_postorder(BinarySearchTree* BST, void (*function)(void* data));
void BinarySearchTree_traverse_levelorder(BinarySearchTree* BST, void (*function)(void* data));

#endif
