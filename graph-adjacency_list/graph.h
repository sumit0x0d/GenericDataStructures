#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct Vertex {
    void *data;
    unsigned long weight;
    size_t index;
    Vertex *edge;
} Vertex;

typedef struct Graph {
    Vertex *adjacency_list;
    size_t data_type_size;
    unsigned long vertices;
} Graph;

Graph graph_construct(size_t data_type_size);
void graph_destruct();
bool graph_vertex_insert(Graph *G, void *data);
bool graph_vertex_remove(Graph *G);
bool graph_edge_insert(Graph *G, Vertex vertex_source, Vertex vertex_destination);
bool graph_edge_remove(Graph *G, Vertex vertex_source, Vertex vertex_destination);

#endif
