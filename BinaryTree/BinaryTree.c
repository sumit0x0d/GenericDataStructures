#include "BinaryTree.h"

static BinaryTreeNode* node_create(size_t data_size);

BinaryTree* BinaryTree_create()
{
    BinaryTree* BT = (BinaryTree*)malloc(sizeof (BinaryTree));
    if(!BT) {
        return NULL;
    }
    BT->root = NULL;
    BT->size = 0;
    return BT;
}

static BinaryTreeNode* node_create(size_t data_size)
{
    BinaryTreeNode* node = (BinaryTreeNode*)malloc(sizeof (BinaryTreeNode));
    if(!node) {
        return NULL;
    }
    node->data = malloc(data_size);
    if(!node->data) {
        free(node);
        return NULL;
    }
    node->left = NULL;
    node->right = NULL;
    return node;
}

BinaryTreeNode* BinaryTree_insert(BinaryTree* BT, void* data, size_t data_size)
{
    BinaryTreeNode* node = node_create(data_size);
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
