#include "binary_search_tree.h"

extern void binary_search_tree_print(struct BinarySearchTree *tree);

int main()
{
    struct BinarySearchTree binary_search_tree = binary_search_tree_construct(sizeof (char));
    char x = 23;
    char y = 211;
    char z = 1;
    char a = 22;
    binary_search_tree_insert(&binary_search_tree, &x);
    binary_search_tree_insert(&binary_search_tree, &y);
    binary_search_tree_insert(&binary_search_tree, &z);
    binary_search_tree_insert(&binary_search_tree, &a);
    binary_search_tree_print(&binary_search_tree);
}
