#include "trie.h"

extern void trie_print(Trie *T);

int main()
{
    Trie tree = trie_construct();
    // char *s = "aasda";
    trie_insert(&tree, "ssdasd");
    trie_insert(&tree, "ssdaassd");
    trie_print(&tree);
}
