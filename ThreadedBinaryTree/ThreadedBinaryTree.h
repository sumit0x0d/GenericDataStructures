#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdlib.h>
#include <string.h>

typedef struct ThreadedBinaryTreeNode {
    void* data;
    struct ThreadedBinaryTreeNode* left;
    struct ThreadedBinaryTreeNode* right;
    struct ThreadedBinaryTreeNode* inorder_predecessor;
    struct ThreadedBinaryTreeNode* inorder_successor;
} ThreadedBinaryTreeNode;

typedef struct ThreadedBinaryTree {
    ThreadedBinaryTreeNode* root;
    size_t size;
} ThreadedBinaryTree;

ThreadedBinaryTree* ThreadedBinaryTree_create();
void ThreadedBinaryTree_destroy(ThreadedBinaryTree* bt);

ThreadedBinaryTreeNode* ThreadedBinaryTree_insert(ThreadedBinaryTree* bt, void* data, size_t data_size);

void* ThreadedBinaryTree_root(ThreadedBinaryTree* BT);

#endif
