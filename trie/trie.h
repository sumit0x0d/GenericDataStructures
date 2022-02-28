#ifndef TRIE_H
#define TRIE_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct TrieNode {
    char character;
    bool terminal;
    struct TrieNode *children[128];
};

struct Trie {
    struct TrieNode *root;
    size_t size;
    struct TrieNode *(*search)(struct Trie *trie, char *string);
    void (*insert)(struct Trie *trie, char *string);
    void (*remove)(struct Trie *trie, char *string);
};

struct Trie trie_construct();

#endif
