#ifndef TRIE_H
#define TRIE_H

#include <stddef.h>
#include <stdbool.h>

struct TrieNode {
    void *data;
    size_t data_type_size;
    bool terminal;
    struct TrieNode *next;
};

struct Trie {
    struct TrieNode *root;
    size_t size;
    void *(*search)(struct Trie *trie, void *data, size_t data_type_size);
    void (*insert)(struct Trie *trie, void *data, size_t data_type_size);
    void (*remove)(struct Trie *trie, void *data, size_t data_type_size);
};

struct Trie trie_construct();

#endif
