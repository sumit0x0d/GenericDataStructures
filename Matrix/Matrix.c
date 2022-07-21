#include "Matrix.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct Matrix {
    void** array;
    size_t data_size;
    size_t row_count;
    size_t column_count;
};

Matrix* Matrix_Create(size_t data_size, size_t row_count, size_t column_count)
{
    Matrix* M = (Matrix*)malloc(sizeof (Matrix));
    if(!M) {
        return NULL;
    }
    M->array = (void**)malloc(row_count * sizeof (void*));
    if(!M->array) {
        free(M);
        return NULL;
    }
    for(size_t i = 0; i < row_count; i++) {
        M->array[i] = malloc(data_size * column_count);
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
    M->row_count = row_count;
    M->column_count = column_count;
    return M;
}

void Matrix_Destroy(Matrix* M)
{
    for(size_t i = 0; i < M->row_count; i++) {
        free(M->array[i]);
        M->array[i] = NULL;
    }
    free(M->array);
    M->array = NULL;
    free(M);
    M = NULL;
}

static inline void* DataAt(Matrix* M, size_t row_count, size_t column_count)
{
    return (char*)M->array[row_count] + column_count;
}

void Matrix_Insert(Matrix* M, size_t row_count, size_t column_count, void* data)
{
    memcpy(DataAt(M, row_count, column_count), data, M->data_size);
}

void Matrix_Remove(Matrix* M, size_t row_count, size_t column_count)
{
    memset(DataAt(M, row_count, column_count), 0, M->data_size);
}
