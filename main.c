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
    // DequeLinkedList D = deque_linked_list_create();
    // DoublyLinkedList DLL = doubly_linked_list_create(INT, sizeof (int));
    // QueueLinkedList Q = queue_linked_list_create();
    // SinglyLinkedList SLL = singly_linked_list_create();
    StackLinkedList S = stack_linked_list_create(sizeof (int));
    
    // DequeArray D = deque_array_create(INT, sizeof (int), 20);
    // StackArray S2 = stack_array_create(sizeof (char), 20);
    // QueueArray Q = queue_array_create(INT, sizeof (int), 20);

    // DynamicArray DA = dynamic_array_create(INT, sizeof (int), 20, 1.5);

    BinarySearchTree bst_int = binary_search_tree_create(sizeof (int), compare_data);
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

    binary_search_tree_insert(&bst_int, &a);
    binary_search_tree_insert(&bst_int, &b);
    binary_search_tree_insert(&bst_int, &c);
    binary_search_tree_insert(&bst_int, &d);
    binary_search_tree_insert(&bst_int, &e);
    binary_search_tree_insert(&bst_int, &f);
    binary_search_tree_insert(&bst_int, &g);

    binary_search_tree_remove(&bst_int, &d);
    binary_search_tree_print(&bst_int, INT);
}
