#ifndef B_TREE_H
#define B_TREE_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct BinaryTree BTree;

BTree* BTree_Create(size_t data_size);
void BTree_Destroy(BTree* BT);

// BTreeNode* BTree_Insert(BTree* BT, void* data, size_t data_size);

void* BTree_Root(BTree* BT);

#endif
