#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct RedBlackTreeNode RedBlackTreeNode;
typedef struct RedBlackTree RedBlackTree;

RedBlackTree *red_black_tree_create(size_t data_size,
    int (*compare)(void *data, void *node_data));

RedBlackTreeNode *red_black_tree_search(RedBlackTree *RBT, void *data);
bool red_black_tree_insert(RedBlackTree *RBT, void *data);
bool red_black_tree_remove(RedBlackTree *RBT, void *data);

#endif
