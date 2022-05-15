#include "Graph-AdjacencyMatrix.h"

GraphAM *graphAM_create(size_t data_size, unsigned long vertices);
void GraphAM_destroy(GraphAM *G);

int GraphAM_adjacent(GraphAM *G, unsigned long vertex);
int GraphAM_neighbors(GraphAM *G, unsigned long vertex);
int GraphAM_insert_vertex(GraphAM *G, unsigned long vertex);
int GraphAM_remove_vertex(GraphAM *G, unsigned long vertex);
int GraphAM_insert_edge(GraphAM *G, unsigned long vertex_source, unsigned long vertex_dest);
int GraphAM_remove_edge(GraphAM *G, unsigned long vertex_source, unsigned long vertex_dest);

GraphAM *graphAM_create(size_t data_size, unsigned long vertices)
{
    GraphAM *G = malloc(sizeof (GraphAM));
    if(!G) {
        return NULL;
    }
    G->adjacency_matrix = malloc(vertices * vertices);
    if(!G->adjacency_matrix) {
        free(G);
        G = NULL;
        return NULL;
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
