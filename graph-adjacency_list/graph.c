#include "graph.h"

void insert_vertex(struct Graph *graph, void *data);
void remove_vertex(struct Graph *graph);
void insert_edge(struct Graph *graph, struct Vertex vertex_source, struct Vertex vertex_destination);
void remove_edge(struct Graph *graph, struct Vertex vertex_source, struct Vertex vertex_destination);

struct Graph graph_construct(size_t data_type_size)
{
    struct Graph graph;

    graph.adjacency_list = NULL;
    graph.data_type_size = data_type_size;
    graph.vertices = 0;

    graph.insert_vertex = insert_vertex;
    graph.remove_vertex = remove_vertex;
    graph.insert_edge = insert_edge;
    graph.remove_edge = remove_edge;

    return graph;
}

void graph_destruct()
{

}

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

    vertex->weight = 0;
    vertex->next = NULL;

    return vertex;
}

void insert_vertex(struct Graph *graph, void *data)
{
    struct Vertex *vertex = vertex_construct(data, graph->data_type_size);
    graph->vertices = graph->vertices + 1;
    graph->adjacency_list = realloc(graph->adjacency_list, sizeof (struct Vertex) * graph->vertices);
    graph->adjacency_list[graph->vertices - 1] = vertex;
}

// void insert_edge(struct Graph *graph, struct Vertex vertex_source, struct Vertex vertex_destination)
// {
//     graph->adjacency_list[vertex_source]->next = vertex_destination;
// }
