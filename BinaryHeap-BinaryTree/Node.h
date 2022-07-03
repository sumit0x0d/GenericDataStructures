#ifndef NODE_H
#define NODE_H

#include "BinaryHeap-BinaryTree.h"

typedef struct Node {
    void* data;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
} Node;

static Node* Node_create(size_t data_size)
{
    Node* N = (Node*)malloc(sizeof (Node));
    if(!N) {
        return NULL;
    }
    N->data = malloc(data_size);
    if(!N->data) {
        free(N);
        return NULL;
    }
    N->left = NULL;
    N->right = NULL;
    return N;
}

#endif