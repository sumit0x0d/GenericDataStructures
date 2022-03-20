#include "graph.h"

bool graph_vertex_insert(Graph *G, void *data);
bool graph_vertex_remove(Graph *G);
bool graph_edge_insert(Graph *G, Vertex vertex_source, Vertex vertex_destination);
bool graph_edge_remove(Graph *G, Vertex vertex_source, Vertex vertex_destination);

Graph graph_construct(size_t data_type_size)
{
    Graph G;

    G.adjacency_list = NULL;
    G.data_type_size = data_type_size;
    G.vertices = 0;

    return G;
}

// void graph_destruct()
// {

// }

void adjacency_list_construct(Vertex *adjacency_list)
{
    if(!adjacency_list) {
        adjacency_list = malloc(sizeof (Vertex));
        if(!adjacency_list) return;
    }
}

Vertex *vertex_construct(size_t data_type_size)
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

void vertex_destruct(Vertex *vertex)
{

}

bool graph_vertex_insert(Graph *G, void *data)
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
    
    Vertex *vertex = vertex_construct(G->data_type_size);
    if(!vertex) return false;

    memcpy(vertex->data, data, G->data_type_size);

    memcpy(G->adjacency_list + (sizeof (Vertex) * G->vertices), vertex, sizeof (Vertex));

    G->vertices = G->vertices + 1;
    vertex->index = G->vertices;

    return true;
}

// void graph_vertex_destruct(Vertex *vertex)
// {

// }

// void graph_vertex_remove(Graph *G)
// {

// }

// void graph_edge_insert(Graph *G, Vertex vertex_source, Vertex vertex_destination)
// {
    
// }
