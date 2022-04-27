#ifndef GRAPH_ADJACENCY_LIST_H
#define GRAPH_ADJACENCY_LIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct Vertex Vertex;
typedef struct GraphAL GraphAL;

GraphAL* graph_adjacency_list_create(size_t data_size);
void graph_adjacency_list_destroy(GraphAL* G);

void* graph_adjacency_list_vertices(GraphAL* G);
size_t graph_adjacency_list_size(GraphAL* G);

bool graph_adjacency_list_vertex_insert(GraphAL* G, void* data);
bool graph_adjacency_list_vertex_remove(GraphAL* G, void* data);
bool graph_adjacency_list_edge_insert(GraphAL* G, Vertex *vertex_source, Vertex *vertex_destination, unsigned long weight);
bool graph_adjacency_list_edge_remove(GraphAL* G, Vertex *vertex_source, Vertex *vertex_destination);

#endif
