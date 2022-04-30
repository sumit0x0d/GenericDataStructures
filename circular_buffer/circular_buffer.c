#include "circular_buffer.h"

CircularBuffer* CircularBuffer_create(size_t data_size, size_t capacity);
void CircularBuffer_destroy(CircularBuffer *CB);

bool CircularBuffer_push(CircularBuffer* CB, void* data);
bool CircularBuffer_pop(CircularBuffer* CB);

CircularBuffer* CircularBuffer_create(size_t data_size, size_t capacity)
{
    CircularBuffer* CB = malloc(sizeof (CircularBuffer));
    if(!CB) {
        return NULL;
    }
    CB->array = malloc(data_size * capacity);
    if(!CB->array) {
        free(CB);
        CB = NULL;
        return NULL;
    }
    CB->data_size = data_size;
    CB->begin = 0;
    CB->end = 0;
    CB->capacity = capacity;
    CB->size = 0;
    return CB;
}

void CircularBuffer_destroy(CircularBuffer *CB)
{
    free(CB->array);
    CB->array = NULL;
    free(CB);
    CB = NULL;
}

bool CircularBuffer_push(CircularBuffer* CB, void* data)
{
    memcpy((char*)CB->array + (CB->data_size * CB->end), data, sizeof (CB->data_size));
    CB->end = (CB->end + 1) % CB->capacity;
    CB->size = CB->size + 1;
}

bool CircularBuffer_pop(CircularBuffer* CB)
{
    CB->begin = (CB->begin + 1) % CB->capacity;
    CB->size = CB->size - 1;
}
