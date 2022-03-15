#include "graph.h"
#include <stdio.h>

void graph_print(struct Graph *G)
{
    struct Vertex *vertex;
    while(vertex) {
        printf("%ld ", G->adjacency_list->index);
        // vertex = vertex +
    }
    
}