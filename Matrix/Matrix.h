#ifndef MATRIX_H
#define MATRIX_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct Matrix {
    void** array;
    size_t data_size;
    size_t rows;
    size_t columns;
} Matrix;

Matrix* Matrix_create(size_t data_size, size_t rows, size_t columns);
void Matrix_destroy(Matrix* M);

void Matrix_insert(Matrix* M, size_t rows, size_t columns, void* data);
void Matrix_remove(Matrix* M, size_t rows, size_t columns);

#endif
