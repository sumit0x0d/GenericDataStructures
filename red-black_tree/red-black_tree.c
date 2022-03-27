#include "red-black_tree.h"

RedBlackTree red_black_tree_create(int data_type, size_t data_type_size, int (*compare_data)(void *data, void *node_data));
void red_black_tree_distroy(RedBlackTree *RBT);

size_t red_black_tree_size(RedBlackTree *RBT);

RedBlackTreeNode *red_black_tree_search(RedBlackTree *RBT, void *data);
bool red_black_tree_insert(RedBlackTree *RBT, void *data);
bool red_black_tree_remove(RedBlackTree *RBT, void *data);


RedBlackTree red_black_tree_create(int data_type, size_t data_type_size, int (*compare_data)(void *data, void *node_data))
{
    RedBlackTree RBT;

    RBT.root = NULL;
    RBT.size = 0;
    RBT.data_type = data_type;
    RBT.data_type_size = data_type_size;

    RBT.compare_data = compare_data;

    return RBT;
}

// RedBlackTreeNode *red_black_tree_search(RedBlackTree *RBT, void *data, size_t data_type_size)
// {
//     RedBlackTreeNode *node = RBT->root;
//     while(node)
//         if(data == node->data)
//             return node;
//         else if(data < node->data)
//             node = node->left;
//         else
//             node = node->right;
//     return NULL;
// }

static RedBlackTreeNode *node_create(size_t data_type_size)
{
    RedBlackTreeNode *node = malloc(sizeof (RedBlackTreeNode));
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

bool red_black_tree_insert(RedBlackTree *RBT, void *data)
{
    if(!RBT->size) {
        RBT->root = node_create(RBT->data_type_size);
        if(!RBT->root) return false;

        memcpy(RBT->root->data, data, RBT->data_type_size);

        RBT->root->parent = NULL;
        RBT->root->color = BLACK;
        
        return false;
    }

    RedBlackTreeNode *node = RBT->root;
    RedBlackTreeNode *node_parent = NULL;
    int compare;

    while(node) {
        compare = RBT->compare_data(data, node->data);
        if(compare == 0)
            return node;
        else if(compare < 0)
            node = node->left;
        else
            node = node->right;
    }

    node = node_create(RBT->data_type_size);
    if(!node) return false;

    memcpy(node->data, data, RBT->data_type_size);

    node->parent = node_parent;
    node->color = RED;
    
    if(node->data < node_parent->data)
        node_parent->left = node;
    else
        node_parent->right = node;

    return true;
}

// void red_black_tree_remove(RedBlackTree *RBT, int data)
// {

// }
