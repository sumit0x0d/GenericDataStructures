// #include "stack-array.h"
#include "stack-linked_list.h"

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
    int i = 10;
    stack.push(&stack, &i, sizeof i);
    // char b = 'c';
    // stack.push(&stack, &b, sizeof c);
    // char d = 'c';
    // stack.push(&stack, &c, sizeof c);
    // char e = 'd';
    // stack.push(&stack, &e, sizeof d);
    // char f = 'c';
    // stack.push(&stack, &f, sizeof c);
    // char g = 'c';
    // stack.push(&stack, &g, sizeof c);
    // char h = 'c';
    // stack.push(&stack, &h, sizeof c);
    // char j = 'c';
    // stack.push(&stack, &j, sizeof c);
    // float x = 188.22;
    // stack.push(&stack, &x, sizeof x);
        // stack_push(stack, &j);
    // stack_push(stack, &y);
    // stack_push(stack, &z);
    // stack_push(stack, 10);
    // stack_push(stack, 20);
    // stack_push(stack, 30);
    // stack.pop(&stack);
    // char k = 'c';
    // stack.push(&stack, &k, sizeof c);
    // stack.pop(&stack);
    // stack.pop(&stack);
    // print_stack(stack);
    // printf("\n");
    // print_stack(stack);
    // push(stack, 10);
    // push(stack, 20);
    // push(stack, 30);
    // push(stack, 40);
    stack.print(&stack);
    stack_distruct(&stack);
    stack.print(&stack);
}
