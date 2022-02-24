#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <stddef.h>

struct AVLTreeNode {
    void *data;
    size_t data_type_size;
    struct AVLTreeNode *left;
    struct AVLTreeNode *right;
    struct AVLTreeNode *parent;
    int balance_factor;
};

struct AVLTree {
    struct AVLTree *root;
    size_t size;
    struct AVLTreeNode *(*search)(struct AVLTree *avl_tree, void *data, size_t data_type_size);
    struct AVLTree *(*insert)(struct AVLTree *avl_tree, void *data, size_t data_type_size);
    void (*remove)(struct AVLTree *avl_tree, void *data, size_t data_type_size);
};

struct AVLTree binary_search_tree_construct();
void binary_search_tree_distruct(struct AVLTree *avl_tree);

#endif
