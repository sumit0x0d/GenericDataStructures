#ifndef NODE_H
#define NODE_H

#include <stdlib.h>

typedef struct Node {
    int terminal;
    struct TrieNode* children[128];
} Node;

static Node* NodeCreate()
{
    Node* N = (Node*)malloc(sizeof (Node));
    if(!N) {
        return NULL;
    }
    N->terminal = 0;
    for(int i = 0; i < 128; i++) {
        N->children[i] = NULL;
    }
    // memset(node->children, '\0', sizeof (Node) * 128);
    return N;
}
#endif
