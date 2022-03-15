#include "graph.h"

void vertex_insert(struct Graph *G, void *data);
void vertex_remove(struct Graph *G);
void edge_insert(struct Graph *G, struct Vertex vertex_source, struct Vertex vertex_destination);
void edge_remove(struct Graph *G, struct Vertex vertex_source, struct Vertex vertex_destination);

struct Graph graph_construct(size_t data_type_size)
{
    struct Graph G;

    G.adjacency_list = malloc(sizeof (struct Vertex));
    G.data_type_size = data_type_size;
    G.vertices = 0;

    G.vertex_insert = vertex_insert;
    // G.vertex_remove = vertex_remove;
    // G.edge_insert = edge_insert;
    // G.edge_remove = edge_remove;

    return G;
}

// void graph_destruct()
// {

// }

struct Vertex *vertex_construct(void *data, size_t data_type_size)
{
    struct Vertex *vertex = malloc(sizeof (struct Vertex));
    if(!vertex) return NULL;

    vertex->data = malloc(data_type_size);
    if(!vertex->data) {
        free(vertex);
        vertex = NULL;
        return NULL;
    }

    memcpy(vertex->data, data, data_type_size);

    vertex->weight = 0;
    vertex->edge = NULL;

    return vertex;
}

void vertex_insert(struct Graph *G, void *data)
{
    struct Vertex *vertex = vertex_construct(data, G->data_type_size);
    G->vertices = G->vertices + 1;
    vertex->index = G->vertices;
    G->adjacency_list = realloc(G->adjacency_list, sizeof (struct Vertex) * G->vertices);
    memcpy(G->adjacency_list + sizeof (struct Vertex) * (G->vertices - 1), vertex, sizeof (struct Vertex));
}

// void vertex_destruct(struct Vertex *vertex)
// {

// }

// void vertex_remove(struct Graph *G)
// {

// }

// void edge_insert(struct Graph *G, struct Vertex vertex_source, struct Vertex vertex_destination)
// {
    
// }
