#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

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

typedef struct RedBlackTreeNode {
    void *data;
    struct RedBlackTreeNode *left;
    struct RedBlackTreeNode *right;
    struct RedBlackTreeNode *parent;
    enum {RED, BLACK} color;
} RedBlackTreeNode;

typedef struct RedBlackTree {
    RedBlackTreeNode *root;
    int data_type;
    size_t data_type_size;
    size_t size;
    int (*compare_data)(void *data, void *node_data);
} RedBlackTree;

RedBlackTree red_black_tree_create(int data_type, size_t data_type_size, int (*compare_data)(void *data, void *node_data));

RedBlackTreeNode *red_black_tree_search(RedBlackTree *RBT, void *data);
bool red_black_tree_insert(RedBlackTree *RBT, void *data);
bool red_black_tree_remove(RedBlackTree *RBT, void *data);

#endif
