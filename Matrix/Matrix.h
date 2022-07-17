#ifndef MATRIX_H
#define MATRIX_H

#include <stdbool.h>
#include <stddef.h>

typedef struct Matrix Matrix;

Matrix* MatrixCreate(size_t data_size, size_t row_count, size_t column_count);
void MatrixDestroy(Matrix* M);

void MatrixInsert(Matrix* M, size_t row_count, size_t column_count, void* data);
void MatrixRemove(Matrix* M, size_t row_count, size_t column_count);

#endif
