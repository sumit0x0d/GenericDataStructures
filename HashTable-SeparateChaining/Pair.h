#ifndef PAIR_H
#define PAIR_H

#include <stdlib.h>

typedef struct Pair {
    void* key;
    void* value;
    struct Pair* next;
} Pair;

static Pair* Pair_create(size_t key_size, size_t value_size)
{
    Pair* P = (Pair*)malloc(sizeof (Pair));
    if(!P) {
        return NULL;
    }
    P->key = malloc(key_size);
    if(!P->key) {
        free(P);
        return NULL;
    }
    P->value = malloc(value_size);
    if(!P->value) {
        free(P->key);
        free(P);
        return NULL;
    }
    return P;
}

static void Pair_destroy(Pair *P)
{
    free(P->key);
    P->key = NULL;
    free(P->value);
    P->value = NULL;
    free(P);
    P = NULL;
}

#endif
