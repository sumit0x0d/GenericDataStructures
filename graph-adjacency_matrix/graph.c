#include "graph.h"

bool graph_adjacent(struct Graph *G, unsigned long vertex);
bool graph_neighbors(struct Graph *G, unsigned long vertex);
bool graph_insert_vertex(struct Graph *G, unsigned long vertex);
bool graph_remove_vertex(struct Graph *G, unsigned long vertex);
bool graph_insert_edge(struct Graph *G, unsigned long vertex_source, unsigned long vertex_destination);
bool graph_remove_edge(struct Graph *G, unsigned long vertex_source, unsigned long vertex_destination);

struct Graph graph_construct()
{
    struct Graph G;

    G.adjacency_matrix = NULL;
    G.vertex = 0;

    return G;
}

void graph_destruct(struct Graph *G)
{
    
}

bool graph_insert_vertex(struct Graph *G, unsigned long vertex)
{

}

bool graph_insert_edge(struct Graph *G, unsigned long vertex_source, unsigned long vertex_destination)
{
    
}