#ifndef GRAPH_ADJACENCY_MATRIX_H
#define GRAPH_ADJACENCY_MATRIX_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct GraphAM {
    int *adjacency_matrix;
    unsigned long vertex;
} GraphAM;

GraphAM *graph_create();
void GraphAM_destroy(GraphAM *G);

bool GraphAM_adjacent(GraphAM *G, unsigned long vertex);
bool GraphAM_neighbors(GraphAM *G, unsigned long vertex);
bool GraphAM_insert_vertex(GraphAM *G, unsigned long vertex);
bool GraphAM_remove_vertex(GraphAM *G, unsigned long vertex);
bool GraphAM_insert_edge(GraphAM *G, unsigned long vertex_source, unsigned long vertex_destination);
bool GraphAM_remove_edge(GraphAM *G, unsigned long vertex_source, unsigned long vertex_destination);

#endif
