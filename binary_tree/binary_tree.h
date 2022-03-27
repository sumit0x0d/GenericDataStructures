#ifndef BINARY_TREE_H
#define BINARY_TREE_H

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
    STRING,
    STRUCT
};

#endif

#include <stdlib.h>
#include <string.h>

typedef struct BinaryTreeNode {
    void *data;
    size_t data_type_size;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
} BinaryTreeNode;

typedef struct BinaryTree {
    BinaryTreeNode *root;
    size_t size;
} BinaryTree;

BinaryTree binary_tree_create();
void binary_tree_distroy(BinaryTree *bt);

BinaryTreeNode *binary_tree_insert(BinaryTree *bt, void *data, size_t data_type_size);

#endif
