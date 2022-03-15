#include "stack.h"

void push(struct Stack *S, void *data);
void pop(struct Stack *S);

struct Stack stack_construct(size_t data_type_size)
{
    struct Stack S;

    S.top = NULL;
    S.data_type_size = data_type_size;
    S.size = 0;

    S.push = push;
    S.pop = pop;

    return S;
}

void stack_destruct(struct Stack *S)
{
    struct StackNode *node = S->top;
    while(node)
        if(node->next) {
            S->pop(S);
            node = S->top;   
        }
        else {
            S->pop(S);
            break;
        }
}

struct StackNode *node_construct(size_t data_type_size)
{
    struct StackNode *node = malloc(sizeof (struct StackNode));
    if(!node) return NULL;

    node->data = malloc(data_type_size);
    if(!node->data) {
        free(node);
        node = NULL;
        return NULL;
    }

    return node;
}

void push(struct Stack *S, void *data)
{
    struct StackNode *node = node_construct(S->data_type_size);
    if(!node) return;

    memcpy(node->data, data, S->data_type_size);

    node->next = S->top;
    S->top = node;

    S->size = S->size + 1;
}

void node_destruct(struct StackNode *node)
{
    free(node->data);
    node->data = NULL;

    free(node);
    node = NULL;
}

void pop(struct Stack *S)
{
    if(!S->size) return;

    struct StackNode *node = S->top;

    S->top = S->top->next;

    node_destruct(node);

    S->size = S->size - 1;
}
