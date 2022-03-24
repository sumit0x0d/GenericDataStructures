#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct AVLTreeNode {
    void *data;
    size_t data_type_size;
    struct AVLTreeNode *left;
    struct AVLTreeNode *right;
    struct AVLTreeNode *parent;
    int balance_factor;
} AVLTreeNode;

typedef struct AVLTree {
    AVLTreeNode *root;
    size_t size;
} AVLTree;

AVLTree avl_tree_construct();
void avl_tree_destruct(AVLTree *AVLT);

AVLTreeNode *avl_tree_search(AVLTree *AVLT, void *data, size_t data_type_size);
bool avl_tree_insert(AVLTree *AVLT, void *data, size_t data_type_size);
bool avl_tree_remove(AVLTree *AVLT, void *data, size_t data_type_size);

#endif
