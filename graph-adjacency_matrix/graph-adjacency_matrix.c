#include "graph-adjacency_matrix.h"

struct GraphAM {
    int *adjacency_matrix;
    unsigned long vertex;
};

bool graph_adjacency_matrix_adjacent(GraphAM *G, unsigned long vertex);
bool graph_adjacency_matrix_neighbors(GraphAM *G, unsigned long vertex);
bool graph_adjacency_matrix_insert_vertex(GraphAM *G, unsigned long vertex);
bool graph_adjacency_matrix_remove_vertex(GraphAM *G, unsigned long vertex);
bool graph_adjacency_matrix_insert_edge(GraphAM *G, unsigned long vertex_source, unsigned long vertex_destination);
bool graph_adjacency_matrix_remove_edge(GraphAM *G, unsigned long vertex_source, unsigned long vertex_destination);

GraphAM *graph_create()
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
