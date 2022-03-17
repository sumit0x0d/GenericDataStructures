#include "graph.h"
#include <stdio.h>

void graph_print(struct Graph *G)
{
    // while(vertex) {
        // printf("%ld ", G->adjacency_list->index);
        for(int i = 0; i < 10; i++)
            printf("%ld ", *(long *)((char *)G->adjacency_list->data+(8*i)));
        // vertex = vertex +
    // }
    
}