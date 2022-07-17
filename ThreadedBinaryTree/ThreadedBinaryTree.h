#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdbool.h>
#include <stddef.h>

typedef struct ThreadedBinaryTree ThreadedBinaryTree;

ThreadedBinaryTree* ThreadedBinaryTreeCreate(size_t data_size);
void ThreadedBinaryTreeDestroy(ThreadedBinaryTree* bt);

// ThreadedBinaryTreeNode* ThreadedBinaryTreeInsert(ThreadedBinaryTree* bt, void* data);

void* ThreadedBinaryTree_root(ThreadedBinaryTree* BT);

#endif
