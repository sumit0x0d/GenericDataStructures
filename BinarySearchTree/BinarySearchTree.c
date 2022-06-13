#include "BinarySearchTree.h"

static BinarySearchTreeNode* node_create(size_t data_size);
static void node_destroy(BinarySearchTreeNode* node);

BinarySearchTree* BinarySearchTree_create(size_t data_size,
    int (*compare)(void* data1, void* data2))
{
    BinarySearchTree* BST = (BinarySearchTree*)malloc(sizeof (BinarySearchTree));
    if(!BST) {
        return NULL;
    }
    BST->root = NULL;
    BST->data_size = data_size;
    BST->size = 0;
    BST->compare = compare;
    return BST;
}

// void BinarySearchTree_destroy(BinarySearchTree* BST)
// {

// }

static BinarySearchTreeNode* node_create(size_t data_size)
{
    BinarySearchTreeNode* node = (BinarySearchTreeNode*)malloc(sizeof (BinarySearchTreeNode));
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

static void node_destroy(BinarySearchTreeNode* node)
{
    free(node->data);
    node->data = NULL;
    free(node);
    node = NULL;
}

int BinarySearchTree_insert(BinarySearchTree* BST, void* data)
{
    if(!BST->root) {
        BST->root = node_create(BST->data_size);
        if(!BST->root) {
            return 0;
        }
        memcpy(BST->root->data, data, BST->data_size);
        BST->size = BST->size + 1;
        return 1;
    }
    BinarySearchTreeNode* node = BST->root;
    BinarySearchTreeNode* node_parent = NULL;
    int compare;
    while(node) {
        compare = BST->compare(data, node->data);
        if(compare == 0) {
            return 0;
        }
        node_parent = node;
        if(compare < 0) {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }
    node = node_create(BST->data_size);
    if(!node) {
        return 0;
    }
    memcpy(node->data, data, BST->data_size);
    if(compare < 0) {
        node_parent->left = node;
    }
    else {
        node_parent->right = node;
    }
    BST->size = BST->size + 1;
    return 1;
}

int BinarySearchTree_remove(BinarySearchTree* BST, void* data)
{
    if(!BST->root) {
        return 0;
    }
    BinarySearchTreeNode* node = BST->root;
    BinarySearchTreeNode* node_parent = NULL; 
    int compare;
    while(node) {
        compare = BST->compare(data, node->data);
        if(compare == 0) {
            break;
        }
        node_parent = node;
        if(compare < 0) {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }
    if(!node) {   
        return 0;
    }
    if(!node->left && !node->right) {
        if(node_parent->left == node) {
            node_parent->left = NULL;
        }
        else {
            node_parent->right = NULL;
        }
        node_destroy(node);
    }
    else if(!node->left) {
        if(node_parent->right == node) {
            node_parent->right = node->right;
        }
        else {
            node_parent->left = node->right;
        }
        node_destroy(node);
    }
    else if(!node->right) {
        if(node_parent->left == node) {
            node_parent->left = node->left;
        }
        else {
            node_parent->right = node->left;
        }
        node_destroy(node);
    }
    else {
        BinarySearchTreeNode* node_successor = node->right;
        BinarySearchTreeNode* node_successor_parent = node;
        while(node_successor->left) {
            node_successor_parent = node_successor;
            node_successor = node_successor->left;
        }
        if(node_successor_parent == node) {
            node_successor_parent->right = node_successor->right;
        }
        else {
            node_successor_parent->left = node_successor->right;
        }
        memcpy(node->data, node_successor->data, BST->data_size);
        node_destroy(node_successor);
    }
    BST->size = BST->size - 1;
    return 1;
}

BinarySearchTreeNode* BinarySearchTree_search(BinarySearchTree* BST, void* data)
{
    BinarySearchTreeNode* node = BST->root;
    while(node) {
        int compare = BST->compare(data, node->data);
        if(compare == 0) {
            return node;
        }
        if(compare < 0) {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }
    return NULL;
}

void* BinarySearchTree_root(BinarySearchTree* BST)
{
    return BST->root->data;
}
