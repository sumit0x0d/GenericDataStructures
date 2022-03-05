#include "graph.h"

void adjacent(struct Graph *graph, unsigned long vertex);
void neighbors(struct Graph *graph, unsigned long vertex);
void insert_vertex(struct Graph *graph, unsigned long vertex);
void remove_vertex(struct Graph *graph, unsigned long vertex);
void insert_edge(struct Graph *graph, unsigned long vertex_source, unsigned long vertex_destination);
void remove_edge(struct Graph *graph, unsigned long vertex_source, unsigned long vertex_destination);

struct Graph graph_construct(unsigned long vertex)
{
    struct Graph graph;

    graph.adjacency_matrix = malloc(sizeof (int) * vertex);
    graph.vertex = vertex;

    graph.adjacent = adjacent;
    graph.neighbors = neighbors;
    graph.insert_vertex = insert_vertex;
    graph.remove_vertex = remove_vertex;
    graph.insert_edge = insert_edge;
    graph.remove_edge = remove_edge;

    return graph;
}

void graph_destruct(struct Graph *graph)
{
    
}

void insert_vertex(struct Graph *graph, unsigned long vertex)
{
    graph.
}

void insert_edge(struct Graph *graph, unsigned long vertex_source, unsigned long vertex_destination)
{
    
}