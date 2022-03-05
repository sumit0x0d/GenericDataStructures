#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <stdlib.h>
#include <string.h>

struct AVLTreeNode {
    void *data;
    size_t data_type_size;
    struct AVLTreeNode *left;
    struct AVLTreeNode *right;
    struct AVLTreeNode *parent;
    int balance_factor;
};

struct AVLTree {
    struct AVLTreeNode *root;
    size_t size;
    struct AVLTreeNode *(*search)(struct AVLTree *tree, void *data, size_t data_type_size);
    void (*insert)(struct AVLTree *tree, void *data, size_t data_type_size);
    void (*remove)(struct AVLTree *tree, void *data, size_t data_type_size);
};

struct AVLTree avl_tree_construct();
void avl_tree_destruct(struct AVLTree *tree);

#endif
