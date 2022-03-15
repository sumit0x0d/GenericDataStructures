#ifndef GRAPH_H
#define GRAPH_H

#include <stdlib.h>

struct Graph {
    int *adjacency_matrix;
    unsigned long vertex;
    void (*adjacent)(struct Graph *G, unsigned long vertex);
    void (*neighbors)(struct Graph *G, unsigned long vertex);
    void (*insert_vertex)(struct Graph *G, unsigned long vertex);
    void (*remove_vertex)(struct Graph *G, unsigned long vertex);
    void (*insert_edge)(struct Graph *G, unsigned long vertex_source, unsigned long vertex_destination);
    void (*remove_edge)(struct Graph *G, unsigned long vertex_source, unsigned long vertex_destination);
};

struct Graph graph_construct();
void graph_destruct(struct Graph *G);

#endif
