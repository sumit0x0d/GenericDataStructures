// #include "array-print.h"
// #include "binary_tree-print.h"
#include "linked_list-print.h"

int compare_data(void *data, void *node_data, int data_type) {
    return 1;
}

int main()
{
    // DequeLinkedList D = deque_linked_list_construct();
    // DoublyLinkedList DLL = doubly_linked_list_construct();
    // QueueLinkedList Q = queue_linked_list_construct();
    // SinglyLinkedList SLL = singly_linked_list_construct();
    StackLinkedList S = stack_linked_list_construct();
    // int c = 1;
    char i[3] = "aaa";
    // long l = 30;
    // char *s = "test";

    // deque_linked_list_push(&D, &a, sizeof a);
    // deque_linked_list_push(&D, &a, sizeof a);
    // deque_linked_list_push(&D, &a, sizeof a);
    
    // doubly_linked_list_push(&DLL, &a, sizeof a);
    // doubly_linked_list_push(&DLL, &a, sizeof a);
    // doubly_linked_list_push(&DLL, &a, sizeof a);

    // queue_linked_list_enqueue(&Q, &c, sizeof c);
    // queue_linked_list_enqueue(&Q, &i, STRING, strlen(i));
    // queue_linked_list_enqueue(&Q, &l, sizeof l);
    // queue_linked_list_enqueue(&Q, &s, strlen(s));

    // singly_linked_list_push_back(&SLL, &c, sizeof c);
    // singly_linked_list_push_back(&SLL, &i, sizeof i);
    // singly_linked_list_push_back(&SLL, &l, sizeof l);
    // singly_linked_list_push_back(&SLL, &s, strlen(s));

    // stack_linked_list_push(&S, &c, sizeof c);
    // BinarySearchTree BST = binary_search_tree_construct(INT, sizeof (int), compare_data);

    // binary_search_tree_insert(&BST, &c);
    // binary_search_tree_insert(&BST, &i);
    // binary_search_tree_insert(&BST, &c, sizeof );
    // binary_search_tree_print(&BST);
    stack_linked_list_push(&S, &i, STRING, strlen(i));
    // stack_linked_list_push(&S, &i, INT, sizeof i);
    // stack_linked_list_push(&S, &s, strlen(s));
    // queue_linked_list_print(&Q);
    // singly_linked_list_print(&SLL);
    stack_linked_list_print(&S);

}