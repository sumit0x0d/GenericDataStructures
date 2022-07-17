#ifndef GRAPH_ADJACENCY_MATRIX_H
#define GRAPH_ADJACENCY_MATRIX_H

#include <stdbool.h>
#include <stddef.h>

typedef struct GraphAM GraphAM;

GraphAM *graphAMCreate(size_t data_size, unsigned long vertex_count);
void GraphAMDestroy(GraphAM *G);
bool GraphAM_adjacent(GraphAM *G, unsigned long vertex);
bool GraphAM_neighbors(GraphAM *G, unsigned long vertex);
bool GraphAMInsert_vertex(GraphAM *G, unsigned long vertex);
bool GraphAMRemove_vertex(GraphAM *G, unsigned long vertex);
bool GraphAMInsert_edge(GraphAM *G, unsigned long vertex_source, unsigned long vertex_dest);
bool GraphAMRemove_edge(GraphAM *G, unsigned long vertex_source, unsigned long vertex_dest);

#endif
