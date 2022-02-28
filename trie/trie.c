#include "trie.h"

struct TrieNode *search(struct Trie *trie, char *string);
void insert(struct Trie *trie, char *string);
void remove(struct Trie *trie, char *string);

struct Trie trie_construct()
{
    struct Trie trie;

    trie.root = NULL;
    trie.size = 0;

    trie.search = search;
    trie.insert = insert;
    trie.remove = remove;

    return trie;
}

struct TrieNode *node_construct(char character)
{
    struct TrieNode *node = malloc(sizeof (struct TrieNode));
    if(!node) return;

    node->character = character;

    node->terminal = false;
    memset(node->children, 0, 128);

    return node;
}

void insert(struct Trie *trie, char *string)
{
    struct TrieNode *node = trie->root;
    char character = *string;

    size_t length = strlen(string);
    for(size_t i = 0; i < length; i++) {
        if(node->children[string[i]] == NULL)
            node->children[string[i]] = node_construct(string[i]);
    }
    if(node->terminal)
        return;
    else
        node->terminal = true;

    ++trie->size;
}

void node_distruct(struct Trie *trie, char character)
{
    struct Trie *node = trie->root;
    free(node);
}
