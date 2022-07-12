#ifndef VERTEX_H
#define VERTEX_H

#include <stdlib.h>

typedef struct Vertex {
    void* data;
    size_t index;
    unsigned long weight;
    struct Vertex *edge;
} Vertex;

static inline Vertex *Vertex_create(size_t data_size)
{
    Vertex* V = (Vertex*)malloc(sizeof (Vertex));
    if(!V) {
        return NULL;
    }
    V->data = (void*)malloc(data_size);
    if(!V->data) {
        free(V);
        return NULL;
    }
    V->weight = 0;
    V->edge = NULL;
    return V;
}

#endif
