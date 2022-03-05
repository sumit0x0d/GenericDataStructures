#include "trie.h"

#include <stdio.h>

void trie_print(struct Trie *tree)
{
    if(!tree->size) return;
    struct TrieNode *node = tree->root;
    
    do {
        printf("%c ", node->character);
    } while(node);
}
