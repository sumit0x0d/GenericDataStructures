#include "avl_tree.h"

extern void avl_tree_print(AVLTree *tree);

int main()
{
    // srand(time(0));
    // int random;
    AVLTree avl_tree = avl_tree_construct();
    char x = 'c';
    avl_tree.insert(&avl_tree, &x, 1);
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
    avl_tree_print(&avl_tree);
}
