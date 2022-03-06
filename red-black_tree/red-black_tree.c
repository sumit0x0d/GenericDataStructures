#include "red-black_tree.h"

struct RedBlackTreeNode *binary_search_tree_search(struct RedBlackTree *rbt, int data)
{
    struct RedBlackTreeNode *node = rbt->root;
    while(node)
        if(data == node->data)
            return node;
        else if(data < node->data)
            node = node->left;
        else
            node = node->right;
    return NULL;
}

void red_black_tree_insert(struct RedBlackTree *rbt, int data)
{
    if(!rbt->size) {
        rbt->root = binary_tree_insert(rbt, data);
        rbt->root->color = BLACK;
        rbt->root->parent = NULL;
        return;
    }
    struct RedBlackTreeNode *node = rbt->root;
    struct RedBlackTreeNode *node_parent = NULL;
    while(node) {
        if(data == node->data)
            return;
        node_parent = node;
        if(data < node->data)
            node = node->left;
        else
            node = node->right;
    }
    node = binary_tree_insert(rbt, data);
    node->color = RED;
    node->parent = node_parent;
    if(node->data < node_parent->data)
        node_parent->left = node;
    else
        node_parent->right = node;
}

void red_black_tree_remove(struct RedBlackTree *rbt, int data)
{

}
