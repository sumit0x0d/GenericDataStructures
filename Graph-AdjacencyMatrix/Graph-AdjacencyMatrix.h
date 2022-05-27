#ifndef GRAPH_ADJACENCY_MATRIX_H
#define GRAPH_ADJACENCY_MATRIX_H

#include <stdlib.h>

typedef struct GraphAM {
    void** array;
    size_t data_size;
    unsigned long vertices;
} GraphAM;

GraphAM *graphAM_create(size_t data_size, unsigned long vertices);
void GraphAM_destroy(GraphAM *G);

int GraphAM_adjacent(GraphAM *G, unsigned long vertex);
int GraphAM_neighbors(GraphAM *G, unsigned long vertex);
int GraphAM_insert_vertex(GraphAM *G, unsigned long vertex);
int GraphAM_remove_vertex(GraphAM *G, unsigned long vertex);
int GraphAM_insert_edge(GraphAM *G, unsigned long vertex_source, unsigned long vertex_dest);
int GraphAM_remove_edge(GraphAM *G, unsigned long vertex_source, unsigned long vertex_dest);

#endif
