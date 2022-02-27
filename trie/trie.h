#ifndef TRIE_H
#define TRIE_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct TrieNode {
    char data;
    bool terminal;
    struct TrieNode *children[256];
};

struct Trie {
    struct TrieNode *root;
    size_t size;
    struct TrieNode *(*search)(struct Trie *trie, char data);
    void (*insert)(struct Trie *trie, char data);
    void (*remove)(struct Trie *trie, char data);
};

struct Trie trie_construct();

#endif
