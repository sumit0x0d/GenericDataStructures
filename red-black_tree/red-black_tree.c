#include "red-black_tree.h"

struct BinaryTreeNode *binary_search_tree_search(struct BinaryTree *binary_tree, int data)
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

void red_black_tree_insert(struct BinaryTree *binary_tree, int data)
{
    if(!binary_tree->size) {
        binary_tree->root = binary_tree_insert(binary_tree, data);
        binary_tree->root->color = BLACK;
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
    node = binary_tree_insert(binary_tree, data);
    node->color = RED;
    node->parent = node_parent;
    if(node->data < node_parent->data)
        node_parent->left = node;
    else
        node_parent->right = node;
}

void red_black_tree_remove(struct BinaryTree *binary_tree, int data)
{

}
