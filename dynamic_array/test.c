#include "dynamic_array.h"

#include <time.h>

int main()
{
    srand(time(0));
    int random;
    struct DynamicArray *dynamic_array = dynamic_array_construct(10, 1.6);
    dynamic_array_push_back(dynamic_array, 10);
    for(size_t i = 0; i < 10; i++) {
        random = rand() % 1000;
        dynamic_array_push_back(dynamic_array, random);
    }
    dynamic_array_print(dynamic_array);
}
