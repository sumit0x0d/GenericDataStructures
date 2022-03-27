#include "array-print.h"
#include "binary_tree-print.h"
#include "graph-print.h"
#include "linked_list-print.h"

int compare_data(void *data, void *node_data) {
    if(*(int *)data < *(int *)node_data)
        return -1;
    else if(*(int *)data > *(int *)node_data)
        return 1;
    return 0;
}

int main()
{
    // DequeLinkedList D = deque_linked_list_create(INT, sizeof (int));
    // DoublyLinkedList DLL = doubly_linked_list_create(INT, sizeof (int));
    // QueueLinkedList Q = queue_linked_list_create(INT, sizeof (int));
    // SinglyLinkedList SLL = singly_linked_list_create(INT, sizeof (int));
    // StackLinkedList S = stack_linked_list_create(INT, sizeof (int));
    
    // DequeArray D = deque_array_create(INT, sizeof (int), 20);
    // StackArray S = stack_array_create(CHAR, sizeof (char), 20);
    // QueueArray Q = queue_array_create(INT, sizeof (int), 20);

    // DynamicArray DA = dynamic_array_create(INT, sizeof (int), 20, 1.5);

    // BinarySearchTree BST = binary_search_tree_create(INT, sizeof (int), compare_data);
    // AVLTree AVLT = avl_tree_create(INT, sizeof (int), compare_data);
    // RedBlackTree RBT = red_black_tree_create(INT, sizeof (int), compare_data);

    // GraphAdjacencyList G = graph_adjacency_list_create(INT, sizeof (int));
    // GraphAdjacencyMatrix G = graph_adjacency_list_create(INT, sizeof (int));
    // char c = 'a';
    // int i = 1;
    // int i2 = 2;
    // long l = 200;
    // long double ld = 210.55552235555;
    // char *s = "test";
    // stack_array_push(&S, &c);
    // stack_array_push(&S, &c);
    // queue_array_enqueue(&Q, &i);
    // queue_array_enqueue(&Q, &i2);
    // int x = 10;
    // int l = 10000;
    // graph_adjacency_list_vertex_insert(&G, &x);
    // graph_adjacency_list_vertex_insert(&G, &l);
    // graph_print(&G);
    // queue_array_enqueue(&Q, &i2);
    // queue_array_enqueue(&Q, &i2);
    // queue_array_enqueue(&Q, &i2);
    // queue_array_enqueue(&Q, &i2);
    // queue_array_enqueue(&Q, &i2);
    // long l = 30;
    // char *s = "test";

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

    // stack_linked_list_push(&S, &c);
    // BinarySearchTree BST = binary_search_tree_create(INT, sizeof (int), compare_data);

    // binary_search_tree_insert(&BST, &c, sizeof c);
    // binary_search_tree_insert(&BST, &i, sizeof i);
    // binary_search_tree_insert(&BST, &c, sizeof c);
    // binary_search_tree_print(&BST);
    // stack_linked_list_push(&S, &i, INT, sizeof i);
    // stack_linked_list_push(&S, &c, CHAR, sizeof c);
    // stack_linked_list_push(&S, &l, INT, sizeof l);
    // stack_linked_list_push(&S, &ld, LONG_DOUBLE, sizeof ld);
    // stack_linked_list_push(&S, s, STRING, strlen(s));
    // stack_linked_list_push(&S, &i, INT, sizeof i);
    // stack_linked_list_push(&S, &s, strlen(s));
    // queue_linked_list_print(&Q);
    // singly_linked_list_print(&SLL);
    // stack_linked_list_print(&S);
    // stack_array_print(&S);
    // queue_array_print(&Q);
}
