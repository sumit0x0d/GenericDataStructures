#ifndef GRAPH_H
#define GRAPH_H

#include <stdlib.h>

struct Vertex {
    void *data;
    unsigned long weight;
    struct GraphNode *next;
};

struct Graph {
    struct Vertex *adjacency_list;
    size_t data_type_size;
    unsigned long vertices;
    void (*insert_vertex)(struct Graph *graph, void *data);
    void (*remove_vertex)(struct Graph *graph);
    void (*insert_edge)(struct Graph *graph, struct Vertex vertex_source, struct Vertex vertex_destination);
    void (*remove_edge)(struct Graph *graph, struct Vertex vertex_source, struct Vertex vertex_destination);
};

struct Graph graph_construct(size_t data_type_size);
void graph_destruct();

#endif
