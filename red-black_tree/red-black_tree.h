#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct RedBlackTreeNode RedBlackTreeNode;
typedef struct RedBlackTree RedBlackTree;

RedBlackTree* red_black_tree_create(size_t data_size,
    int (*compare)(void* data, void* node_data));

void* red_black_tree_root(RedBlackTree* RedBlackT);
size_t red_black_tree_size(RedBlackTree* RedBlackT);

bool red_black_tree_insert(RedBlackTree* RBT, void* data);
bool red_black_tree_remove(RedBlackTree* RBT, void* data);

RedBlackTreeNode* red_black_tree_begin(RedBlackTree* RBT);
RedBlackTreeNode* red_black_tree_search(RedBlackTree* RBT, void* data);

void* red_black_tree_node_data(RedBlackTreeNode* node);
RedBlackTreeNode* red_black_tree_node_left(RedBlackTreeNode* node);
RedBlackTreeNode* red_black_tree_node_right(RedBlackTreeNode* node);
RedBlackTreeNode* red_black_tree_node_parent(RedBlackTreeNode* node);
int red_black_tree_node_color(RedBlackTreeNode* node);

#endif
