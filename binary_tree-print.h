#include "data_structures.h"

typedef union BinaryTree {
    BinarySearchTree BST;
    AVLTree AVLT;
    RedBlackTree RBT;
} BinaryTree;
