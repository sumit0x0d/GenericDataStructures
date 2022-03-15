#ifndef GRAPH_H
#define GRAPH_H

#include <stdlib.h>
#include <string.h>

struct Vertex {
    void *data;
    unsigned long weight;
    size_t index;
    struct GraphNode *edge;
};

struct Graph {
    struct Vertex *adjacency_list;
    size_t data_type_size;
    unsigned long vertices;
    void (*vertex_insert)(struct Graph *G, void *data);
    // void (*vertex_remove)(struct Graph *G);
    // void (*edge_insert)(struct Graph *G, struct Vertex vertex_source, struct Vertex vertex_destination);
    // void (*edge_remove)(struct Graph *G, struct Vertex vertex_source, struct Vertex vertex_destination);
};

struct Graph graph_construct(size_t data_type_size);
void graph_destruct();

#endif
