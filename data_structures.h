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

enum {
    SIZE_CHAR = sizeof (char),
    SIZE_SHORT = sizeof (short),
    SIZE_INT = sizeof (int),
    SIZE_FLOAT = sizeof (float),
    SIZE_LONG = sizeof (long),
    SIZE_DOUBLE = sizeof (double)
};

enum {
    AVL_TREE,
    BINARY_SEARCH_TREE,
    DEQUE_ARRAY,
    DEQUE_LINKED_LIST,
    DOUBLY_LINKED_LIST,
    DYNAMIC_ARRAY,
    GRAPH_ADJACENCY_LIST,
    GRAPH_ADJACENCY_MATRIX,
    QUEUE_ARRAY,
    QUEUE_LINKED_LIST,
    RED_BLACK_TREE,
    SINGLY_LINKED_LIST,
    STACK_ARRAY,
    STACK_LINKED_LIST
};

inline void data_print(void *data, size_t data_type_size)
{
    switch (data_type_size) {
        case SIZE_CHAR:
            printf("%c ", *(char *)data);
            break;
        case SIZE_SHORT:
            printf("%hd ", *(short *)data);
            break;
        case SIZE_INT:
            printf("%f ", *(int *)data);
            break;
        // case SIZE_FLOAT:
        //     printf("%f ", *(float *)data);
        //     break;
        case SIZE_LONG:
            printf("%ld ", *(long *)data);
            break;
        // case SIZE_DOUBLE:
        //     printf("%lf ", *(double *)data);
        //     break;
        default:
            break;
    }
}