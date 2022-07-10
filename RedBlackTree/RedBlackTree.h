#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <stdbool.h>
#include <stddef.h>

typedef struct RedBlackTree RedBlackTree;

RedBlackTree* RedBlackTree_create(size_t data_size, int (*compare)(void* data1, void* data2));
void RedBlackTree_destroy(RedBlackTree* RBT);
size_t RedBlackTree_size(RedBlackTree* RBT);
bool RedBlackTree_empty(RedBlackTree* RBT);
void* RedBlackTree_root(RedBlackTree* RBT);
void* RedBlackTree_search(RedBlackTree* RBT, void* data);
bool RedBlackTree_insert(RedBlackTree* RBT, void* data);
bool RedBlackTree_remove(RedBlackTree* RBT, void* data);
void RedBlackTree_traverse_preorder(RedBlackTree* RBT, void (*function)(void* data));
void RedBlackTree_traverse_inorder(RedBlackTree* RBT, void (*function)(void* data));
void RedBlackTree_traverse_postorder(RedBlackTree* RBT, void (*function)(void* data));
void RedBlackTree_traverse_levelorder(RedBlackTree* RBT, void (*function)(void* data));

#endif
