#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdbool.h>
#include <stddef.h>

typedef struct ThreadedBinaryTree ThreadedBinaryTree;

ThreadedBinaryTree* ThreadedBinaryTree_create(size_t data_size);
void ThreadedBinaryTree_destroy(ThreadedBinaryTree* bt);

// ThreadedBinaryTreeNode* ThreadedBinaryTree_insert(ThreadedBinaryTree* bt, void* data);

void* ThreadedBinaryTree_root(ThreadedBinaryTree* BT);

#endif
