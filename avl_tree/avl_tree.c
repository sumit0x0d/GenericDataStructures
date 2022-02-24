#include "avl_tree.h"

#include <string.h>

struct BinaryTreeNode *avl_tree_search(struct BinaryTree *binary_tree, void *data, size_t data_type_size)
{
    struct BinaryTreeNode *node = binary_tree->root;
    while(node) {
        int compare = memcmp(data, node->data, data_type_size);
        if(compare == 0)
            return node;
        else if(compare < 0)
            node = node->left;
        else
            node = node->right;
    }
    return NULL;
}

int binary_tree_node_balance_factor(struct BinaryTreeNode *node)
{
    size_t node_left_height = 0;
    size_t node_right_height = 0;
    if(node->left)
        node_left_height = binary_tree_node_height(node->left);
    if(node->right)
        node_right_height = binary_tree_node_height(node->right);
    return (int)(node_right_height - node_left_height);
}

struct BinaryTreeNode *binary_tree_node_rotate_left(struct BinaryTreeNode *node)
{
    struct BinaryTreeNode *node_right = node->right;
    struct BinaryTreeNode *node_right_left = node_right->left;
    node_right->left = node;
    node_right->parent = node->parent;
    if(node_right->parent)
        node_right->parent->right = node_right;
    node->parent = node_right;
    node->right = node_right_left;
    if(node_right_left)
        node_right_left->parent = node;
    node->balance_factor = binary_tree_node_balance_factor(node);
    node_right->balance_factor = binary_tree_node_balance_factor(node_right);
    return node_right;
}

struct BinaryTreeNode *binary_tree_node_rotate_right(struct BinaryTreeNode *node)
{
    struct BinaryTreeNode *node_left = node->left;
    struct BinaryTreeNode *node_left_right = node_left->right;
    node_left->right = node;
    node_left->parent = node->parent;
    if(node_left->parent)
        node_left->parent->left = node_left;
    if(node_left_right)
        node_left_right->parent = node;
    node->parent = node_left;
    node->left = node_left_right;
    node->balance_factor = binary_tree_node_balance_factor(node);;
    node_left->balance_factor = binary_tree_node_balance_factor(node_left);
    return node_left;
}

struct BinaryTreeNode *binary_tree_node_rotate_right_left(struct BinaryTreeNode *node)
{
    struct BinaryTreeNode *node_right = node->right;
    struct BinaryTreeNode *node_right_left = node_right->left;
    node_right->left = node_right_left->right;
    node->right = node_right_left->left;
    node_right_left->left = node_right;
    node_right_left->right = node;
    node->balance_factor = binary_tree_node_balance_factor(node);
    node_right_left->balance_factor = binary_tree_node_balance_factor(node_right_left);
    return node_right_left;
}

struct BinaryTreeNode *binary_tree_node_rotate_left_right(struct BinaryTreeNode *node)
{
    struct BinaryTreeNode *node_left = node->left;
    struct BinaryTreeNode *node_left_right = node_left->right;
    node_left->right = node_left_right->left;
    if(node_left_right->left)
        node_left_right->left->parent = node_left;
    node->left = node_left_right->right;
    if(node_left_right->right)
        node_left_right->right->parent = node;
    node_left_right->left = node_left;
    node_left->parent = node_left_right;
    node_left_right->right = node;
    node->parent = node_left_right;
    // if(node->parent)
    //     node_left_right->parent->left = node_left_right;
    node->balance_factor = binary_tree_node_balance_factor(node);
    node_left_right->balance_factor = binary_tree_node_balance_factor(node_left_right);
    return node_left_right;
}

void binary_tree_node_rebalance(struct BinaryTreeNode *node)
{
    if(node->balance_factor == -2 && node->left->balance_factor == -1)
        node = binary_tree_node_rotate_right(node);
    else if(node->balance_factor == 2 && node->right->balance_factor == 1)
        node = binary_tree_node_rotate_left(node);
    else if(node->balance_factor == 2 && node->right->balance_factor == -1)
        node = binary_tree_node_rotate_right_left(node);
    else if(node->balance_factor == -2 && node->left->balance_factor == 1)
        node = binary_tree_node_rotate_left_right(node);
}

void avl_tree_insert(struct BinaryTree *binary_tree, void *data, size_t data_type_size)
{
    if(!binary_tree->size) {
        binary_tree->root = binary_tree_insert(binary_tree, data, data_type_size);
        binary_tree->root->balance_factor = 0;
        binary_tree->root->parent = NULL;
        return;
    }
    struct BinaryTreeNode *node = binary_tree->root;
    struct BinaryTreeNode *node_parent = NULL;
    while(node) {
        if(data == node->data)
            return;
        node_parent = node;
        if(data < node->data)
            node = node->left;
        else
            node = node->right;
    }
    node = binary_tree_insert(binary_tree, data, data_type_size);
    node->balance_factor = 0;
    node->parent = node_parent;
    if(node->data < node_parent->data)
        node_parent->left = node;
    else
        node_parent->right = node;
    while(node_parent) {
        node_parent->balance_factor = binary_tree_node_balance_factor(node_parent);
        if(node_parent->balance_factor == 2 || node_parent->balance_factor == -2)
            binary_tree_node_rebalance(node_parent);
        if(!node_parent->parent)
            binary_tree->root = node_parent;
        node_parent = node_parent->parent;
    }
}

void avl_tree_remove(struct BinaryTree *binary_tree, void *data, size_t data_type_size)
{
    
}