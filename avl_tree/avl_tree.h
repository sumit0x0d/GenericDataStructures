#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct AVLTreeNode {
    void *data;
    struct AVLTreeNode *left;
    struct AVLTreeNode *right;
    struct AVLTreeNode *parent;
    int balance_factor;
} AVLTreeNode;

typedef struct AVLTree {
    AVLTreeNode *root;
    size_t data_type;
    size_t data_type_size;
    size_t size;
    int (*compare_data)(void *data, void *node_data);
} AVLTree;

AVLTree avl_tree_create(int data_type, size_t data_type_size, int (*compare_data)(void *data, void *node_data));
void avl_tree_distroy(AVLTree *AVLT);

AVLTreeNode *avl_tree_search(AVLTree *AVLT, void *data);
bool avl_tree_insert(AVLTree *AVLT, void *data);
bool avl_tree_remove(AVLTree *AVLT, void *data);

#endif
