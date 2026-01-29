#include "Trie.h"

Trie::Trie()
{
    root = new TrieNode();
}

Trie::~Trie()
{
    freeNode(root);
}

 // Освобождение памяти всех узлов дерева
void Trie::freeNode(TrieNode* node)
{
    if (!node)
        return;

    for (auto& pair : node->children)
    {
        freeNode(pair.second);
    }

    delete node;
}

 // Добавляет слово в префиксное дерево
void Trie::insert(const std::string& word)
{
    TrieNode* current = root;

    for (char symbol : word)
    {
        if (current->children.find(symbol) == current->children.end())
        {
            current->children[symbol] = new TrieNode();
        }
        current = current->children[symbol];
    }

    current->isEndOfWord = true;
}

 // Проверяет, существует ли указанный префикс
bool Trie::startsWith(const std::string& prefix) const
{
    TrieNode* current = root;

    for (char symbol : prefix)
    {
        auto it = current->children.find(symbol);
        if (it == current->children.end())
            return false;

        current = it->second;
    }

    return true;
}

 // Рекурсивно собирает все слова, начиная с узла
void Trie::collectWords(
    TrieNode* node,
    const std::string& currentPrefix,
    std::vector<std::string>& results
) const
{
    if (node->isEndOfWord)
    {
        results.push_back(currentPrefix);
    }

    for (const auto& pair : node->children)
    {
        collectWords(
            pair.second,
            currentPrefix + pair.first,
            results
        );
    }
}

 // Возвращает список слов, подходящих под введённый префикс
std::vector<std::string> Trie::autocomplete(const std::string& prefix) const
{
    std::vector<std::string> results;
    TrieNode* current = root;

    for (char symbol : prefix)
    {
        auto it = current->children.find(symbol);
        if (it == current->children.end())
        {
            return results; // пустой список
        }
        current = it->second;
    }

    collectWords(current, prefix, results);
    return results;
}