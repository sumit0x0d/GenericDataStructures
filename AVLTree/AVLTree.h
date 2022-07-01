#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct AVLTree {
    struct Node* root;
    size_t data_size;
    size_t size;
    int (*compare)(void* data1, void* data2);
} AVLTree;

AVLTree* AVLTree_create(size_t data_size, int (*compare)(void* data1, void* data2));
void AVLTree_destroy(AVLTree* AVLT);

bool AVLTree_insert(AVLTree* AVLT, void* data);
bool AVLTree_remove(AVLTree* AVLT, void* data);

void* AVLTree_search(AVLTree* AVLT, void* data);

void* AVLTree_root(AVLTree* AVLT);

#endif
