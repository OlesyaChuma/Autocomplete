#pragma once

#include <vector>
#include <string>
#include "Trie.h"

 // Класс-обёртка для работы со словарём
class Dictionary
{
private:
    Trie trie;

public:
    /// Загрузка встроенного словаря
    void loadDefaultWords();

    /// Загрузка слов из файла
    bool loadFromFile(const std::string& fileName);

    /// Получение подсказок
    std::vector<std::string> getSuggestions(const std::string& prefix) const;
};

