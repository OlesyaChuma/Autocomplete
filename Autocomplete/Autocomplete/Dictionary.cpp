#include "Dictionary.h"
#include <fstream>
#include <iostream>

void Dictionary::loadDefaultWords()
{
    std::vector<std::string> words =
    {
        "hello", "help", "helium",
        "hero", "her", "hi",
        "house", "hover", "home",
        "habit", "happy", "hard"
    };

    for (const auto& word : words)
    {
        trie.insert(word);
    }
}

 // Загружает словарь из текстового файла
bool Dictionary::loadFromFile(const std::string& fileName)
{
    std::ifstream file(fileName);
    if (!file.is_open())
        return false;

    std::string word;
    while (file >> word)
    {
        trie.insert(word);
    }

    return true;
}

std::vector<std::string> Dictionary::getSuggestions(const std::string& prefix) const
{
    return trie.autocomplete(prefix);
}