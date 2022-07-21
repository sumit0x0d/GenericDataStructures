#ifndef MATRIX_H
#define MATRIX_H

#include <stdbool.h>
#include <stddef.h>

typedef struct Matrix Matrix;

Matrix* Matrix_Create(size_t data_size, size_t row_count, size_t column_count);
void Matrix_Destroy(Matrix* M);

void Matrix_Insert(Matrix* M, size_t row_count, size_t column_count, void* data);
void Matrix_Remove(Matrix* M, size_t row_count, size_t column_count);

#endif
