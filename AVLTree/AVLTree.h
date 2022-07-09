#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <stdbool.h>
#include <stddef.h>

typedef struct AVLTree AVLTree;

AVLTree* AVLTree_create(size_t data_size, int (*compare)(void* data1, void* data2));
void AVLTree_destroy(AVLTree* AVLT);
size_t AVLTree_size(AVLTree* AVLT);
bool AVLTree_empty(AVLTree* AVLT);
void* AVLTree_search(AVLTree* AVLT, void* data);
void* AVLTree_root(AVLTree* AVLT);
bool AVLTree_insert(AVLTree* AVLT, void* data);
bool AVLTree_remove(AVLTree* AVLT, void* data);

#endif
