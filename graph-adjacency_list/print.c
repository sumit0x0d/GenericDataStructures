#include "graph.h"
#include <stdio.h>

void graph_print(struct Graph *G)
{
    // while(vertex) {
        // printf("%ld ", G->adjacency_list->index);
    for(int i = 0; i < 10; i++)
        printf("%d ", *(int *)((char *)G->adjacency_list->data+(28*i)));
        // vertex = vertex +
        // printf("%zu", G->adjacency_list->);
    // }
    
}