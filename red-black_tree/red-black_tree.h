#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <stdlib.h>

struct RedBlackTreeNode {
    void *data;
    size_t data_type_size;
    struct RedBlackTreeNode *left;
    struct RedBlackTreeNode *right;
    struct RedBlackTreeNode *parent;
    enum {RED, BLACK} color;
};

struct RedBlackTree {
    struct RedBlackTree *root;
    size_t size;
    struct RedBlackTreeNode *(*search)(struct RedBlackTree *binary_search_tree, void *data, size_t data_type_size);
    struct RedBlackTree *(*insert)(struct RedBlackTree *avl_tree, void *data, size_t data_type_size);
    void (*remove)(struct RedBlackTree *avl_tree, void *data, size_t data_type_size);
};

struct BinaryTreeNode *avl_tree_search(struct RedBlackTree *avl_tree, void *data, size_t data_type_size);
void avl_tree_insert(struct RedBlackTree *avl_tree, void *data, size_t data_type_size);
void avl_tree_remove(struct RedBlackTree *avl_tree, void *data, size_t data_type_size);

#endif
