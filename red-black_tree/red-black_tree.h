#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <stdlib.h>
#include <string.h>

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
    void (*insert)(struct RedBlackTree *avl_tree, void *data, size_t data_type_size);
    void (*remove)(struct RedBlackTree *avl_tree, void *data, size_t data_type_size);
};

struct RedBlackTree red_black_tree_construct();

#endif
