#include "avl_tree/avl_tree.h"
#include "binary_search_tree/binary_search_tree.h"
// #include "binary_tree/binary_tree.h"
#include "deque-array/deque-array.h"
#include "deque-linked_list/deque-linked_list.h"
#include "doubly_linked_list/doubly_linked_list.h"
#include "dynamic_array/dynamic_array.h"
#include "graph-adjacency_list/graph-adjacency_list.h"
#include "graph-adjacency_matrix/graph-adjacency_matrix.h"
#include "hash_table/hash_table.h"
#include "queue-array/queue-array.h"
#include "queue-linked_list/queue-linked_list.h"
#include "red-black_tree/red-black_tree.h"
#include "singly_linked_list/singly_linked_list.h"
#include "stack-array/stack-array.h"
#include "stack-linked_list/stack-linked_list.h"
#include "trie/trie.h"

typedef union Array {
    DequeArray deque;
    DynamicArray dynamic_array;
    QueueArray queue;
    StackArray stack;
} Array;

typedef union BinaryTree {
    BinarySearchTree binary_search;
    AVLTree avl;
    RedBlackTree red_black;
} BinaryTree;

typedef union LinkedList {
    DequeLinkedList deque;
    DoublyLinkedList doubly_linked_list;
    QueueLinkedList queue;
    SinglyLinkedList Singly_linked_list;
    StackLinkedList stack;
} LinkedList;
