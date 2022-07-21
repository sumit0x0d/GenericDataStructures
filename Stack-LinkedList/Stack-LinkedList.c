#include "Stack-LinkedList.h"
#include "Node.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct StackLL {
    Node* top;
    size_t data_size;
    size_t size;
};

StackLL* StackLL_Create(size_t data_size)
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

void StackLL_Destroy(StackLL* S)
{
    Node* node = S->top;
    while(node) {
        if(node->next) {
            StackLLPop(S);
            node = S->top;   
        }
        else {
            StackLLPop(S);
            break;
        }
    }
    free(S);
    S = NULL;
}

size_t StackLL_Size(StackLL* S)
{
    return S->size;
}

bool StackLL_Empty(StackLL* S)
{
    if(S->size) {
        return false;
    }
    return true;
}

void* StackLL_Top(StackLL* S)
{
    return S->top->data;
}

bool StackLL_Push(StackLL* S, void* data)
{
    Node* node = Node_Create(S->data_size);
    if(!node) {
        return false;
    }
    memcpy(node->data, data, S->data_size);
    node->next = S->top;
    S->top = node;
    S->size = S->size + 1;
    return true;
}

void StackLLPop(StackLL* S)
{
    Node* node = S->top;
    S->top = S->top->next;
    Node_Destroy(node);
    S->size = S->size - 1;
}

void StackLL_Traverse(StackLL* S, void (*function)(void* data))
{
    Node* node = S->top;
    while(node) {
        function(node->data);
        node = node->next;
    }
}
