#include "Matrix.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct Matrix {
    void** array;
    size_t data_size;
    size_t rows;
    size_t columns;
};

Matrix* Matrix_create(size_t data_size, size_t rows, size_t columns)
{
    Matrix* M = (Matrix*)malloc(sizeof (Matrix));
    if(!M) {
        return NULL;
    }
    M->array = (void**)malloc(rows * sizeof (void*));
    if(!M->array) {
        free(M);
        return NULL;
    }
    for(size_t i = 0; i < rows; i++) {
        M->array[i] = malloc(data_size * columns);
        if(!M->array[i]) {
            for(size_t j = 0; j < i; j++) {
                free(M->array[j]);
            }
            free(M->array);
            free(M);
            return NULL;
        }
    }
    M->data_size = data_size;
    M->rows = rows;
    M->columns = columns;
    return M;
}

void Matrix_destroy(Matrix* M)
{
    for(size_t i = 0; i < M->rows; i++) {
        free(M->array[i]);
        M->array[i] = NULL;
    }
    free(M->array);
    M->array = NULL;
    free(M);
    M = NULL;
}

static inline void* data_at(Matrix* M, size_t rows, size_t columns)
{
    return (char*)M->array[rows] + columns;
}

void Matrix_insert(Matrix* M, size_t rows, size_t columns, void* data)
{
    memcpy(data_at(M, rows, columns), data, M->data_size);
}

void Matrix_remove(Matrix* M, size_t rows, size_t columns)
{
    memset(data_at(M, rows, columns), 0, M->data_size);
}
