#ifndef DATA_PRINT_H
#define DATA_PRINT_H
// #include, "binary_tree/binary_tree.h"
// #include, "graph-adjacency_list/graph-adjacency_list.h"
// #include, "graph-adjacency_matrix/graph-adjacency_matrix.h"
// #include, "hash_table/hash_table.h"
// #include, "trie/trie.h"
#include <stdio.h>

#ifndef DATA_TYPE
#define DATA_TYPE

enum {
    BOOL,
    CHAR,
    UNSIGNED_CHAR,
    SHORT,
    UNSIGNED_SHORT,
    INT,
    UNSIGNED_INT,
    FLOAT,
    LONG,
    UNSIGNED_LONG,
    DOUBLE,
    LONG_LONG,
    UNSIGNED_LONG_LONG,
    LONG_DOUBLE,
    STRUCT,
    UNION,
    ARRAY,
    POINTER
};

#endif

void data_print(void* data, int data_type)
{
    switch (data_type) {
        case CHAR:
            printf("%c ", *(char *)data);
            break;
        case UNSIGNED_CHAR:
            printf("%c ", *(unsigned char *)data);
            break;
        case SHORT:
            printf("%hd ", *(short *)data);
            break;
        case UNSIGNED_SHORT:
            printf("%hd ", *(unsigned short *)data);
            break;
        case INT:
            printf("%d ", *(int *)&data);
            break;
        case UNSIGNED_INT:
            printf("%u ", *(unsigned int *)data);
            break;
        case FLOAT:
            printf("%f ", *(float *)data);
            break;
        case LONG:
            printf("%ld ", *(long *)data);
            break;
        case UNSIGNED_LONG:
            printf("%lu ", *(unsigned long *)data);
            break;
        case DOUBLE:
            printf("%lf ", *(double *)data);
            break;
        case LONG_LONG:
            printf("%lld ", *(long long *)data);
            break;
        case UNSIGNED_LONG_LONG:
            printf("%llu ", *(unsigned long long *)data);
            break;
        case LONG_DOUBLE:
            printf("%Lf ", *(long double *)data);
            break;
        case POINTER:
            printf("%s ", (char *)data);
            break;
        default:
            break;
    }
}

#endif
