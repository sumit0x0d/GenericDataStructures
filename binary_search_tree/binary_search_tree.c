#include "binary_search_tree.h"

BinarySearchTree binary_search_tree_create(int (*compare_data)(void *data, void *node_data));
void binary_search_tree_destroy(BinarySearchTree *BST);

static BinarySearchTreeNode *node_create(size_t data_size);
static void node_destroy(BinarySearchTreeNode *node);

BinarySearchTreeNode *binary_search_tree_search(BinarySearchTree *BST, void *data, size_t data_size);
bool binary_search_tree_insert(BinarySearchTree *BST, void *data, size_t data_size);
bool binary_search_tree_remove(BinarySearchTree *BST, void *data, size_t data_size);

BinarySearchTree binary_search_tree_create(int (*compare_data)(void *data, void *node_data))
{
    BinarySearchTree BST;

    BST.root = NULL;
    BST.size = 0;

    BST.compare_data = compare_data;

    return BST;
}

// void binary_search_tree_destroy(BinarySearchTree *BST)
// {

// }

size_t binary_search_tree_size(BinarySearchTree *BST)
{
    return BST->size;
}

BinarySearchTreeNode *binary_search_tree_search(BinarySearchTree *BST, void *data, size_t data_size)
{
    BinarySearchTreeNode *node = BST->root;

    while(node) {
        int compare = BST->compare_data(data, node->data);
        if(compare == 0)
            return node;
        if(compare < 0)
            node = node->left;
        else
            node = node->right;
    }

    return NULL;
}

static BinarySearchTreeNode *node_create(size_t data_size)
{
    BinarySearchTreeNode *node = malloc(sizeof (BinarySearchTreeNode));
    if(!node) return NULL;

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

static void node_destroy(BinarySearchTreeNode *node)
{
    free(node->data);
    node->data = NULL;

    free(node);
    node = NULL;
}

bool binary_search_tree_insert(BinarySearchTree *BST, void *data, size_t data_size)
{
    if(!binary_search_tree_size(BST)) {
        BST->root = node_create(data_size);
        if(!BST->root) return false;

        memcpy(BST->root->data, data, data_size);

        BST->size = BST->size + 1;

        return true;
    }

    BinarySearchTreeNode *node = BST->root;
    BinarySearchTreeNode *node_parent = NULL;
    int compare;

    while(node) {
        compare = BST->compare_data(data, node->data);
        if(compare == 0)
            return false;
        node_parent = node;
        if(compare < 0)
            node = node->left;
        else
            node = node->right;
    }

    node = node_create(data_size);
    if(!node) return false;

    memcpy(node->data, data, data_size);

    if(compare < 0)
        node_parent->left = node;
    else
        node_parent->right = node;

    BST->size = BST->size + 1;

    return true;
}

bool binary_search_tree_remove(BinarySearchTree *BST, void *data, size_t data_size)
{
    if(!binary_search_tree_size(BST)) return false;

    BinarySearchTreeNode *node = BST->root;
    BinarySearchTreeNode *node_parent = NULL; 
    int compare;

    while(node) {
        compare = BST->compare_data(data, node->data);
        if(compare == 0)
            break;
        node_parent = node;
        if(compare < 0)
            node = node->left;
        else
            node = node->right;
    }

    if(!node) return false;

    if(!node->left && !node->right) {
        if(node_parent->left == node)
            node_parent->left = NULL;
        else
            node_parent->right = NULL;

        node_destroy(node);
    }
    else if(!node->left) {
        if(node_parent->right == node)
            node_parent->right = node->right;
        else
            node_parent->left = node->right;

        node_destroy(node);
    }
    else if(!node->right) {
        if(node_parent->left == node)
            node_parent->left = node->left;
        else
            node_parent->right = node->left;

        node_destroy(node);
    }
    else {
        BinarySearchTreeNode *node_inorder_successor = node->right;
        BinarySearchTreeNode *node_inorder_successor_parent = node;

        while(node_inorder_successor->left) {
            node_inorder_successor_parent = node_inorder_successor;
            node_inorder_successor = node_inorder_successor->left;
        }

        if(node_inorder_successor_parent == node) {
            node_inorder_successor_parent->right = node_inorder_successor->right;
        }
        else
            node_inorder_successor_parent->left = node_inorder_successor->right;

        memcpy(node->data, node_inorder_successor->data, data_size);

        node_destroy(node_inorder_successor);
    }

    BST->size = BST->size - 1;

    return true;
}
