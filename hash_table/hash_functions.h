#ifndef HASH_FUNCTIONS_H
#define HASH_FUNCTIONS_H

#include "helpers.h"

void separate_chaining();
void linear_probing();
void quadratic_probing();
void double_hashing();

size_t hash_mod(size_t capacity, int key)
{
    return (size_t)(key % capacity);
}

#endif
