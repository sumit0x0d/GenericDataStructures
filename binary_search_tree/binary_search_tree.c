#include "binary_search_tree.h"

BinarySearchTree binary_search_tree_construct(int data_type, int (*compare_data)(void *data, void *node_data));
void binary_search_tree_destruct(BinarySearchTree *BST);

BinarySearchTreeNode *binary_search_tree_search(BinarySearchTree *BST, void *data, size_t data_type_size);
bool binary_search_tree_insert(BinarySearchTree *BST, void *data, size_t data_type_size);
bool binary_search_tree_remove(BinarySearchTree *BST, void *data, size_t data_type_size);

BinarySearchTree binary_search_tree_construct(int data_type, int (*compare_data)(void *data, void *node_data))
{
    BinarySearchTree BST;

    BST.root = NULL;
    BST.size = 0;
    BST.data_type = data_type;

    BST.compare_data = compare_data;

    return BST;
}

// void binary_search_tree_destruct(BinarySearchTree *BST)
// {

// }

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

static BinarySearchTreeNode *node_construct(size_t data_type_size)
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

bool binary_search_tree_insert(BinarySearchTree *BST, void *data, size_t data_type_size)
{
    if(!BST->size) {
        BST->root = node_construct(data_type_size);
        if(!BST->root) return false;

        memcpy(BST->root->data, data, data_type_size);

        BST->size = BST->size + 1;

        return true;
    }

    BinarySearchTreeNode *node = BST->root;
    BinarySearchTreeNode *node_parent = NULL;
    int compare;

    while(node) {
        // BST->compare_data(data, node->data);
        compare = memcmp(data, node->data, data_type_size);
        if(compare == 0)
            return false;
        node_parent = node;
        if(compare < 0)
            node = node->left;
        else
            node = node->right;
    }

    node = node_construct(data_type_size);
    if(!node) return false;

    memcpy(node->data, data, data_type_size);

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

// void binary_search_tree_remove(BinarySearchTree *BST, int data)
// {
//     if(!BST->size)
//         return;
//     BinarySearchTreeNode *node = BST->root;
//     BinarySearchTreeNode *node_parent = NULL; 
//     while(node) {
//         if(data == node->data) {
//             break;
//             // binary_search_tree_node_remove(node);
//             // return;
//         }
//         node_parent = node;
//         if(data < node->data)
//             node = node->left;
//         else
//             node = node->right;
//     }
    
//     BST->size--;
// }
