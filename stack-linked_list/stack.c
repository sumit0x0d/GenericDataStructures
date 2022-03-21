#include "stack.h"

Stack stack_construct();
void stack_destruct(Stack *);

StackNode *stack_peek(Stack *);
size_t stack_size(Stack *);

StackNode *node_construct(size_t);
void node_destruct(StackNode *);

bool stack_push(Stack *, void *, size_t);
bool stack_pop(Stack *);

Stack stack_construct()
{
    Stack S;

    S.top = NULL;
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

StackNode *stack_peek(Stack *S)
{
    return S->top;
}

size_t stack_size(Stack *S)
{
    return S->size;
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

void node_destruct(StackNode *node)
{
    free(node->data);
    node->data = NULL;

    free(node);
    node = NULL;
}

bool stack_push(Stack *S, void *data, size_t data_type_size)
{
    StackNode *node = node_construct(data_type_size);
    if(!node) return false;

    memcpy(node->data, data, data_type_size);

    node->next = S->top;
    S->top = node;

    S->size = S->size + 1;

    return true;
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
