#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct AVLTreeNode AVLTreeNode;
typedef struct AVLTree AVLTree;

AVLTree* avl_tree_create(size_t data_size, int (*compare)(void* data, void* node_data));
void avl_tree_destroy(AVLTree* AVLT);

AVLTreeNode* avl_tree_search(AVLTree* AVLT, void* data);
bool avl_tree_insert(AVLTree* AVLT, void* data);
bool avl_tree_remove(AVLTree* AVLT, void* data);

#endif
