#include "binary_tree.h"

extern void binary_tree_print(BinaryTree *tree);

int main()
{
    BinaryTree binary_tree = binary_tree_construct();
    char x = 'c';
    binary_tree.root = binary_tree.insert(&binary_tree, &x, 1);

    binary_tree_print(&binary_tree);
}
