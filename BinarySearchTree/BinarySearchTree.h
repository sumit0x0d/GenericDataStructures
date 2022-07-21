#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdbool.h>
#include <stddef.h>

typedef struct BinarySearchTree BinarySearchTree;

BinarySearchTree* BinarySearchTree_Create(size_t data_size, int (*compare_function)(void* data1, void* data2));
void BinarySearchTree_Destroy(BinarySearchTree* BST);
size_t BinarySearchTree_Size(BinarySearchTree* BST);
bool BinarySearchTree_Empty(BinarySearchTree* BST);
void* BinarySearchTree_Root(BinarySearchTree* BST);
void* BinarySearchTree_Search(BinarySearchTree* BST, void* data);
bool BinarySearchTree_Insert(BinarySearchTree* BST, void* data);
bool BinarySearchTree_Remove(BinarySearchTree* BST, void* data);
void BinarySearchTree_TraversePreorder(BinarySearchTree* BST, void (*function)(void* data));
void BinarySearchTree_TraverseInorder(BinarySearchTree* BST, void (*function)(void* data));
void BinarySearchTree_TraversePostorder(BinarySearchTree* BST, void (*function)(void* data));
void BinarySearchTree_TraverseLevelorder(BinarySearchTree* BST, void (*function)(void* data));

#endif
