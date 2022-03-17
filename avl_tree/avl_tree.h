#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <stdbool.h>
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
};

struct AVLTree avl_tree_construct(size_t data_type_size);
void avl_tree_destruct(struct AVLTree *AVLT);
struct AVLTreeNode *binary_search_tree_search(struct AVLTree *AVLT, void *data);
bool avl_tree_insert(struct AVLTree *AVLT, void *data);
bool avl_tree_remove(struct AVLTree *AVLT, void *data);

#endif
