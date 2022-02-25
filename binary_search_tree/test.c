#include "binary_search_tree.h"
#include "binary_search_tree_print.h"

int main()
{
    struct BinarySearchTree binary_search_tree = binary_search_tree_construct();
    char x = 23;
    char y = 211;
    char z = 1;
    char a = 22;
    binary_search_tree.insert(&binary_search_tree, &x, 1);
    binary_search_tree.insert(&binary_search_tree, &y, 1);
    binary_search_tree.insert(&binary_search_tree, &z, 1);
    binary_search_tree.insert(&binary_search_tree, &a, 1);
    binary_search_tree_print(&binary_search_tree);
}
