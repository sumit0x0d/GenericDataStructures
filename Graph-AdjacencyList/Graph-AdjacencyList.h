#ifndef GRAPH_ADJACENCY_LIST_H
#define GRAPH_ADJACENCY_LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct GraphAL GraphAL;

GraphAL* GraphAL_create(size_t data_size);
void GraphAL_destroy(GraphAL* G);

void* GraphAL_vertices(GraphAL* G);

int GraphAL_vertex_insert(GraphAL* G, void* data);
int GraphAL_vertex_remove(GraphAL* G, void* data);
// int GraphAL_edge_insert(GraphAL* G, GraphALVertex *vertex_source,
//     GraphALVertex *vertex_destination, unsigned long weight);
// int GraphAL_edge_remove(GraphAL* G, GraphALVertex *vertex_source,
//     GraphALVertex *vertex_destination);

#endif
