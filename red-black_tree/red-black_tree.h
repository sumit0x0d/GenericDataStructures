#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <stdbool.h>
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
    size_t data_size;
    size_t size;
    int (*compare_data)(void *data, void *node_data);
} RedBlackTree;

RedBlackTree red_black_tree_create(size_t data_size, int (*compare_data)(void *data, void *node_data));

RedBlackTreeNode *red_black_tree_search(RedBlackTree *RBT, void *data);
bool red_black_tree_insert(RedBlackTree *RBT, void *data);
bool red_black_tree_remove(RedBlackTree *RBT, void *data);

#endif
