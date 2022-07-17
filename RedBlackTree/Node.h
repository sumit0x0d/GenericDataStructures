#ifndef NODE_H
#define NODE_H

#include <stdlib.h>

typedef struct Node {
    void* data;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
    // int color; // RED = 0 BLACK = 1
    enum {RED, BLACK} color;
} Node;

static Node* NodeCreate(size_t data_size)
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

static Node* Node_rotate_right(Node* N, Node* NL)
{
    N->left = NL->right;
    if(N->left) {
        N->left->parent = N;
    }
    NL->parent = N->parent;
    if(NL->parent) {
        if(NL->parent->left == N) {
            NL->parent->left = NL;
        }
        else {
            NL->parent->right = NL;
        }
    }
    N->parent = NL;
    NL->right = N;
    return NL;
}

static Node* Node_rotate_left_right(Node* N, Node* NL, Node* NLR)
{
    NL->right = NLR->left;
    if(NL->right) {
        NL->right->parent = NL;
    }
    N->left = NLR->right;
    if(N->left) {
        N->left->parent = N;
    }
    NLR->left = NL;
    NL->parent = NLR;
    NLR->parent = N->parent;
    if(NLR->parent) {
        if(NLR->parent->left == N) {
            NLR->parent->left = NLR;
        }
        else {
            NLR->parent->right = NLR;
        }
    }
    N->parent = NLR;
    NLR->right = N;
    return NLR;
}

static Node* Node_rotate_left(Node* N, Node* NR)
{
    N->right = NR->left;
    if(N->right) {
        N->right->parent = N;
    }
    NR->parent = N->parent;
    if(NR->parent) {
        if(NR->parent->left == N) {
            NR->parent->left = NR;
        }
        else {
            NR->parent->right = NR;
        }
    }
    N->parent = NR;
    NR->left = N;
    return NR;
}

static Node* Node_rotate_right_left(Node* N, Node* NR, Node* NRL)
{
    NR->left = NRL->right;
    if(NR->left) {
        NR->left->parent = NR;
    }
    N->right = NRL->left;
    if(N->right) {
        N->right->parent = N;
    }
    NRL->right = NR;
    NR->parent = NRL;
    NRL->parent = N->parent;
    if(NRL->parent) {
        if(NRL->parent->left == N) {
            NRL->parent->left = NRL;
        }
        else {
            NRL->parent->right = NRL;
        }
    }
    N->parent = NRL;
    NRL->left = N;
    return NRL;
}

#endif
