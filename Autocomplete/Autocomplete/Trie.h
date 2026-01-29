#pragma once

#include <string>
#include <vector>
#include "TrieNode.h"

// Класс префиксного дерева (Trie) для хранения словаря
class Trie
{
private:
    TrieNode* root;

    // Рекурсивно собирает все слова, начинающиеся с текущего узла
    void collectWords(
        TrieNode* node,
        const std::string& prefix,
        std::vector<std::string>& results
    ) const;

    //  Рекурсивно освобождает память
    void freeNode(TrieNode* node);


public:
    Trie();
    ~Trie();

    // Добавление слова в словарь
    void insert(const std::string& word);

    // Проверка наличия префикса
    bool startsWith(const std::string& prefix) const;

    // Получение вариантов автодополнения
    std::vector<std::string> autocomplete(const std::string& prefix) const;
};

