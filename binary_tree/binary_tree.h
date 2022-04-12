#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdlib.h>
#include <string.h>

typedef struct BinaryTreeNode BinaryTreeNode;
typedef struct BinaryTree BinaryTree;

BinaryTree *binary_tree_create();
void binary_tree_destroy(BinaryTree *bt);

BinaryTreeNode *binary_tree_insert(BinaryTree *bt, void *data, size_t data_size);

#endif
