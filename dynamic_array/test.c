#include "dynamic_array.h"

extern void dynamic_array_print(struct DynamicArray *dynamic_array);

int main()
{
    struct DynamicArray dynamic_array = dynamic_array_construct(sizeof (int), 10, 1.6);
    int a = 10;
    int b = 20;
    int c = 30;
    int d = 40;
    dynamic_array.push_front(&dynamic_array, &a);
    dynamic_array.push_front(&dynamic_array, &b);
    // dynamic_array.push_front(&dynamic_array, &c);
    // dynamic_array.push_front(&dynamic_array, &d);
    // for(size_t i = 0; i < 10; i++) {
    //     random = rand() % 1000;
    //     dynamic_array_push_back(dynamic_array, random);
    // }
    dynamic_array_print(&dynamic_array);
}
