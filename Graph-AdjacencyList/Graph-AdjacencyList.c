#include "Graph-AdjacencyList.h"
#include "Vertex.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct GraphAL {
    struct Vertex* adjacency_list;
    size_t data_size;
    unsigned long vertex_count;
    size_t size;
};

GraphAL* GraphAL_Create(size_t data_size)
{
    GraphAL* G = (GraphAL*)malloc(sizeof (GraphAL));
    if(!G) {
        return NULL;
    }
    G->adjacency_list = NULL;
    G->data_size = data_size;
    G->vertex_count = 0;
    G->size = 0;
    return G;
}

void GraphAL_Destroy(GraphAL* G)
{
    free(G->adjacency_list);
    G->adjacency_list = NULL;
    G->vertex_count = 0;
    G->size = 0;
}

// void adjacency_list_Create(Vertex *adjacency_list)
// {
//     if(!adjacency_list) {
//         adjacency_list = malloc(sizeof (Vertex));
//         if(!adjacency_list) return;
//     }
// }

// Vertex *GraphAL_vertex_Search(GraphAL* G, void* data)
// {
//     Vertex *vertex = G->adjacency_list;

//     for(unsigned long i = 0; i < G->vertex_count; i++) {
//         if(vertex->data == )

//     }
// }


// void vertex_Destroy(Vertex *vertex)
// {

// }

int GraphAL_vertex_Insert(GraphAL* G, void* data)
{
    if(!G->adjacency_list) {
        G->adjacency_list = (Vertex*)malloc(sizeof (Vertex));
        if(!G->adjacency_list) {
            return false;
        }
    }
    else {
        Vertex* adjacency_list = (Vertex*)realloc(G->adjacency_list,
            sizeof (Vertex) * (G->vertex_count + 1));
        if(!adjacency_list) {
            return false;
        }
        G->adjacency_list = adjacency_list;
    }
    Vertex *vertex = Vertex_Create(G->data_size);
    if(!vertex) {
        return false;
    }
    memcpy(vertex->data, data, G->data_size);
    memcpy(G->adjacency_list + (sizeof (Vertex) * G->vertex_count), vertex,
        sizeof (Vertex));
    G->vertex_count = G->vertex_count + 1;
    vertex->index = G->vertex_count;
    G->size = G->size + 1;
    return true;
}

// void graph_vertex_Destroy(Vertex *vertex)
// {

// }

// void GraphAL_vertex_Remove(GraphAL* G)
// {

// }

// int GraphAL_edge_Insert(GraphAL* G, Vertex *vertex_source, Vertex *vertex_destination, unsigned long weight)
// {
    
// }
