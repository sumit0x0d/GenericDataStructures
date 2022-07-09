#ifndef TRIE_H
#define TRIE_H

#include <stdbool.h>
#include <stddef.h>

typedef struct Trie Trie;

Trie *trie_create();
char* trie_search(Trie *trie, char* string);
int trie_insert(Trie *trie, char* string);
int trie_remove(Trie *trie, char* string);

#endif
