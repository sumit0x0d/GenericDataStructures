#include "Graph-AdjacencyMatrix.h"

int GraphAM_adjacent(GraphAM *G, unsigned long vertex);
int GraphAM_neighbors(GraphAM *G, unsigned long vertex);
int GraphAM_insert_vertex(GraphAM *G, unsigned long vertex);
int GraphAM_remove_vertex(GraphAM *G, unsigned long vertex);
int GraphAM_insert_edge(GraphAM *G, unsigned long vertex_source, unsigned long vertex_dest);
int GraphAM_remove_edge(GraphAM *G, unsigned long vertex_source, unsigned long vertex_dest);

GraphAM *graphAM_create()
{
    GraphAM *G = malloc(sizeof (GraphAM));
    if(!G) {
        return NULL;
    }
    G->adjacency_matrix = NULL;
    G->vertex = 0;

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
