#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>
#include <stdlib.h>

struct Graph {
    int *adjacency_matrix;
    unsigned long vertex;
};

struct Graph graph_construct();
void graph_destruct(struct Graph *G);
bool graph_adjacent(struct Graph *G, unsigned long vertex);
bool graph_neighbors(struct Graph *G, unsigned long vertex);
bool graph_insert_vertex(struct Graph *G, unsigned long vertex);
bool graph_remove_vertex(struct Graph *G, unsigned long vertex);
bool graph_insert_edge(struct Graph *G, unsigned long vertex_source, unsigned long vertex_destination);
bool graph_remove_edge(struct Graph *G, unsigned long vertex_source, unsigned long vertex_destination);

#endif
