#ifndef GRAPH_ADJACENCY_MATRIX_H
#define GRAPH_ADJACENCY_MATRIX_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct GraphAM GraphAM;

GraphAM *graph_create();
void graph_adjacency_matrix_destroy(GraphAM *G);
bool graph_adjacency_matrix_adjacent(GraphAM *G, unsigned long vertex);
bool graph_adjacency_matrix_neighbors(GraphAM *G, unsigned long vertex);
bool graph_adjacency_matrix_insert_vertex(GraphAM *G, unsigned long vertex);
bool graph_adjacency_matrix_remove_vertex(GraphAM *G, unsigned long vertex);
bool graph_adjacency_matrix_insert_edge(GraphAM *G, unsigned long vertex_source, unsigned long vertex_destination);
bool graph_adjacency_matrix_remove_edge(GraphAM *G, unsigned long vertex_source, unsigned long vertex_destination);

#endif
