#include "binary_search_tree.h"

BinarySearchTree binary_search_tree_create(size_t data_type_size, int (*compare_data)(void *data, void *node_data));
void binary_search_tree_destroy(BinarySearchTree *BST);

static BinarySearchTreeNode *node_create(size_t data_type_size);
static void *node_destroy(BinarySearchTreeNode *node);
static BinarySearchTreeNode *node_inorder_predecessor(BinarySearchTreeNode *node);
static BinarySearchTreeNode *node_inorder_successor(BinarySearchTreeNode *node);

BinarySearchTreeNode *binary_search_tree_search(BinarySearchTree *BST, void *data);
bool binary_search_tree_insert(BinarySearchTree *BST, void *data);
bool binary_search_tree_remove(BinarySearchTree *BST, void *data);

BinarySearchTree binary_search_tree_create(size_t data_type_size, int (*compare_data)(void *data, void *node_data))
{
    BinarySearchTree BST;

    BST.root = NULL;
    BST.size = 0;
    BST.data_type_size = data_type_size;

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

// BinarySearchTreeNode *binary_search_tree_search(BinarySearchTree *BST, void *data, size_t data_type_size)
// {
//     BinarySearchTreeNode *node = BST->root;
    
//     while(node)
//         if(data == node->data)
//             return node;
//         else if(data < node->data)
//             node = node->left;
//         else
//             node = node->right;

//     return NULL;
// }

static BinarySearchTreeNode *node_create(size_t data_type_size)
{
    BinarySearchTreeNode *node = malloc(sizeof (BinarySearchTreeNode));
    if(!node) return NULL;

    node->data = malloc(data_type_size);
    if(!node->data) {
        free(node);
        node = NULL;
        return NULL;
    }

    node->left = NULL;
    node->right = NULL;

    return node;
}

static void *node_destroy(BinarySearchTreeNode *node)
{
    free(node->data);
    node->data = NULL;

    free(node);
    node = NULL;
}

static BinarySearchTreeNode *node_inorder_predecessor(BinarySearchTreeNode *node)
{
    if(node->left) {
        node = node->left;
        while(node) {
            node = node->right;
        }
    }

    return node;
}

static BinarySearchTreeNode *node_inorder_successor(BinarySearchTreeNode *node)
{
    if(node->right) {
        node = node->right;
        while(node) {
            node = node->left;
        }
    }

    return node;
}

bool binary_search_tree_insert(BinarySearchTree *BST, void *data)
{
    if(!binary_search_tree_size(BST)) {
        BST->root = node_create(BST->data_type_size);
        if(!BST->root) return false;

        memcpy(BST->root->data, data, BST->data_type_size);

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

    node = node_create(BST->data_type_size);
    if(!node) return false;

    memcpy(node->data, data, BST->data_type_size);

    if(compare < 0)
        node_parent->left = node;
    else
        node_parent->right = node;

    BST->size = BST->size + 1;

    return true;
}

// void binary_search_tree_node_remove(BinarySearchTreeNode *node)
// {
//     if(!node->left && !node->right) {
//         node = NULL;
//         free(node);
//         return;
//     }
//     BinarySearchTreeNode *node_inorder_predecessor = NULL;
//     BinarySearchTreeNode *node_inorder_successor = NULL;
//     size_t node_left_height = 0;
//     size_t node_right_height = 0;
//     if(node->left)
//         node_left_height = binary_search_tree_node_height(node->left);
//     if(node->right)
//         node_right_height = binary_search_tree_node_height(node->right);
//     if(node_left_height < node_right_height) {
//         node_inorder_predecessor = binary_search_tree_node_inorder_predecessor(node);
//         node->data = node_inorder_predecessor->data;
//     }
//     else {
//         node_inorder_successor = binary_search_tree_node_inorder_successor(node);
//         node->data = node_inorder_successor->data;
//     }
// }

bool binary_search_tree_remove(BinarySearchTree *BST, void *data)
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

    node->data = (node);

    if(node->left && node->right) {
        node_destroy(node);
        node_parent->left = NULL;
        node_parent->right = NULL;
    }

    if(node->left)
    
    node_inorder_predecessor(node);
    

    BST->size = BST->size + 1;
}
