#include "Graph-AdjacencyMatrix.h"

#include <stdbool.h>
#include <stdlib.h>

struct GraphAM {
    void** array;
    size_t data_size;
    unsigned long vertex_count;
};

GraphAM *graphAM_Create(size_t data_size, unsigned long vertex_count)
{
    GraphAM* G = (GraphAM*)malloc(sizeof (GraphAM));
    if(!G) {
        return NULL;
    }
    G->array = (void**)malloc(vertex_count * sizeof (void*));
    if(!G->array) {
        free(G);
        G = NULL;
        return NULL;
    }
    for(size_t i = 0; i < vertex_count; i++) {
        G->array[i] = malloc(data_size * vertex_count);
        if(!G->array[i]) {
            for(size_t j = 0; j < i; j++) {
                free(G->array[j]);
                G->array[j] = NULL;
            }
            free(G->array);
            G->array = NULL;
            free(G);
            G = NULL;
            return NULL;
        }
    }
    G->data_size = data_size;
    G->vertex_count = 0;
    return G;
}

// void graph_Destroy(GraphAM *G)
// {
    
// }

// int graph_Insert_vertex(GraphAM *G, unsigned long vertex)
// {

// }

// int graph_Insert_edge(GraphAM *G, unsigned long vertex_source, unsigned long vertex_dest)
// {
    
// }
