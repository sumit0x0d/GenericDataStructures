#include "graph-adjacency_matrix.h"

bool graph_adjacency_matrix_adjacent(Graph *G, unsigned long vertex);
bool graph_adjacency_matrix_neighbors(Graph *G, unsigned long vertex);
bool graph_adjacency_matrix_insert_vertex(Graph *G, unsigned long vertex);
bool graph_adjacency_matrix_remove_vertex(Graph *G, unsigned long vertex);
bool graph_adjacency_matrix_insert_edge(Graph *G, unsigned long vertex_source, unsigned long vertex_destination);
bool graph_adjacency_matrix_remove_edge(Graph *G, unsigned long vertex_source, unsigned long vertex_destination);

Graph graph_create()
{
    Graph G;

    G.adjacency_matrix = NULL;
    G.vertex = 0;

    return G;
}

// void graph_distroy(Graph *G)
// {
    
// }

// bool graph_insert_vertex(Graph *G, unsigned long vertex)
// {

// }

// bool graph_insert_edge(Graph *G, unsigned long vertex_source, unsigned long vertex_destination)
// {
    
// }