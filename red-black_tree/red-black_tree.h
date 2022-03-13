#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <stdlib.h>
#include <string.h>

struct RedBlackTreeNode {
    void *data;
    struct RedBlackTreeNode *left;
    struct RedBlackTreeNode *right;
    struct RedBlackTreeNode *parent;
    enum {RED, BLACK} color;
};

struct RedBlackTree {
    struct RedBlackTreeNode *root;
    size_t data_type_size;
    size_t size;
    struct RedBlackTreeNode *(*search)(struct RedBlackTree *rbt, void *data);
    void (*insert)(struct RedBlackTree *rbt, void *data);
    void (*remove)(struct RedBlackTree *rbt, void *data);
};

struct RedBlackTree red_black_tree_construct(size_t data_type_size);

#endif
