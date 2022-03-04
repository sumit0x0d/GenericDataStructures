#include "trie.h"
#include "trie_print.h"

int main()
{
    struct Trie tree = trie_construct();
    char *s = "a";
    tree.insert(&tree, s);
    // trie_print(&tree);
}
