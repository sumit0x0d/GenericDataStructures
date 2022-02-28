#ifndef TRIE_PRINT_H
#define TRIE_PRINT_H

#include "trie.h"

#include <stdio.h>

void trie_print(struct Trie *trie)
{
    if(!trie->size) return;
    struct TrieNode *node = trie->root;
    
    do {
        printf("%c", node->character);
    } while(node);
}

#endif
