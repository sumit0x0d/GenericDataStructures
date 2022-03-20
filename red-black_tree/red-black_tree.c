#include "red-black_tree.h"

RedBlackTreeNode *binary_search_tree_search(RedBlackTree *RBT, void *data)
{
    RedBlackTreeNode *node = RBT->root;
    while(node)
        if(data == node->data)
            return node;
        else if(data < node->data)
            node = node->left;
        else
            node = node->right;
    return NULL;
}

RedBlackTreeNode *node_construct(void *data, size_t data_type_size)
{
    RedBlackTreeNode *node = malloc(sizeof (RedBlackTreeNode));
    if(!node) return NULL;

    node->data = malloc(data_type_size);
    if(!node->data) {
        free(node);
        node = NULL;
        return NULL;
    }

    memcpy(node->data, data, data_type_size);

    node->left = NULL;
    node->right = NULL;

    return node;
}

void red_black_tree_insert(RedBlackTree *RBT, void *data)
{
    if(!RBT->size) {
        RBT->root = node_construct(data, RBT->data_type_size);
        if(!RBT->root) return;

        RBT->root->parent = NULL;
        RBT->root->color = BLACK;
        
        return;
    }

    RedBlackTreeNode *node = RBT->root;
    RedBlackTreeNode *node_parent = NULL;

    while(node) {
        if(data == node->data)
            return;
        node_parent = node;
        if(data < node->data)
            node = node->left;
        else
            node = node->right;
    }

    node = node_construct(data, RBT->data_type_size);
    if(!node) return;

    node->parent = node_parent;
    node->color = RED;
    
    if(node->data < node_parent->data)
        node_parent->left = node;
    else
        node_parent->right = node;
}

void red_black_tree_remove(RedBlackTree *RBT, int data)
{

}
