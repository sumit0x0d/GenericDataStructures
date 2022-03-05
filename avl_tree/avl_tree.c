#include "avl_tree.h"

struct AVLTreeNode *search(struct AVLTree *tree, void *data, size_t data_type_size);
void insert(struct AVLTree *tree, void *data, size_t data_type_size);
void remove(struct AVLTree *tree, void *data, size_t data_type_size);

struct AVLTreeNode *search(struct AVLTree *tree, void *data, size_t data_type_size)
{
    struct AVLTreeNode *node = tree->root;
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

int node_balance_factor(struct AVLTreeNode *node)
{
    size_t node_left_height = 0;
    size_t node_right_height = 0;
    if(node->left)
        node_left_height = node_height(node->left);
    if(node->right)
        node_right_height = node_height(node->right);
    return (int)(node_right_height - node_left_height);
}

struct AVLTreeNode *node_rotate_left(struct AVLTreeNode *node)
{
    struct AVLTreeNode *node_right = node->right;
    struct AVLTreeNode *node_right_left = node_right->left;
    node_right->left = node;
    node_right->parent = node->parent;
    if(node_right->parent)
        node_right->parent->right = node_right;
    node->parent = node_right;
    node->right = node_right_left;
    if(node_right_left)
        node_right_left->parent = node;
    node->balance_factor = node_balance_factor(node);
    node_right->balance_factor = node_balance_factor(node_right);
    return node_right;
}

struct AVLTreeNode *node_rotate_right(struct AVLTreeNode *node)
{
    struct AVLTreeNode *node_left = node->left;
    struct AVLTreeNode *node_left_right = node_left->right;
    node_left->right = node;
    node_left->parent = node->parent;
    if(node_left->parent)
        node_left->parent->left = node_left;
    if(node_left_right)
        node_left_right->parent = node;
    node->parent = node_left;
    node->left = node_left_right;
    node->balance_factor = node_balance_factor(node);;
    node_left->balance_factor = node_balance_factor(node_left);
    return node_left;
}

struct AVLTreeNode *_node_rotate_right_left(struct AVLTreeNode *node)
{
    struct AVLTreeNode *node_right = node->right;
    struct AVLTreeNode *node_right_left = node_right->left;
    node_right->left = node_right_left->right;
    node->right = node_right_left->left;
    node_right_left->left = node_right;
    node_right_left->right = node;
    node->balance_factor = node_balance_factor(node);
    node_right_left->balance_factor = node_balance_factor(node_right_left);
    return node_right_left;
}

struct AVLTreeNode *node_rotate_left_right(struct AVLTreeNode *node)
{
    struct AVLTreeNode *node_left = node->left;
    struct AVLTreeNode *node_left_right = node_left->right;

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
    node->balance_factor = node_balance_factor(node);
    node_left_right->balance_factor = node_balance_factor(node_left_right);
    return node_left_right;
}

void node_rebalance(struct AVLTreeNode *node)
{
    if(node->balance_factor == -2 && node->left->balance_factor == -1)
        node = node_rotate_right(node);
    else if(node->balance_factor == 2 && node->right->balance_factor == 1)
        node = node_rotate_left(node);
    else if(node->balance_factor == 2 && node->right->balance_factor == -1)
        node = node_rotate_right_left(node);
    else if(node->balance_factor == -2 && node->left->balance_factor == 1)
        node = node_rotate_left_right(node);
}

struct AVLTreeNode *node_construct(void *data, size_t data_type_size)
{
    struct AVLTreeNode *node = malloc(sizeof (struct AVLTreeNode));
    if(!node) return NULL;

    node->data = malloc(data_type_size);
    if(!node->data) {
        free(node);
        node = NULL;
        return NULL;
    }
    
    memcpy(node->data, data, data_type_size);

    node->data_type_size = data_type_size;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    node->balance_factor = 0;

    return node;
}

void insert(struct AVLTree *tree, void *data, size_t data_type_size)
{
    if(!tree->size) {
        tree->root = node_construct(data, data_type_size);
        ++tree->size;
        return;
    }
    
    struct AVLTreeNode *node = tree->root;
    struct AVLTreeNode *node_parent = NULL;
    
    while(node) {
        if(data == node->data)
            return;
        node_parent = node;
        if(data < node->data)
            node = node->left;
        else
            node = node->right;
    }

    node = node_construct(data, data_type_size);
    ++tree->size;

    if(node->data < node_parent->data)
        node_parent->left = node;
    else
        node_parent->right = node;

    while(node_parent) {
        node_parent->balance_factor = node_balance_factor(node_parent);
        if(node_parent->balance_factor == 2 || node_parent->balance_factor == -2)
            node_rebalance(node_parent);
        if(!node_parent->parent)
            tree->root = node_parent;
        node_parent = node_parent->parent;
    }
}

void remove(struct AVLTree *tree, void *data, size_t data_type_size)
{
    
}