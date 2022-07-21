#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <stdbool.h>
#include <stddef.h>

typedef struct AVLTree AVLTree;

AVLTree* AVLTree_Create(size_t data_size, int (*compare_function)(void* data1, void* data2));
void AVLTree_Destroy(AVLTree* AVLT);
size_t AVLTree_Size(AVLTree* AVLT);
bool AVLTree_Empty(AVLTree* AVLT);
void* AVLTree_Search(AVLTree* AVLT, void* data);
void* AVLTree_Root(AVLTree* AVLT);
bool AVLTree_Insert(AVLTree* AVLT, void* data);
bool AVLTree_Remove(AVLTree* AVLT, void* data);
void AVLTree_TraversePreorder(AVLTree* AVLT, void (*function)(void* data));
void AVLTree_TraverseInorder(AVLTree* AVLT, void (*function)(void* data));
void AVLTree_TraversePostorder(AVLTree* AVLT, void (*function)(void* data));
void AVLTree_TraverseLevelorder(AVLTree* AVLT, void (*function)(void* data));

#endif
