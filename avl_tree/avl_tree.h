#ifndef AVL_TREE_H
#define AVL_TREE_H

#ifndef DATA_TYPE
#define DATA_TYPE

enum {
    BOOL,
    CHAR,
    UNSIGNED_CHAR,
    SHORT,
    UNSIGNED_SHORT,
    INT,
    UNSIGNED_INT,
    FLOAT,
    LONG,
    UNSIGNED_LONG,
    DOUBLE,
    LONG_LONG,
    UNSIGNED_LONG_LONG,
    LONG_DOUBLE,
    STRUCT,
    UNION,
    ARRAY,
    POINTER
};

#endif

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct AVLTreeNode {
    void *data;
    struct AVLTreeNode *left;
    struct AVLTreeNode *right;
    struct AVLTreeNode *parent;
    int balance_factor;
} AVLTreeNode;

typedef struct AVLTree {
    AVLTreeNode *root;
    size_t data_type;
    size_t data_type_size;
    size_t size;
    int (*compare_data)(void *data, void *node_data);
} AVLTree;

AVLTree avl_tree_create(int data_type, size_t data_type_size, int (*compare_data)(void *data, void *node_data));
void avl_tree_distroy(AVLTree *AVLT);

AVLTreeNode *avl_tree_search(AVLTree *AVLT, void *data);
bool avl_tree_insert(AVLTree *AVLT, void *data);
bool avl_tree_remove(AVLTree *AVLT, void *data);

#endif
