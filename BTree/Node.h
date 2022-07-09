#ifndef NODE_H
#define NODE_H


typedef struct Node {
    void* data;
    struct Node* left;
    struct Node* right;
} Node;

#endif
