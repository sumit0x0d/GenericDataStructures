#ifndef GRAPH_ADJACENCY_MATRIX_H
#define GRAPH_ADJACENCY_MATRIX_H

#include <stdbool.h>
#include <stddef.h>

typedef struct GraphAM GraphAM;

GraphAM *graphAM_Create(size_t data_size, unsigned long vertex_count);
void GraphAM_Destroy(GraphAM *G);
bool GraphAM_adjacent(GraphAM *G, unsigned long vertex);
bool GraphAM_neighbors(GraphAM *G, unsigned long vertex);
bool GraphAM_Insert_vertex(GraphAM *G, unsigned long vertex);
bool GraphAM_Remove_vertex(GraphAM *G, unsigned long vertex);
bool GraphAM_Insert_edge(GraphAM *G, unsigned long vertex_source, unsigned long vertex_dest);
bool GraphAM_Remove_edge(GraphAM *G, unsigned long vertex_source, unsigned long vertex_dest);

#endif
