#ifndef TRIE_H
#define TRIE_H

#include <stdbool.h>
#include <stddef.h>

typedef struct Trie Trie;

Trie *trie_Create();
char* trie_Search(Trie *trie, char* string);
int trie_Insert(Trie *trie, char* string);
int trie_Remove(Trie *trie, char* string);

#endif
