#include "graph-adjacency_list.h"

GraphAdjacencyList graph_adjacency_list_create(int data_type, size_t data_type_size);
void graph_distroy(GraphAdjacencyList *G);

void *graph_adjacency_list_vertices(GraphAdjacencyList *G);
size_t graph_adjacency_list_size(GraphAdjacencyList *G);

static Vertex *vertex_create(size_t data_type_size);
// static void vertex_distroy(Vertex *vertex);

bool graph_adjacency_list_vertex_insert(GraphAdjacencyList *G, void *data);
bool graph_adjacency_list_vertex_remove(GraphAdjacencyList *G, void *data);
bool graph_adjacency_list_edge_insert(GraphAdjacencyList *G, Vertex *vertex_source, Vertex *vertex_destination, unsigned long weight);
bool graph_adjacency_list_edge_remove(GraphAdjacencyList *G, Vertex *vertex_source, Vertex *vertex_destination);

GraphAdjacencyList graph_adjacency_list_create(int data_type, size_t data_type_size)
{
    GraphAdjacencyList G;

    G.adjacency_list = NULL;
    G.data_type = data_type;
    G.data_type_size = data_type_size;
    G.vertices = 0;
    G.size = 0;

    return G;
}

// void graph_distroy()
// {

// }

// void adjacency_list_create(Vertex *adjacency_list)
// {
//     if(!adjacency_list) {
//         adjacency_list = malloc(sizeof (Vertex));
//         if(!adjacency_list) return;
//     }
// }

// Vertex *graph_adjacency_list_vertex_search(GraphAdjacencyList *G, void *data)
// {
//     Vertex *vertex = G->adjacency_list;

//     for(unsigned long i = 0; i < G->vertices; i++) {
//         if(vertex->data == )

//     }
// }

Vertex *vertex_create(size_t data_type_size)
{
    Vertex *vertex = malloc(sizeof (Vertex));
    if(!vertex) return NULL;

    vertex->data = malloc(data_type_size);
    if(!vertex->data) {
        free(vertex);
        vertex = NULL;
        return NULL;
    }

    vertex->weight = 0;
    vertex->edge = NULL;

    return vertex;
}

// void vertex_distroy(Vertex *vertex)
// {

// }

bool graph_adjacency_list_vertex_insert(GraphAdjacencyList *G, void *data)
{
    if(!G->adjacency_list) {
        G->adjacency_list = malloc(sizeof (Vertex));
        if(!G->adjacency_list) return false;
    }
    else {
        Vertex *adjacency_list = realloc(G->adjacency_list, sizeof (Vertex) * (G->vertices + 1));
        if(!adjacency_list) return false;

        G->adjacency_list = adjacency_list;
    }

    Vertex *vertex = vertex_create(G->data_type_size);
    if(!vertex) return false;

    memcpy(vertex->data, data, G->data_type_size);

    memcpy(G->adjacency_list + (sizeof (Vertex) * G->vertices), vertex, sizeof (Vertex));

    G->vertices = G->vertices + 1;
    vertex->index = G->vertices;

    G->size = G->size + 1;

    return true;
}

// void graph_vertex_distroy(Vertex *vertex)
// {

// }

// void graph_adjacency_list_vertex_remove(GraphAdjacencyList *G)
// {

// }

// bool graph_adjacency_list_edge_insert(GraphAdjacencyList *G, Vertex *vertex_source, Vertex *vertex_destination, unsigned long weight)
// {
    
// }
