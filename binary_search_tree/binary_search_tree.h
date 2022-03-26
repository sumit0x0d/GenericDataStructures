#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

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

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct BinarySearchTreeNode {
    void *data;
    struct BinarySearchTreeNode *left;
    struct BinarySearchTreeNode *right;
} BinarySearchTreeNode;

typedef struct BinarySearchTree {
    BinarySearchTreeNode *root;
    size_t data_type;
    size_t data_type_size;
    size_t size;
    int (*compare_data)(void *data, void *node_data);
} BinarySearchTree;

BinarySearchTree binary_search_tree_construct(int data_type, int (*compare_data)(void *data, void *node_data));
void binary_search_tree_destruct(BinarySearchTree *BST);

BinarySearchTreeNode *binary_search_tree_search(BinarySearchTree *BST, void *data, size_t data_type_size);
bool binary_search_tree_insert(BinarySearchTree *BST, void *data, size_t data_type_size);
bool binary_search_tree_remove(BinarySearchTree *BST, void *data, size_t data_type_size);

#endif
