#ifndef GRAPH_ADJACENCY_MATRIX_H
#define GRAPH_ADJACENCY_MATRIX_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct GraphAdjacencyMatrix GraphAdjacencyMatrix;

GraphAdjacencyMatrix *graph_create();
void graph_adjacency_matrix_destroy(GraphAdjacencyMatrix *G);
bool graph_adjacency_matrix_adjacent(GraphAdjacencyMatrix *G, unsigned long vertex);
bool graph_adjacency_matrix_neighbors(GraphAdjacencyMatrix *G, unsigned long vertex);
bool graph_adjacency_matrix_insert_vertex(GraphAdjacencyMatrix *G, unsigned long vertex);
bool graph_adjacency_matrix_remove_vertex(GraphAdjacencyMatrix *G, unsigned long vertex);
bool graph_adjacency_matrix_insert_edge(GraphAdjacencyMatrix *G, unsigned long vertex_source, unsigned long vertex_destination);
bool graph_adjacency_matrix_remove_edge(GraphAdjacencyMatrix *G, unsigned long vertex_source, unsigned long vertex_destination);

#endif
