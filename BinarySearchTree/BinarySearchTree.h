#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdbool.h>
#include <stddef.h>

typedef struct BinarySearchTree BinarySearchTree;

BinarySearchTree* BinarySearchTreeCreate(size_t data_size, int (*compare_function)(void* data1, void* data2));
void BinarySearchTreeDestroy(BinarySearchTree* BST);
size_t BinarySearchTreeSize(BinarySearchTree* BST);
bool BinarySearchTreeEmpty(BinarySearchTree* BST);
void* BinarySearchTree_root(BinarySearchTree* BST);
void* BinarySearchTreeSearch(BinarySearchTree* BST, void* data);
bool BinarySearchTreeInsert(BinarySearchTree* BST, void* data);
bool BinarySearchTreeRemove(BinarySearchTree* BST, void* data);
void BinarySearchTreeTraverse_preorder(BinarySearchTree* BST, void (*function)(void* data));
void BinarySearchTreeTraverse_inorder(BinarySearchTree* BST, void (*function)(void* data));
void BinarySearchTreeTraverse_postorder(BinarySearchTree* BST, void (*function)(void* data));
void BinarySearchTreeTraverse_levelorder(BinarySearchTree* BST, void (*function)(void* data));

#endif
