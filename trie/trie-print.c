#include "trie.h"

#include <stdio.h>

void print_t(TrieNode* node, unsigned char* pr, int length)
{
    unsigned char newpr[length+2];
    memcpy(newpr, pr, length);
    newpr[length+1] = 0;

    if(node->terminal)
        printf("%s", pr);
    
    for(int i= 0; i < 128; i++) {
        if(node->children[i] == NULL) {
            newpr[length] = i;
            print_t(node->children[i], newpr, length+1);
        }
    }
}

void trie_print(Trie *T)
{
    if(!T->size) return;
    // TrieNode* node = tree->root;
    print_t(T->root, NULL, 0);
    // do {
    // } while(node);
}
