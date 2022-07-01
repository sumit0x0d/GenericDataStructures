#include "Stack-LinkedList.h"

typedef struct Node {
    void* data;
    struct Node* next;
} Node;

StackLL* StackLL_create(size_t data_size)
{
    StackLL* S = (StackLL*)malloc(sizeof (StackLL));
    if(!S) {
        return NULL;
    }
    S->top = NULL;
    S->data_size = data_size;
    S->size = 0;
    return S;
}

void StackLL_destroy(StackLL* S)
{
    Node* node = S->top;
    while(node) {
        if(node->next) {
            StackLL_pop(S);
            node = S->top;   
        }
        else {
            StackLL_pop(S);
            break;
        }
    }
    free(S);
    S = NULL;
}

void* StackLL_top(StackLL* S)
{
    return S->top->data;
}

static Node* node_create(size_t data_size)
{
    Node* node = (Node*)malloc(sizeof (Node));
    if(!node) {
        return NULL;
    }
    node->data = malloc(data_size);
    if(!node->data) {
        free(node);
        return NULL;
    }
    return node;
}

static void node_destroy(Node* node)
{
    free(node->data);
    node->data = NULL;
    free(node);
    node = NULL;
}

bool StackLL_push(StackLL* S, void* data)
{
    Node* node = node_create(S->data_size);
    if(!node) {
        return false;
    }
    memcpy(node->data, data, S->data_size);
    node->next = S->top;
    S->top = node;
    S->size = S->size + 1;
    return true;
}

void StackLL_pop(StackLL* S)
{
    Node* node = S->top;
    S->top = S->top->next;
    node_destroy(node);
    S->size = S->size - 1;
}
