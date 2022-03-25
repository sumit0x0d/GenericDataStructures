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
    UNION
};

#endif

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct AVLTreeNode {
    void *data;
    size_t data_type_size;
    struct AVLTreeNode *left;
    struct AVLTreeNode *right;
    struct AVLTreeNode *parent;
    int balance_factor;
} AVLTreeNode;

typedef struct AVLTree {
    AVLTreeNode *root;
    size_t size;
} AVLTree;

AVLTree avl_tree_construct();
void avl_tree_destruct(AVLTree *AVLT);

AVLTreeNode *avl_tree_search(AVLTree *AVLT, void *data, size_t data_type_size);
bool avl_tree_insert(AVLTree *AVLT, void *data, size_t data_type_size);
bool avl_tree_remove(AVLTree *AVLT, void *data, size_t data_type_size);

#endif
