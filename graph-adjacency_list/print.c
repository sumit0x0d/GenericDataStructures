#include "graph.h"
#include <stdio.h>

void graph_print(struct Graph *graph)
{
    struct Vertex *vertex;
    while(vertex) {
        printf("%ld ", graph->adjacency_list->index);
        // vertex = vertex +
    }
    
}