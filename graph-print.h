#include "graph-adjacency_list/graph-adjacency_list.h"

#include "data-print.h"

void graph_print(GraphAdjacencyList *G)
{
    if(!G->size) return;

    printf("[Graph (Adjacency List)]");

    printf("\n[Data]\t: ");
    for(size_t i = 0; i < G->vertices; i++) {
        data_print((G->adjacency_list + (i * sizeof(Vertex)))->data, INT);
        // printf("%lu", (G->adjacency_list + (i * sizeof(Vertex)))->weight);
    }

    printf("\n[Size]\t: %zu\n", G->size);
}
