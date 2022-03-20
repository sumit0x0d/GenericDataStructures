#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct AVLTreeNode {
    void *data;
    AVLTreeNode *left;
    AVLTreeNode *right;
    AVLTreeNode *parent;
    int balance_factor;
} AVLTreeNode;

typedef struct AVLTree {
    AVLTreeNode *root;
    size_t data_type_size;
    size_t size;
} AVLTree;

AVLTree avl_tree_construct(size_t data_type_size);
void avl_tree_destruct(AVLTree *AVLT);
AVLTreeNode *binary_search_tree_search(AVLTree *AVLT, void *data);
bool avl_tree_insert(AVLTree *AVLT, void *data);
bool avl_tree_remove(AVLTree *AVLT, void *data);

#endif
