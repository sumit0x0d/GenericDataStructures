#include "Graph-AdjacencyList.h"

GraphAL* GraphAL_create(size_t data_size);
void GraphAL_destroy(GraphAL* G);

void* GraphAL_vertices(GraphAL* G);
size_t GraphAL_size(GraphAL* G);

static Vertex *vertex_create(size_t data_size);
// static void vertex_destinationroy(Vertex *vertex);

bool GraphAL_vertex_insert(GraphAL* G, void* data);
bool GraphAL_vertex_remove(GraphAL* G, void* data);
bool GraphAL_edge_insert(GraphAL* G, Vertex *vertex_source, Vertex *vertex_destination, unsigned long weight);
bool GraphAL_edge_remove(GraphAL* G, Vertex *vertex_source, Vertex *vertex_destination);

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

// void adjacency_list_create(Vertex *adjacency_list)
// {
//     if(!adjacency_list) {
//         adjacency_list = malloc(sizeof (Vertex));
//         if(!adjacency_list) return;
//     }
// }

// Vertex *GraphAL_vertex_search(GraphAL* G, void* data)
// {
//     Vertex *vertex = G->adjacency_list;

//     for(unsigned long i = 0; i < G->vertices; i++) {
//         if(vertex->data == )

//     }
// }

Vertex *vertex_create(size_t data_size)
{
    Vertex *vertex = malloc(sizeof (Vertex));
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

// void vertex_destinationroy(Vertex *vertex)
// {

// }

bool GraphAL_vertex_insert(GraphAL* G, void* data)
{
    if(!G->adjacency_list) {
        G->adjacency_list = malloc(sizeof (Vertex));
        if(!G->adjacency_list) {
            return false;
        }
    }
    else {
        Vertex *adjacency_list = realloc(G->adjacency_list, sizeof (Vertex) * (G->vertices + 1));
        if(!adjacency_list) {
            return false;
        }
        G->adjacency_list = adjacency_list;
    }
    Vertex *vertex = vertex_create(G->data_size);
    if(!vertex) {
        return false;
    }
    memcpy(vertex->data, data, G->data_size);
    memcpy(G->adjacency_list + (sizeof (Vertex) * G->vertices), vertex, sizeof (Vertex));
    G->vertices = G->vertices + 1;
    vertex->index = G->vertices;
    G->size = G->size + 1;
    return true;
}

// void graph_vertex_destinationroy(Vertex *vertex)
// {

// }

// void GraphAL_vertex_remove(GraphAL* G)
// {

// }

// bool GraphAL_edge_insert(GraphAL* G, Vertex *vertex_source, Vertex *vertex_destination, unsigned long weight)
// {
    
// }
