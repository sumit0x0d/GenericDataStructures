#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <stdlib.h>
#include <string.h>

typedef struct RedBlackTreeNode {
    void* data;
    struct RedBlackTreeNode* left;
    struct RedBlackTreeNode* right;
    struct RedBlackTreeNode* parent;
    enum {RED, BLACK} color;
} RedBlackTreeNode;

typedef struct RedBlackTree {
    RedBlackTreeNode* root;
    size_t data_size;
    size_t size;
    int (*compare)(void* data1, void* data2);
} RedBlackTree;

RedBlackTree* RedBlackTree_create(size_t data_size,
    int (*compare)(void* data1, void* data2));

int RedBlackTree_insert(RedBlackTree* RBT, void* data);
int RedBlackTree_remove(RedBlackTree* RBT, void* data);

RedBlackTreeNode* RedBlackTree_search(RedBlackTree* RBT, void* data);

void* RedBlackTree_root(RedBlackTree* RBT);

#endif
