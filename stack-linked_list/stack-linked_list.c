#include "stack-linked_list.h"

#include <string.h>

void push(struct Stack *stack, void *data, size_t data_type_size);
void pop(struct Stack *stack);

struct Stack stack_construct()
{
    struct Stack stack;

    stack.top = NULL;
    stack.size = 0;

    stack.push = push;
    stack.pop = pop;

    return stack;
}

void stack_distruct(struct Stack *stack)
{
    struct LinkedListNode *node = stack->top;
    while(node) {
        if(node->next) {
            stack->pop(stack);
            node = stack->top;   
        }
        else {
            stack->pop(stack);
            break;
        }
    }
}

struct LinkedListNode *node_construct(void *data, size_t data_type_size)
{
    struct LinkedListNode *node = malloc(sizeof(struct LinkedListNode));
    if(!node) return NULL;

    node->data = malloc(data_type_size);
    memcpy(node->data, data, data_type_size);

    node->data_type_size = data_type_size;

    return node;
}

void push(struct Stack *stack, void *data, size_t data_type_size)
{
    struct LinkedListNode *node = node_construct(data, data_type_size);

    node->next = stack->top;
    stack->top = node;
    
    ++stack->size;
}

void node_distruct(struct LinkedListNode *node)
{
    memset(node->data, 0, node->data_type_size);
    free(node->data);
    node->data = NULL;

    memset(node, 0, sizeof(struct LinkedListNode));
    free(node);
    node = NULL;
}

void pop(struct Stack *stack)
{
    if(!stack->size) return;

    struct LinkedListNode *node = stack->top;

    stack->top = stack->top->next;

    node_distruct(node);

    --stack->size;
}
