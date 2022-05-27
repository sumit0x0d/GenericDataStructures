#include "Graph-AdjacencyMatrix.h"

GraphAM *graphAM_create(size_t data_size, unsigned long vertices)
{
    GraphAM *G = malloc(sizeof (GraphAM));
    if(!G) {
        return NULL;
    }
    G->array = malloc(vertices * sizeof (void*));
    if(!G->array) {
        free(G);
        G = NULL;
        return NULL;
    }
    for(size_t i = 0; i < vertices; i++) {
        G->array[i] = malloc(data_size * vertices);
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
    G->vertices = 0;
    return G;
}

// void graph_destroy(GraphAM *G)
// {
    
// }

// int graph_insert_vertex(GraphAM *G, unsigned long vertex)
// {

// }

// int graph_insert_edge(GraphAM *G, unsigned long vertex_source, unsigned long vertex_dest)
// {
    
// }
