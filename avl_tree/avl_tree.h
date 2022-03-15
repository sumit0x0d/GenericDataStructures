#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <stdlib.h>
#include <string.h>

struct AVLTreeNode {
    void *data;
    struct AVLTreeNode *left;
    struct AVLTreeNode *right;
    struct AVLTreeNode *parent;
    int balance_factor;
};

struct AVLTree {
    struct AVLTreeNode *root;
    size_t data_type_size;
    size_t size;
    struct AVLTreeNode *(*search)(struct AVLTree *AVLT, void *data);
    void (*insert)(struct AVLTree *AVLT, void *data);
    void (*remove)(struct AVLTree *AVLT, void *data);
};

struct AVLTree avl_tree_construct(size_t data_type_size);
void avl_tree_destruct(struct AVLTree *AVLT);

#endif
