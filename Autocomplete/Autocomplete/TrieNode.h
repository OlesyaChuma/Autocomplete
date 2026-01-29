#pragma once
#include <map>

// Узел префиксного дерева (Trie)
class TrieNode
{
public:
    // Признак того, что в этом узле заканчивается слово
    bool isEndOfWord;

    // Потомки текущего узла (ключ — символ)
    std::map<char, TrieNode*> children;

    TrieNode();
};

