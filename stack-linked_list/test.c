#include "stack-linked_list.h"

extern void stack_linked_list_print(StackLinkedList *S);

int main()
{
    StackLinkedList stack = stack_linked_list_construct();
    // stack_push(stack, INT, &x);
    long x = 1, y = 12, z =11;
    // for(int i = 1; i < 100; i++)
    int i = 132213;
    stack_linked_list_push(&stack, &i, sizeof (int));
    stack_linked_list_push(&stack, &z, sizeof (long));
    stack_linked_list_push(&stack, &i, sizeof (int));
    stack_linked_list_push(&stack, &i, sizeof (int));
    // char d = 'c';
    // stack.push(&stack, &c, sizeof c);
    // char e = 'd';
    // stack.push(&stack, &e, sizeof d
    stack_linked_list_print(&stack);
    stack_linked_list_destruct(&stack);
    stack_linked_list_print(&stack);
}
