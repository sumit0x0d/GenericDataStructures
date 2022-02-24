#include "binary_search_tree.h"
#include "binary_search_tree_traversal.h"

int main()
{
    // srand(time(0));
    // int random;
    struct BinarySearchTree binary_search_tree = binary_search_tree_construct();
    char x = 23;
    char y = 211;
    char z = 1;
    char a = 22;
    binary_search_tree.insert(&binary_search_tree, &x, 1);
    binary_search_tree.insert(&binary_search_tree, &y, 1);
    binary_search_tree.insert(&binary_search_tree, &z, 1);
    binary_search_tree.insert(&binary_search_tree, &a, 1);
    binary_tree_print(&binary_search_tree);
}
