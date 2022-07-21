#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdbool.h>
#include <stddef.h>

typedef struct ThreadedBinaryTree ThreadedBinaryTree;

ThreadedBinaryTree* ThreadedBinaryTree_Create(size_t data_size);
void ThreadedBinaryTree_Destroy(ThreadedBinaryTree* bt);

// ThreadedBinaryTreeNode* ThreadedBinaryTree_Insert(ThreadedBinaryTree* bt, void* data);

void* ThreadedBinaryTree_Root(ThreadedBinaryTree* BT);

#endif
