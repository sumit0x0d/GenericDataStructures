#include "graph.h"

void vertex_insert(struct Graph *graph, void *data);
void vertex_remove(struct Graph *graph);
void edge_insert(struct Graph *graph, struct Vertex vertex_source, struct Vertex vertex_destination);
void edge_remove(struct Graph *graph, struct Vertex vertex_source, struct Vertex vertex_destination);

struct Graph graph_construct(size_t data_type_size)
{
    struct Graph graph;

    graph.adjacency_list = malloc(sizeof (struct Vertex));
    graph.data_type_size = data_type_size;
    graph.vertices = 0;

    graph.vertex_insert = vertex_insert;
    // graph.vertex_remove = vertex_remove;
    // graph.edge_insert = edge_insert;
    // graph.edge_remove = edge_remove;

    return graph;
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
    vertex->next = NULL;

    return vertex;
}

void vertex_insert(struct Graph *graph, void *data)
{
    struct Vertex *vertex = vertex_construct(data, graph->data_type_size);
    graph->vertices = graph->vertices + 1;
    vertex->index = graph->vertices;
    graph->adjacency_list = realloc(graph->adjacency_list, sizeof (struct Vertex) * graph->vertices);
    memcpy(graph->adjacency_list + sizeof (struct Vertex) * (graph->vertices - 1), vertex, sizeof (struct Vertex));
}

// void vertex_destruct(struct Vertex *vertex)
// {

// }

// void vertex_remove(struct Graph *graph)
// {

// }

// void edge_insert(struct Graph *graph, struct Vertex vertex_source, struct Vertex vertex_destination)
// {
    
// }
