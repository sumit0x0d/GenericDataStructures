#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <stdlib.h>
#include <string.h>

typedef struct RedBlackTreeNode {
    void *data;
    struct RedBlackTreeNode *left;
    struct RedBlackTreeNode *right;
    struct RedBlackTreeNode *parent;
    enum {RED, BLACK} color;
} RedBlackTreeNode;

typedef struct RedBlackTree {
    RedBlackTreeNode *root;
    size_t data_type_size;
    size_t size;
} RedBlackTree;

RedBlackTree red_black_tree_construct(size_t data_type_size);
RedBlackTreeNode *red_black_tree_search(RedBlackTree *RBT, void *data);
void red_black_tree_insert(RedBlackTree *RBT, void *data);
void red_black_tree_remove(RedBlackTree *RBT, void *data);

#endif
