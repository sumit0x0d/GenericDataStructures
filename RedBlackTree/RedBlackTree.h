#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <stdbool.h>
#include <stddef.h>

typedef struct RedBlackTree RedBlackTree;

RedBlackTree* RedBlackTree_Create(size_t data_size, int (*compare_function)(void* data1, void* data2));
void RedBlackTree_Destroy(RedBlackTree* RBT);
size_t RedBlackTree_Size(RedBlackTree* RBT);
bool RedBlackTree_Empty(RedBlackTree* RBT);
void* RedBlackTree_Root(RedBlackTree* RBT);
void* RedBlackTree_Search(RedBlackTree* RBT, void* data);
bool RedBlackTree_Insert(RedBlackTree* RBT, void* data);
bool RedBlackTree_Remove(RedBlackTree* RBT, void* data);
void RedBlackTree_TraversePreorder(RedBlackTree* RBT, void (*function)(void* data));
void RedBlackTree_TraverseInorder(RedBlackTree* RBT, void (*function)(void* data));
void RedBlackTree_TraversePostorder(RedBlackTree* RBT, void (*function)(void* data));
void RedBlackTree_TraverseLevelorder(RedBlackTree* RBT, void (*function)(void* data));

#endif
