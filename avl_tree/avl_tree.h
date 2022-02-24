#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <stddef.h>

struct AVLTreeNode {
    void *data;
    size_t data_type_size;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
    struct BinaryTreeNode *parent;
    int balance_factor;
};

struct AVLTree {
    struct AVLTree *root;
    size_t size;
    struct AVLTreeNode *(*search)(struct AVLTree *binary_search_tree, void *data, size_t data_type_size);
    struct AVLTree *(*insert)(struct AVLTree *avl_tree, void *data, size_t data_type_size);
    void (*remove)(struct AVLTree *avl_tree, void *data, size_t data_type_size);
};

struct AVLTreeNode *avl_tree_search(struct AVLTree *avl_tree, void *data, size_t data_type_size);
void avl_tree_insert(struct AVLTree *avl_tree, void *data, size_t data_type_size);
void avl_tree_remove(struct AVLTree *avl_tree, void *data, size_t data_type_size);

#endif
