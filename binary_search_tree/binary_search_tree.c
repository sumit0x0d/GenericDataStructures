#include "binary_search_tree.h"

#include <string.h>

struct BinaryTreeNode *search(struct BinaryTree *binary_tree, void *data, size_t data_tyep_size)
{
    struct BinaryTreeNode *node = binary_tree->root;
    while(node)
        if(data == node->data)
            return node;
        else if(data < node->data)
            node = node->left;
        else
            node = node->right;
    return NULL;
}

void insert(struct BinaryTree *binary_tree, void *data, size_t data_type_size)
{
    assert(binary_tree);
    assert(data);
    assert(data_type_size);
    if(!binary_tree->size) {
        binary_tree->root = binary_tree_insert(binary_tree, data, data_type_size);
        return;
    }

    struct BinaryTreeNode *node = binary_tree->root;
    struct BinaryTreeNode *node_parent = NULL;
    int compare;

    while(node) {
        compare = memcmp(data, node->data, node->data_type_size);
        if(compare == 0)
            return;
        node_parent = node;
        if(compare < 0)
            node = node->left;
        else
            node = node->right;
    }

    node = binary_tree_insert(binary_tree, data, data_type_size);
    // compare = memcmp(data, node_parent->data, node->data_type_size);
    if(compare < 0)
        node_parent->left = node;
    else
        node_parent->right = node;
}

// void binary_tree_node_remove(struct BinaryTreeNode *node)
// {
//     if(!node->left && !node->right) {
//         node = NULL;
//         free(node);
//         return;
//     }
//     struct BinaryTreeNode *node_inorder_predecessor = NULL;
//     struct BinaryTreeNode *node_inorder_successor = NULL;
//     size_t node_left_height = 0;
//     size_t node_right_height = 0;
//     if(node->left)
//         node_left_height = binary_tree_node_height(node->left);
//     if(node->right)
//         node_right_height = binary_tree_node_height(node->right);
//     if(node_left_height < node_right_height) {
//         node_inorder_predecessor = binary_tree_node_inorder_predecessor(node);
//         node->data = node_inorder_predecessor->data;
//     }
//     else {
//         node_inorder_successor = binary_tree_node_inorder_successor(node);
//         node->data = node_inorder_successor->data;
//     }
// }

// void binary_search_tree_remove(struct BinaryTree *binary_tree, int data)
// {
//     if(!binary_tree->size)
//         return;
//     struct BinaryTreeNode *node = binary_tree->root;
//     struct BinaryTreeNode *node_parent = NULL; 
//     while(node) {
//         if(data == node->data) {
//             break;
//             // binary_tree_node_remove(node);
//             // return;
//         }
//         node_parent = node;
//         if(data < node->data)
//             node = node->left;
//         else
//             node = node->right;
//     }
    
//     binary_tree->size--;
// }
