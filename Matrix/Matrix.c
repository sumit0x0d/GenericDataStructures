#include "Matrix.h"

Matrix* Matrix_create(size_t data_size, size_t rows, size_t columns);
void Matrix_destroy(Matrix* M);

void Matrix_insert(Matrix* M, size_t rows, size_t columns, void* data);
void Matrix_remove(Matrix* M, size_t rows, size_t columns);

Matrix* Matrix_create(size_t data_size, size_t rows, size_t columns)
{
    Matrix* M = malloc(sizeof (Matrix));
    if(!M) {
        return NULL;
    }
    M->array = malloc(rows * sizeof (void*));
    if(!M->array) {
        free(M);
        M = NULL;
        return NULL;
    }
    for(size_t i = 0; i < rows; i++) {
        M->array[i] = malloc(data_size * columns);
        if(!M->array[i]) {
            for(size_t j = 0; j < i; j++) {
                free(M->array[j]);
                M->array[j] = NULL;
            }
            free(M->array);
            M->array = NULL;
            free(M);
            M = NULL;
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

void Matrix_insert(Matrix* M, size_t rows, size_t columns, void* data)
{
    memcpy((char*)M->array[rows] + columns, data, M->data_size);
}

void Matrix_remove(Matrix* M, size_t rows, size_t columns)
{
    memset((char*)M->array[rows] + columns, 0, M->data_size);
}
