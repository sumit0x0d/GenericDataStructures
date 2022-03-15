#include "graph.h"

void adjacent(struct Graph *G, unsigned long vertex);
void neighbors(struct Graph *G, unsigned long vertex);
void insert_vertex(struct Graph *G, unsigned long vertex);
void remove_vertex(struct Graph *G, unsigned long vertex);
void insert_edge(struct Graph *G, unsigned long vertex_source, unsigned long vertex_destination);
void remove_edge(struct Graph *G, unsigned long vertex_source, unsigned long vertex_destination);

struct Graph graph_construct()
{
    struct Graph G;

    G.adjacency_matrix = NULL;
    G.vertex = 0;

    G.adjacent = adjacent;
    G.neighbors = neighbors;
    G.insert_vertex = insert_vertex;
    G.remove_vertex = remove_vertex;
    G.insert_edge = insert_edge;
    G.remove_edge = remove_edge;

    return G;
}

void graph_destruct(struct Graph *G)
{
    
}

void insert_vertex(struct Graph *G, unsigned long vertex)
{
    G.
}

void insert_edge(struct Graph *G, unsigned long vertex_source, unsigned long vertex_destination)
{
    
}