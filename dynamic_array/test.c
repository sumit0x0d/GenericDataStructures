#include "dynamic_array.h"

extern void dynamic_array_print(struct DynamicArray *da);

int main()
{
    struct DynamicArray dynamic_array = dynamic_array_construct(sizeof (int), 1.5);
    for(long i = 0; i < 10; i++)
        dynamic_array.push_back(&dynamic_array, &i);
    // dynamic_array.push_front(&dynamic_array, &c);
    // dynamic_array.push_front(&dynamic_array, &d);
    // for(size_t i = 0; i < 10; i++) {
    //     random = rand() % 1000;
    //     dynamic_array_push_back(dynamic_array, random);
    // }
    dynamic_array_print(&dynamic_array);
}
