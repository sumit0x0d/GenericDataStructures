#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <stdbool.h>
#include <stddef.h>

typedef struct RedBlackTree RedBlackTree;

RedBlackTree* RedBlackTreeCreate(size_t data_size, int (*compare_function)(void* data1, void* data2));
void RedBlackTreeDestroy(RedBlackTree* RBT);
size_t RedBlackTreeSize(RedBlackTree* RBT);
bool RedBlackTreeEmpty(RedBlackTree* RBT);
void* RedBlackTree_root(RedBlackTree* RBT);
void* RedBlackTreeSearch(RedBlackTree* RBT, void* data);
bool RedBlackTreeInsert(RedBlackTree* RBT, void* data);
bool RedBlackTreeRemove(RedBlackTree* RBT, void* data);
void RedBlackTreeTraverse_preorder(RedBlackTree* RBT, void (*function)(void* data));
void RedBlackTreeTraverse_inorder(RedBlackTree* RBT, void (*function)(void* data));
void RedBlackTreeTraverse_postorder(RedBlackTree* RBT, void (*function)(void* data));
void RedBlackTreeTraverse_levelorder(RedBlackTree* RBT, void (*function)(void* data));

#endif
