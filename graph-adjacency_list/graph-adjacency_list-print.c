#include "graph-adjacency_list.h"

#include <stdio.h>

void graph_print(GraphAdjacencyList *G)
{
    // while(vertex) {
        // printf("%ld ", G->adjacency_list->index);
    for(int i = 0; i < 10; i++)
        printf("%d ", *(int *)((char *)G->adjacency_list->data+(28*i)));
        // vertex = vertex +
        // printf("%zu", G->adjacency_list->);
    // }
    
}