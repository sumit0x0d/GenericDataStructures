#include "graph-adjacency_matrix.h"

bool GraphAM_adjacent(GraphAM *G, unsigned long vertex);
bool GraphAM_neighbors(GraphAM *G, unsigned long vertex);
bool GraphAM_insert_vertex(GraphAM *G, unsigned long vertex);
bool GraphAM_remove_vertex(GraphAM *G, unsigned long vertex);
bool GraphAM_insert_edge(GraphAM *G, unsigned long vertex_source, unsigned long vertex_destination);
bool GraphAM_remove_edge(GraphAM *G, unsigned long vertex_source, unsigned long vertex_destination);

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

// bool graph_insert_vertex(GraphAM *G, unsigned long vertex)
// {

// }

// bool graph_insert_edge(GraphAM *G, unsigned long vertex_source, unsigned long vertex_destination)
// {
    
// }
