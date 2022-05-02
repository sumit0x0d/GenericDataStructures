#ifndef GRAPH_ADJACENCY_LIST_H
#define GRAPH_ADJACENCY_LIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct Vertex {
    void* data;
    size_t index;
    unsigned long weight;
    struct Vertex *edge;
} Vertex;

typedef struct GraphAL {
    Vertex *adjacency_list;
    size_t data_size;
    unsigned long vertices;
    size_t size;
} GraphAL;

GraphAL* GraphAL_create(size_t data_size);
void GraphAL_destroy(GraphAL* G);

void* GraphAL_vertices(GraphAL* G);
size_t GraphAL_size(GraphAL* G);

bool GraphAL_vertex_insert(GraphAL* G, void* data);
bool GraphAL_vertex_remove(GraphAL* G, void* data);
bool GraphAL_edge_insert(GraphAL* G, Vertex *vertex_source, Vertex *vertex_destination, unsigned long weight);
bool GraphAL_edge_remove(GraphAL* G, Vertex *vertex_source, Vertex *vertex_destination);

#endif
