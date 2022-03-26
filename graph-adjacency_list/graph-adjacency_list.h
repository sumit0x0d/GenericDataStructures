#ifndef GRAPH_ADJACENCY_LIST_H
#define GRAPH_ADJACENCY_LIST_H

#ifndef DATA_TYPE
#define DATA_TYPE

enum {
    BOOL,
    CHAR,
    UNSIGNED_CHAR,
    SHORT,
    UNSIGNED_SHORT,
    INT,
    UNSIGNED_INT,
    FLOAT,
    LONG,
    UNSIGNED_LONG,
    DOUBLE,
    LONG_LONG,
    UNSIGNED_LONG_LONG,
    LONG_DOUBLE,
    STRING,
    STRUCT
};

#endif

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct Vertex {
    void *data;
    int data_type;
    unsigned long weight;
    size_t index;
    struct Vertex *edge;
} Vertex;

typedef struct GraphAdjacencyList {
    Vertex *adjacency_list;
    unsigned long vertices;
    size_t size;
} GraphAdjacencyList;

GraphAdjacencyList graph_adjacency_list_construct();
void graph_adjacency_list_destruct(GraphAdjacencyList *G);

void *graph_adjacency_list_vertices(GraphAdjacencyList *G);
size_t graph_adjacency_list_size(GraphAdjacencyList *G);

bool graph_adjacency_list_vertex_insert(GraphAdjacencyList *G, void *data, int data_type, size_t data_type_size);
bool graph_adjacency_list_vertex_remove(GraphAdjacencyList *G, void *data, int data_type, size_t data_type_size);
bool graph_adjacency_list_edge_insert(GraphAdjacencyList *G, Vertex *vertex_source, Vertex *vertex_destination, , unsigned long weight);
bool graph_adjacency_list_edge_remove(GraphAdjacencyList *G, Vertex *vertex_source, Vertex *vertex_destination);

#endif
