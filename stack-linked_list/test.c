#include "stack.h"

extern void stack_print(struct Stack *stack);

int main()
{
    struct Stack stack = stack_construct();
    // stack_push(stack, INT, &x);
    // int x = 1, y = 12, z =11;
    // for(int i = 1; i < 100; i++)
    char *c = "assdaskhdkjashkjdhkjsahdkjhakshdkjashdkjashkdjhkasjhdkjsahjhvjsadfabkjhdja";
    stack.push(&stack, c, strlen(c));
    char a = 'a';
    stack.push(&stack, &a, sizeof a);
    int i = 132213;
    stack.push(&stack, &i, sizeof i);
    float b = 0.26;
    stack.push(&stack, &b, sizeof b);
    // char d = 'c';
    // stack.push(&stack, &c, sizeof c);
    // char e = 'd';
    // stack.push(&stack, &e, sizeof d
    stack_print(&stack);
    stack_destruct(&stack);
    stack_print(&stack);
}
