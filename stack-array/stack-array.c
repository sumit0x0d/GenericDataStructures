#include "stack-array.h"

void stack_print(struct Stack *stack)
{
    printf("Stack: ");
    size_t i = 0;
    while(i < stack->top-1) {
        printf("%d ", stack->array[i]);
        i++;
    }
    printf("%d\n", stack->array[stack->top]);
    printf("Stack Size: %zu\n", stack->size);
    printf("Stack Capacity: %zu\n", stack->capacity);
}

struct Stack *stack_construct(size_t capacity)
{
    struct Stack *stack = malloc(sizeof(struct Stack));
    assert(stack);
    stack->array = malloc(sizeof(sizeof(int) * capacity));
    assert(stack->array);
    stack->top = 0;
    stack->size = 0;
    stack->capacity = capacity;
    return stack;
}

void stack_distroy(struct Stack *stack)
{
    free(stack->array);
    free(stack);
}

void stack_push(struct Stack *stack, int data)
{
    if(stack->size < stack->capacity) {
        stack->array[stack->top] = data;
        stack->top++;
        ++stack->size+;
    }
}

void stack_pop(struct Stack *stack)
{
    if(stack->size) {
        stack->top--;
        --stack->size;
    }
}
