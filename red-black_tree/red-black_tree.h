#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <stdlib.h>
#include <string.h>

typedef struct RedBlackTreeNode {
    void *data;
    RedBlackTreeNode *left;
    RedBlackTreeNode *right;
    RedBlackTreeNode *parent;
    enum {RED, BLACK} color;
} RedBlackTreeNode;

typedef struct RedBlackTree {
    RedBlackTreeNode *root;
    size_t data_type_size;
    size_t size;
    RedBlackTreeNode *(*search)(RedBlackTree *RBT, void *data);
    void (*insert)(RedBlackTree *RBT, void *data);
    void (*remove)(RedBlackTree *RBT, void *data);
} RedBlackTree;

RedBlackTree red_black_tree_construct(size_t data_type_size);

#endif
