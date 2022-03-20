#include "stack.h"

void stack_destruct(Stack *S);
bool stack_push(Stack *S, void *data);
bool stack_pop(Stack *S);

Stack stack_construct(size_t data_type_size)
{
    Stack S;

    S.top = NULL;
    S.data_type_size = data_type_size;
    S.size = 0;

    return S;
}

void stack_destruct(Stack *S)
{
    StackNode *node = S->top;

    while(node)
        if(node->next) {
            stack_pop(S);
            node = S->top;   
        }
        else {
            stack_pop(S);
            break;
        }

    return;
}

StackNode *node_construct(size_t data_type_size)
{
    StackNode *node = malloc(sizeof (StackNode));
    if(!node) return NULL;

    node->data = malloc(data_type_size);
    if(!node->data) {
        free(node);
        node = NULL;
        return NULL;
    }

    return node;
}

bool stack_push(Stack *S, void *data)
{
    StackNode *node = node_construct(S->data_type_size);
    if(!node) return false;

    memcpy(node->data, data, S->data_type_size);

    node->next = S->top;
    S->top = node;

    S->size = S->size + 1;

    return true;
}

void node_destruct(StackNode *node)
{
    free(node->data);
    node->data = NULL;

    free(node);
    node = NULL;
}

bool stack_pop(Stack *S)
{
    if(!S->size) return false;

    StackNode *node = S->top;

    S->top = S->top->next;

    node_destruct(node);

    S->size = S->size - 1;

    return true;
}
