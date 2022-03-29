#ifndef GRAPH_ADJACENCY_MATRIX_H
#define GRAPH_ADJACENCY_MATRIX_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct Graph {
    int *adjacency_matrix;
    unsigned long vertex;
} Graph;

Graph graph_create();
void graph_destroy(Graph *G);
bool graph_adjacent(Graph *G, unsigned long vertex);
bool graph_neighbors(Graph *G, unsigned long vertex);
bool graph_insert_vertex(Graph *G, unsigned long vertex);
bool graph_remove_vertex(Graph *G, unsigned long vertex);
bool graph_insert_edge(Graph *G, unsigned long vertex_source, unsigned long vertex_destination);
bool graph_remove_edge(Graph *G, unsigned long vertex_source, unsigned long vertex_destination);

#endif
