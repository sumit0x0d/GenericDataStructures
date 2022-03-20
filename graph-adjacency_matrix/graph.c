#include "graph.h"

bool graph_adjacent(Graph *G, unsigned long vertex);
bool graph_neighbors(Graph *G, unsigned long vertex);
bool graph_insert_vertex(Graph *G, unsigned long vertex);
bool graph_remove_vertex(Graph *G, unsigned long vertex);
bool graph_insert_edge(Graph *G, unsigned long vertex_source, unsigned long vertex_destination);
bool graph_remove_edge(Graph *G, unsigned long vertex_source, unsigned long vertex_destination);

Graph graph_construct()
{
    Graph G;

    G.adjacency_matrix = NULL;
    G.vertex = 0;

    return G;
}

void graph_destruct(Graph *G)
{
    
}

bool graph_insert_vertex(Graph *G, unsigned long vertex)
{

}

bool graph_insert_edge(Graph *G, unsigned long vertex_source, unsigned long vertex_destination)
{
    
}