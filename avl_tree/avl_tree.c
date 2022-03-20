#include "avl_tree.h"

AVLTreeNode *avl_tree_search(AVLTree *AVLT, void *data);
bool avl_tree_insert(AVLTree *AVLT, void *data);
bool avl_tree_remove(AVLTree *AVLT, void *data);

AVLTreeNode *search(AVLTree *AVLT, void *data)
{
    AVLTreeNode *node = AVLT->root;
    while(node) {
        int compare = memcmp(data, node->data, AVLT->data_type_size);
        if(compare == 0)
            return node;
        else if(compare < 0)
            node = node->left;
        else
            node = node->right;
    }
    return NULL;
}

int node_balance_factor(AVLTreeNode *node)
{
    size_t node_left_height = 0;
    size_t node_right_height = 0;

    if(node->left)
        node_left_height = node_height(node->left);
    if(node->right)
        node_right_height = node_height(node->right);
    
    return (int)(node_right_height - node_left_height);
}

AVLTreeNode *node_rotate_left(AVLTreeNode *node)
{
    AVLTreeNode *node_right = node->right;
    AVLTreeNode *node_right_left = node_right->left;

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

AVLTreeNode *node_rotate_right(AVLTreeNode *node)
{
    AVLTreeNode *node_left = node->left;
    AVLTreeNode *node_left_right = node_left->right;

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

AVLTreeNode *_node_rotate_right_left(AVLTreeNode *node)
{
    AVLTreeNode *node_right = node->right;
    AVLTreeNode *node_right_left = node_right->left;
    
    node_right->left = node_right_left->right;
    node->right = node_right_left->left;
    node_right_left->left = node_right;
    node_right_left->right = node;
    
    node->balance_factor = node_balance_factor(node);
    node_right_left->balance_factor = node_balance_factor(node_right_left);
    
    return node_right_left;
}

AVLTreeNode *node_rotate_left_right(AVLTreeNode *node)
{
    AVLTreeNode *node_left = node->left;
    AVLTreeNode *node_left_right = node_left->right;

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

void node_rebalance(AVLTreeNode *node)
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

AVLTreeNode *node_construct(void *data, size_t data_type_size)
{
    AVLTreeNode *node = malloc(sizeof (AVLTreeNode));
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
    node->balance_factor = 0;

    return node;
}

bool avl_tree_insert(AVLTree *AVLT, void *data)
{
    if(!AVLT->size) {
        AVLT->root = node_construct(data, AVLT->data_type_size);
        if(!AVLT->root) return false;
        
        AVLT->root->parent = NULL;

        AVLT->size = AVLT->size + 1;

        return true;
    }
    
    AVLTreeNode *node = AVLT->root;
    AVLTreeNode *node_parent = NULL;
    
    while(node) {
        if(data == node->data)
            return;
        node_parent = node;
        if(data < node->data)
            node = node->left;
        else
            node = node->right;
    }

    node = node_construct(data, AVLT->data_type_size);
    if(!node) return false;

    node->parent = node_parent;

    AVLT->size = AVLT->size + 1;

    if(node->data < node_parent->data)
        node_parent->left = node;
    else
        node_parent->right = node;

    while(node_parent) {
        node_parent->balance_factor = node_balance_factor(node_parent);
        if(node_parent->balance_factor == 2 || node_parent->balance_factor == -2)
            node_rebalance(node_parent);
        if(!node_parent->parent)
            AVLT->root = node_parent;
        node_parent = node_parent->parent;
    }

    return true;
}

bool avl_tree_remove(AVLTree *AVLT, void *data)
{
    
}
