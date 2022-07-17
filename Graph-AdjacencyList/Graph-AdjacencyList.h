#ifndef GRAPH_ADJACENCY_LIST_H
#define GRAPH_ADJACENCY_LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct GraphAL GraphAL;

GraphAL* GraphALCreate(size_t data_size);
void GraphALDestroy(GraphAL* G);
void* GraphALSize(GraphAL* G);
int GraphALInsert(GraphAL* G, void* data);
int GraphALRemove(GraphAL* G, void* data);
// int GraphAL_edgeInsert(GraphAL* G, GraphALVertex *vertex_source,
//     GraphALVertex *vertex_destination, unsigned long weight);
// int GraphAL_edgeRemove(GraphAL* G, GraphALVertex *vertex_source,
//     GraphALVertex *vertex_destination);

#endif
