#include "stack.h"

void push(struct Stack *stack, void *data);
void pop(struct Stack *stack);

struct Stack stack_construct(size_t data_type_size)
{
    struct Stack stack;

    stack.top = NULL;
    stack.data_type_size = data_type_size;
    stack.size = 0;

    stack.push = push;
    stack.pop = pop;

    return stack;
}

void stack_destruct(struct Stack *stack)
{
    struct StackNode *node = stack->top;
    while(node)
        if(node->next) {
            stack->pop(stack);
            node = stack->top;   
        }
        else {
            stack->pop(stack);
            break;
        }
}

struct StackNode *node_construct(void *data, size_t data_type_size)
{
    struct StackNode *node = malloc(sizeof (struct StackNode));
    if(!node) return NULL;

    node->data = malloc(data_type_size);
    if(!node->data) {
        free(node);
        node = NULL;
        return NULL;
    }

    memcpy(node->data, data, data_type_size);

    return node;
}

void push(struct Stack *stack, void *data)
{
    struct StackNode *node = node_construct(data, stack->data_type_size);
    if(!node) return;

    node->next = stack->top;
    stack->top = node;

    stack->size = stack->size + 1;
}

void node_destruct(struct StackNode *node)
{
    free(node->data);
    node->data = NULL;

    free(node);
    node = NULL;
}

void pop(struct Stack *stack)
{
    if(!stack->size) return;

    struct StackNode *node = stack->top;

    stack->top = stack->top->next;

    node_destruct(node);

    stack->size = stack->size - 1;
}
