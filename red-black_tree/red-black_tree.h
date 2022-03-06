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
    struct RedBlackTreeNode *root;
    size_t size;
    struct RedBlackTreeNode *(*search)(struct RedBlackTree *rbt, void *data, size_t data_type_size);
    void (*insert)(struct RedBlackTree *rbt, void *data, size_t data_type_size);
    void (*remove)(struct RedBlackTree *rbt, void *data, size_t data_type_size);
};

struct RedBlackTree red_black_tree_construct();

#endif
