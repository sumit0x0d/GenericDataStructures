#include "red-black_tree.h"

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // srand(time(0));
    // int random;
    struct BinaryTree red_black_tree = red_black_tree_construct();
    char x = 'c';
    red_black_tree.root = red_black_tree.insert(&red_black_tree, &x, 1);
    // tree->root->left = binary_tree_insert(binary_tree, &y, 4);
    // for(int i = 0; i < 10; i++) {
        // random = rand()%10;
        // int x[24] = {10, 30, 20, 90, 5, 1, 8, 6, 11, 99, 21, 223, 23, 24};
        // for(int i = 0; i < 10; i++)
        //     binary_search_tree_insert(&binary_tree, &x[i], sizeof (int));
        // binary_search_tree_insert(binary_tree, &y, sizeof x);
    // }
    // binary_search_tree_insert(binary_tree, &y, 4);
    // binary_search_tree_insert(binary_search_tree, 100);
    // binary_search_tree_insert(binary_search_tree, 200);
    // binary_search_tree_insert(binary_search_tree, 300);
    binary_tree_print(&red_black_tree);
}
