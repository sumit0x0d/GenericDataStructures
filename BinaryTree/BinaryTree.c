#include "BinaryTree.h"

BinaryTree* BinaryTree_create();

static BinaryTreeNode* BinaryTreeNode_create(size_t data_size);

BinaryTreeNode* BinaryTree_insert(BinaryTree* BT, void* data, size_t data_size);

void* BinaryTree_root(BinaryTree* BT);

BinaryTree* BinaryTree_create()
{
    BinaryTree* BT = malloc(sizeof (BinaryTree));
    if(!BT) {
        return NULL;
    }
    BT->root = NULL;
    BT->size = 0;
    return BT;
}

static BinaryTreeNode* BinaryTreeNode_create(size_t data_size)
{
    BinaryTreeNode* node = malloc(sizeof (BinaryTreeNode));
    if(!node) {
        return NULL;
    }
    node->data = malloc(data_size);
    if(!node->data) {
        free(node);
        node = NULL;
        return NULL;
    }
    node->left = NULL;
    node->right = NULL;
    return node;
}

BinaryTreeNode* BinaryTree_insert(BinaryTree* BT, void* data, size_t data_size)
{
    BinaryTreeNode* node = BinaryTreeNode_create(data_size);
    if(!node) {
        return NULL;
    }
    memcpy(node->data, data, data_size);
    BT->size = BT->size + 1;
    return node;
}

void* BinaryTree_root(BinaryTree* BT)
{
    return BT->root->data;
}
