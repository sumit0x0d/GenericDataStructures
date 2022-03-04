#include "stack-linked_list.h"
#include "stack_print.h"

int main()
{
    struct Stack stack = stack_construct();
    // stack_push(stack, INT, &x);
    // int x = 1, y = 12, z =11;
    // for(int i = 1; i < 100; i++)
    char c = 'c';
    stack.push(&stack, &c, sizeof c);
    char a = 'a';
    stack.push(&stack, &a, sizeof a);
    int i = 0;
    stack.push(&stack, &i, sizeof i);
    float b = 1.26;
    stack.push(&stack, &b, sizeof b);
    // char d = 'c';
    // stack.push(&stack, &c, sizeof c);
    // char e = 'd';
    // stack.push(&stack, &e, sizeof d
    stack_print(&stack);
    stack_distruct(&stack);
    stack_print(&stack);
}
