#ifndef B_TREE_H
#define B_TREE_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct BTreeNode {
    void* data;
    struct BTreeNode* left;
    struct BTreeNode* right;
} BTreeNode;

typedef struct BinaryTree {
    BTreeNode* root;
    size_t data_size;
    size_t size;
} BTree;

BTree* BTree_create(size_t data_size);
void BTree_destroy(BTree* BT);

BTreeNode* BTree_insert(BTree* BT, void* data, size_t data_size);

void* BTree_root(BTree* BT);

#endif
