#include "graph.h"

bool graph_vertex_insert(struct Graph *G, void *data);
bool graph_vertex_remove(struct Graph *G);
bool graph_edge_insert(struct Graph *G, struct Vertex vertex_source, struct Vertex vertex_destination);
bool graph_edge_remove(struct Graph *G, struct Vertex vertex_source, struct Vertex vertex_destination);

struct Graph graph_construct(size_t data_type_size)
{
    struct Graph G;

    G.adjacency_list = NULL;
    G.data_type_size = data_type_size;
    G.vertices = 0;

    return G;
}

// void graph_destruct()
// {

// }

void adjacency_list_construct(struct Vertex *adjacency_list)
{
    if(!adjacency_list) {
        adjacency_list = malloc(sizeof (struct Vertex));
        if(!adjacency_list) return;
    }
}

struct Vertex *vertex_construct(size_t data_type_size)
{
    struct Vertex *vertex = malloc(sizeof (struct Vertex));
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

bool graph_vertex_insert(struct Graph *G, void *data)
{
    struct Vertex *vertex = vertex_construct(G->data_type_size);
    if(!vertex) return false;

    memcpy(vertex->data, data, G->data_type_size);

    if(!G->adjacency_list) {
        G->adjacency_list = malloc(sizeof (struct Vertex));
        if(!G->adjacency_list) return false;
    }
    else {
        struct Vertex *adjacency_list = realloc(G->adjacency_list, sizeof (struct Vertex) * (G->vertices + 1));
        if(!adjacency_list) return false;

        G->adjacency_list = adjacency_list;
    }

    memcpy(G->adjacency_list + (sizeof (struct Vertex) * G->vertices), vertex, sizeof (struct Vertex));

    G->vertices = G->vertices + 1;
    vertex->index = G->vertices;

    return true;
}

// void graph_vertex_destruct(struct Vertex *vertex)
// {

// }

// void graph_vertex_remove(struct Graph *G)
// {

// }

// void graph_edge_insert(struct Graph *G, struct Vertex vertex_source, struct Vertex vertex_destination)
// {
    
// }
