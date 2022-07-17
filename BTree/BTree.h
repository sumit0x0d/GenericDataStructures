#ifndef B_TREE_H
#define B_TREE_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct BinaryTree BTree;

BTree* BTreeCreate(size_t data_size);
void BTreeDestroy(BTree* BT);

// BTreeNode* BTreeInsert(BTree* BT, void* data, size_t data_size);

void* BTree_root(BTree* BT);

#endif
