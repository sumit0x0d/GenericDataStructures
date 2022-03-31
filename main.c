// #include "array-print.h"
#include "binary_tree-print.h"
// #include "graph-print.h"
// #include "linked_list-print.h"

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
    // StackLinkedList S = stack_linked_list_create(sizeof (char));
    
    // DequeArray D = deque_array_create(INT, sizeof (int), 20);
    // StackArray S2 = stack_array_create(sizeof (char), 20);
    // QueueArray Q = queue_array_create(INT, sizeof (int), 20);

    // DynamicArray DA = dynamic_array_create(INT, sizeof (int), 20, 1.5);

    BinarySearchTree BST = binary_search_tree_create(sizeof (int), compare_data);
    // AVLTree AVLT = avl_tree_create(INT, sizeof (int), compare_data);
    // RedBlackTree RBT = red_black_tree_create(INT, sizeof (int), compare_data);

    // GraphAdjacencyList G = graph_adjacency_list_create(INT, sizeof (int));
    // GraphAdjacencyMatrix G = graph_adjacency_list_create(INT, sizeof (int));

    int a = 10;
    int b = 3;
    int c = 1;
    int d = 19;
    int e = 30;
    int f = 100;
    int g = 14;
    // int i = 1;
    // long l = 99999999;
    // long double ld = 3.14;
    // char *s = "string";

    binary_search_tree_insert(&BST, &a);
    binary_search_tree_insert(&BST, &b);
    binary_search_tree_insert(&BST, &c);
    binary_search_tree_insert(&BST, &d);
    binary_search_tree_insert(&BST, &e);
    binary_search_tree_insert(&BST, &f);
    binary_search_tree_insert(&BST, &g);

    binary_search_tree_remove(&BST, &d);
    // stack_array_push(&S, &c);
    // stack_array_push(&S2, &c);
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

    // deque_linked_list_push(&D, &a);
    // deque_linked_list_push(&D, &a);
    
    // doubly_linked_list_push(&DLL, &a);
    // doubly_linked_list_push(&DLL, &a);
    // doubly_linked_list_push(&DLL, &a);

    // queue_linked_list_enqueue(&Q, &c);
    // queue_linked_list_enqueue(&Q, &i);
    // queue_linked_list_enqueue(&Q, &l);
    // queue_linked_list_enqueue(&Q, &s));

    // singly_linked_list_push_back(&SLL, &c);
    // singly_linked_list_push_back(&SLL, &i);
    // singly_linked_list_push_back(&SLL, &l);
    // singly_linked_list_push_back(&SLL, &s);

    // stack_linked_list_push(&S, &c);
    // BinarySearchTree BST = binary_search_tree_create(INT, sizeof (int), compare_data);

    // binary_search_tree_insert(&BST, &i);
    // binary_search_tree_insert(&BST, &c);
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
    // stack_linked_list_print(&S, CHAR);
    // stack_array_print(&S2, CHAR);
    // queue_array_print(&Q);
    binary_search_tree_print(&BST, INT);
}
