#include "trie.h"

int main()
{
    struct Trie trie = trie_construct();
    trie.insert(&trie, "Sumit");
}
