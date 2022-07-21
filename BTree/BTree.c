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

BTree* BTree_Create(size_t data_size)
{
    BTree* BT = (BTree*)malloc(sizeof (BTree));
    if(!BT) {
        return NULL;
    }
    return BT;
}

void BTree_Destroy(BTree* BT)
{

}

// BTreeNode* BTree_Insert(BTree* BT, void* data, size_t data_size)
// {

// }

void* BTree_Root(BTree* BT)
{
    return BT->root;
}
