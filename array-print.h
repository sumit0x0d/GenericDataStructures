#include "deque-array/deque-array.h"
#include "dynamic_array/dynamic_array.h"
#include "queue-array/queue-array.h"
#include "stack-array/stack-array.h"
#include "hash_table-separate_chaining/hash_table-separate_chaining.h"


#include "data-print.h"

enum {
    DEQUE_ARRAY,
    DYNAMIC_ARRAY,
    QUEUE_ARRAY,
    STACK_ARRAY,
};

void queue_array_print(QueueArray *Q, int data_type)
{
    if(!Q->array) return;

    printf("[Queue (Array)]");

    printf("\n[Data]\t: ");
    for(size_t i = Q->front; i < Q->back; i++)
        data_print(((char *)Q->array + (i * Q->data_size)), data_type);

    printf("\n[Size]\t: %zu\n", Q->size);
}

void hash_table_separate_chaining_print(HashTable *HT, int key_type, int value_type)
{
    if(!HT->array) return;
    printf("[Hash Table (Seprate Chaining)]");

    printf("\n[Data]\t: ");
    for(size_t i = 0; i < HT->buckets; i++) {
        data_print(((char *)HT->array->key + (i * HT->key_size)), key_type);
        data_print(((char *)HT->array->value + (i * HT->value_size)), value_type);
    }

    printf("\n[Size]\t: %zu\n", HT->size);

}

void stack_array_print(StackArray *S, int data_type)
{
    if(!S->array) return;

    printf("[Stack (Array)]");

    printf("\n[Data]\t: ");
    for(size_t i = 0; i < S->top; i++)
        data_print(((char *)S->array + (i * S->data_size)), data_type);

    printf("\n[Size]\t: %zu\n", S->size);
}
