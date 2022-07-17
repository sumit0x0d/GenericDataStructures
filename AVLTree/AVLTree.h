#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <stdbool.h>
#include <stddef.h>

typedef struct AVLTree AVLTree;

AVLTree* AVLTreeCreate(size_t data_size, int (*compare_function)(void* data1, void* data2));
void AVLTreeDestroy(AVLTree* AVLT);
size_t AVLTreeSize(AVLTree* AVLT);
bool AVLTreeEmpty(AVLTree* AVLT);
void* AVLTreeSearch(AVLTree* AVLT, void* data);
void* AVLTree_root(AVLTree* AVLT);
bool AVLTreeInsert(AVLTree* AVLT, void* data);
bool AVLTreeRemove(AVLTree* AVLT, void* data);
void AVLTreeTraverse_preorder(AVLTree* AVLT, void (*function)(void* data));
void AVLTreeTraverse_inorder(AVLTree* AVLT, void (*function)(void* data));
void AVLTreeTraverse_postorder(AVLTree* AVLT, void (*function)(void* data));
void AVLTreeTraverse_levelorder(AVLTree* AVLT, void (*function)(void* data));

#endif
