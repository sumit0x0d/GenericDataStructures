#include "Graph-AdjacencyList.h"

GraphAL* GraphAL_create(size_t data_size);
void GraphAL_destroy(GraphAL* G);

void* GraphAL_vertices(GraphAL* G);
size_t GraphAL_size(GraphAL* G);

// static GraphALVertex *vertex_create(size_t data_size);
// static void vertex_destroy(GraphALVertex *vertex);

int GraphAL_vertex_insert(GraphAL* G, void* data);
int GraphAL_vertex_remove(GraphAL* G, void* data);
int GraphAL_edge_insert(GraphAL* G, GraphALVertex *vertex_source,
    GraphALVertex *vertex_destination, unsigned long weight);
int GraphAL_edge_remove(GraphAL* G, GraphALVertex *vertex_source,
    GraphALVertex *vertex_destination);

GraphAL* GraphAL_create(size_t data_size)
{
    GraphAL* G = malloc(sizeof (GraphAL));
    if(!G) {
        return NULL;
    }
    G->adjacency_list = NULL;
    G->data_size = data_size;
    G->vertices = 0;
    G->size = 0;
    return G;
}

void GraphAL_destroy(GraphAL* G)
{
    free(G->adjacency_list);
    G->adjacency_list = NULL;
    G->vertices = 0;
    G->size = 0;
}

// void adjacency_list_create(GraphALVertex *adjacency_list)
// {
//     if(!adjacency_list) {
//         adjacency_list = malloc(sizeof (GraphALVertex));
//         if(!adjacency_list) return;
//     }
// }

// GraphALVertex *GraphAL_vertex_search(GraphAL* G, void* data)
// {
//     GraphALVertex *vertex = G->adjacency_list;

//     for(unsigned long i = 0; i < G->vertices; i++) {
//         if(vertex->data == )

//     }
// }

GraphALVertex *GraphALVertex_create(size_t data_size)
{
    GraphALVertex *vertex = malloc(sizeof (GraphALVertex));
    if(!vertex) {
        return NULL;
    }
    vertex->data = malloc(data_size);
    if(!vertex->data) {
        free(vertex);
        vertex = NULL;
        return NULL;
    }
    vertex->weight = 0;
    vertex->edge = NULL;
    return vertex;
}

// void vertex_destroy(GraphALVertex *vertex)
// {

// }

int GraphAL_vertex_insert(GraphAL* G, void* data)
{
    if(!G->adjacency_list) {
        G->adjacency_list = malloc(sizeof (GraphALVertex));
        if(!G->adjacency_list) {
            return 0;
        }
    }
    else {
        GraphALVertex *adjacency_list = realloc(G->adjacency_list, sizeof (GraphALVertex) * (G->vertices + 1));
        if(!adjacency_list) {
            return 0;
        }
        G->adjacency_list = adjacency_list;
    }
    GraphALVertex *vertex = GraphALVertex_create(G->data_size);
    if(!vertex) {
        return 0;
    }
    memcpy(vertex->data, data, G->data_size);
    memcpy(G->adjacency_list + (sizeof (GraphALVertex) * G->vertices), vertex, sizeof (GraphALVertex));
    G->vertices = G->vertices + 1;
    vertex->index = G->vertices;
    G->size = G->size + 1;
    return 1;
}

// void graph_vertex_destroy(GraphALVertex *vertex)
// {

// }

// void GraphAL_vertex_remove(GraphAL* G)
// {

// }

// int GraphAL_edge_insert(GraphAL* G, GraphALVertex *vertex_source, GraphALVertex *vertex_destination, unsigned long weight)
// {
    
// }
