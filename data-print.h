#ifndef DATA_PRINT_H
#define DATA_PRINT_H
// #include "binary_tree/binary_tree.h"
// #include "graph-adjacency_list/graph-adjacency_list.h"
// #include "graph-adjacency_matrix/graph-adjacency_matrix.h"
// #include "hash_table/hash_table.h"
// #include "trie/trie.h"
#include <stdio.h>

void data_print(void *data, size_t data_type_size)
{
    switch (data_type_size) {
        case sizeof (char):
            printf("%c ", *(char *)data);
            break;
        case sizeof (short):
            printf("%hd ", *(short *)data);
            break;
        case sizeof (int):
            printf("%d ", *(int *)data);
            break;
        // case sizeof (float):
        //     printf("%f ", *(float *)data);
        //     break;
        case sizeof (long):
            printf("%ld ", *(long *)data);
            break;
        // case sizeof (double):
        //     printf("%lf ", *(double *)data);
        //     break;
        default:
            break;
    }
}

#endif
