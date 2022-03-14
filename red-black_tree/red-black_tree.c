#include "red-black_tree.h"

struct RedBlackTreeNode *binary_search_tree_search(struct RedBlackTree *rbt, void *data)
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

struct RedBlackTreeNode *node_construct(void *data, size_t data_type_size)
{
    struct RedBlackTreeNode *node = malloc(sizeof (struct RedBlackTreeNode));
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

void red_black_tree_insert(struct RedBlackTree *rbt, void *data)
{
    if(!rbt->size) {
        rbt->root = node_construct(data, rbt->data_type_size);
        if(!rbt->root) return;

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
    node = node_construct(data, rbt->data_type_size);
    if(!node) return;

    node->parent = node_parent;
    node->color = RED;
    
    if(node->data < node_parent->data)
        node_parent->left = node;
    else
        node_parent->right = node;
}

void red_black_tree_remove(struct RedBlackTree *rbt, int data)
{

}
