#include "binary_search_tree.h"

BinarySearchTree* BinarySearchTree_create(size_t data_size,
    int (*compare)(void* data, void* node_data));
void BinarySearchTree_destroy(BinarySearchTree* BST);

static BinarySearchTreeNode* BInarySearchTreeNode_create(size_t data_size);
static void BInarySearchTreeNode_destroy(BinarySearchTreeNode* node);

bool BinarySearchTree_insert(BinarySearchTree* BST, void* data);
bool BinarySearchTree_remove(BinarySearchTree* BST, void* data);

BinarySearchTreeNode* BinarySearchTree_search(BinarySearchTree* BST, void* data);

BinarySearchTree* BinarySearchTree_create(size_t data_size,
    int (*compare)(void* data, void* node_data))
{
    BinarySearchTree* BST = malloc(sizeof (BinarySearchTree));
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

static BinarySearchTreeNode* BInarySearchTreeNode_create(size_t data_size)
{
    BinarySearchTreeNode* node = malloc(sizeof (BinarySearchTreeNode));
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

static void BInarySearchTreeNode_destroy(BinarySearchTreeNode* node)
{
    free(node->data);
    node->data = NULL;
    free(node);
    node = NULL;
}

bool BinarySearchTree_insert(BinarySearchTree* BST, void* data)
{
    if(!BST->root) {
        BST->root = BInarySearchTreeNode_create(BST->data_size);
        if(!BST->root) {
            return false;
        }
        memcpy(BST->root->data, data, BST->data_size);
        BST->size = BST->size + 1;
        return true;
    }
    BinarySearchTreeNode* node = BST->root;
    BinarySearchTreeNode* node_parent = NULL;
    int compare;
    while(node) {
        compare = BST->compare(data, node->data);
        if(compare == 0) {
            return false;
        }
        node_parent = node;
        if(compare < 0) {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }
    node = BInarySearchTreeNode_create(BST->data_size);
    if(!node) {
        return false;
    }
    memcpy(node->data, data, BST->data_size);
    if(compare < 0) {
        node_parent->left = node;
    }
    else {
        node_parent->right = node;
    }
    BST->size = BST->size + 1;
    return true;
}

bool BinarySearchTree_remove(BinarySearchTree* BST, void* data)
{
    if(!BST->root) {
        return false;
    }
    BinarySearchTreeNode* pointer = BST->root;
    BinarySearchTreeNode* pointer_parent = NULL; 
    int compare;
    while(pointer) {
        compare = BST->compare(data, pointer->data);
        if(compare == 0) {
            break;
        }
        pointer_parent = pointer;
        if(compare < 0) {
            pointer = pointer->left;
        }
        else {
            pointer = pointer->right;
        }
    }
    if(!pointer) {   
        return false;
    }
    if(!pointer->left && !pointer->right) {
        if(pointer_parent->left == pointer) {
            pointer_parent->left = NULL;
        }
        else {
            pointer_parent->right = NULL;
        }
        BInarySearchTreeNode_destroy(pointer);
    }
    else if(!pointer->left) {
        if(pointer_parent->right == pointer) {
            pointer_parent->right = pointer->right;
        }
        else {
            pointer_parent->left = pointer->right;
        }
        BInarySearchTreeNode_destroy(pointer);
    }
    else if(!pointer->right) {
        if(pointer_parent->left == pointer) {
            pointer_parent->left = pointer->left;
        }
        else {
            pointer_parent->right = pointer->left;
        }
        BInarySearchTreeNode_destroy(pointer);
    }
    else {
        BinarySearchTreeNode* node_inorder_successor = pointer->right;
        BinarySearchTreeNode* node_inorder_successor_parent = pointer;
        while(node_inorder_successor->left) {
            node_inorder_successor_parent = node_inorder_successor;
            node_inorder_successor = node_inorder_successor->left;
        }
        if(node_inorder_successor_parent == pointer) {
            node_inorder_successor_parent->right = node_inorder_successor->right;
        }
        else {
            node_inorder_successor_parent->left = node_inorder_successor->right;
        }
        memcpy(pointer->data, node_inorder_successor->data, BST->data_size);
        BInarySearchTreeNode_destroy(node_inorder_successor);
    }
    BST->size = BST->size - 1;
    return true;
}

BinarySearchTreeNode* BinarySearchTree_search(BinarySearchTree* BST, void* data)
{
    BinarySearchTreeNode* pointer = BST->root;
    while(pointer) {
        int compare = BST->compare(data, pointer->data);
        if(compare == 0) {
            return pointer;
        }
        if(compare < 0) {
            pointer = pointer->left;
        }
        else {
            pointer = pointer->right;
        }
    }
    return NULL;
}
