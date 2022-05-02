#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct AVLTreeNode {
    void* data;
    struct AVLTreeNode* left;
    struct AVLTreeNode* right;
    struct AVLTreeNode* parent;
    int balance_factor;
} AVLTreeNode;

typedef struct AVLTree {
    AVLTreeNode* root;
    size_t data_size;
    size_t size;
    int (*compare)(void* data, void* node_data);
} AVLTree;

AVLTree* AVLTree_create(size_t data_size, int (*compare)(void* data, void* node_data));
void AVLTree_destroy(AVLTree* AVLT);

bool AVLTree_insert(AVLTree* AVLT, void* data);
bool AVLTree_remove(AVLTree* AVLT, void* data);

AVLTreeNode* AVLTree_search(AVLTree* AVLT, void* data);

#endif
