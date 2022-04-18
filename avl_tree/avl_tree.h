#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct AVLTreeNode AVLTreeNode;
typedef struct AVLTree AVLTree;

AVLTree* avl_tree_create(size_t data_size, int (*compare)(void* data, void* node_data));
void avl_tree_destroy(AVLTree* AVLT);

void* avl_tree_root(AVLTree* AVLT);
size_t avl_tree_size(AVLTree* AVLT);

bool avl_tree_insert(AVLTree* AVLT, void* data);
bool avl_tree_remove(AVLTree* AVLT, void* data);

AVLTreeNode* avl_tree_begin(AVLTree* BST);
AVLTreeNode* avl_tree_search(AVLTree* AVLT, void* data);

void* avl_tree_node_data(AVLTreeNode* node);
AVLTreeNode* avl_tree_node_left(AVLTreeNode* node);
AVLTreeNode* avl_tree_node_right(AVLTreeNode* node);
AVLTreeNode* avl_tree_node_parent(AVLTreeNode* node);
int avl_tree_node_balance_factor(AVLTreeNode* node);

#endif
