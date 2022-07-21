#ifndef GRAPH_ADJACENCY_LIST_H
#define GRAPH_ADJACENCY_LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct GraphAL GraphAL;

GraphAL* GraphAL_Create(size_t data_size);
void GraphAL_Destroy(GraphAL* G);
void* GraphAL_Size(GraphAL* G);
int GraphAL_Insert(GraphAL* G, void* data);
int GraphAL_Remove(GraphAL* G, void* data);
// int GraphAL_edge_Insert(GraphAL* G, GraphALVertex *vertex_source,
//     GraphALVertex *vertex_destination, unsigned long weight);
// int GraphAL_edge_Remove(GraphAL* G, GraphALVertex *vertex_source,
//     GraphALVertex *vertex_destination);

#endif
