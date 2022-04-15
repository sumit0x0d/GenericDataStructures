#include "graph-adjacency_matrix.h"

bool graph_adjacency_matrix_adjacent(GraphAdjacencyMatrix *G, unsigned long vertex);
bool graph_adjacency_matrix_neighbors(GraphAdjacencyMatrix *G, unsigned long vertex);
bool graph_adjacency_matrix_insert_vertex(GraphAdjacencyMatrix *G, unsigned long vertex);
bool graph_adjacency_matrix_remove_vertex(GraphAdjacencyMatrix *G, unsigned long vertex);
bool graph_adjacency_matrix_insert_edge(GraphAdjacencyMatrix *G, unsigned long vertex_source, unsigned long vertex_destination);
bool graph_adjacency_matrix_remove_edge(GraphAdjacencyMatrix *G, unsigned long vertex_source, unsigned long vertex_destination);

GraphAdjacencyMatrix graph_create()
{
    GraphAdjacencyMatrix G;

    G.adjacency_matrix = NULL;
    G.vertex = 0;

    return G;
}

// void graph_destroy(GraphAdjacencyMatrix *G)
// {
    
// }

// bool graph_insert_vertex(GraphAdjacencyMatrix *G, unsigned long vertex)
// {

// }

// bool graph_insert_edge(GraphAdjacencyMatrix *G, unsigned long vertex_source, unsigned long vertex_destination)
// {
    
// }