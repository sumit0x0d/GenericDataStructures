#include "stack.h"

extern void stack_print(struct Stack *stack);

int main()
{
    struct Stack stack = stack_construct(sizeof (int));
    // stack_push(stack, INT, &x);
    // int x = 1, y = 12, z =11;
    // for(int i = 1; i < 100; i++)
    int i = 132213;
    stack.push(&stack, &i);
    // char d = 'c';
    // stack.push(&stack, &c, sizeof c);
    // char e = 'd';
    // stack.push(&stack, &e, sizeof d
    stack_print(&stack);
    stack_destruct(&stack);
    stack_print(&stack);
}
