#include "BTree.h"
#include "Node.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct BinaryTree {
    Node* root;
    size_t data_size;
    size_t size;
};

BTree* BTreeCreate(size_t data_size)
{
    BTree* BT = (BTree*)malloc(sizeof (BTree));
    if(!BT) {
        return NULL;
    }
    return BT;
}

void BTreeDestroy(BTree* BT)
{

}

// BTreeNode* BTreeInsert(BTree* BT, void* data, size_t data_size)
// {

// }

void* BTree_root(BTree* BT)
{
    return BT->root;
}
