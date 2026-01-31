// Autocomplete.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Dictionary.h"
#include "Validation.h"

int main()
{
    setlocale(LC_ALL, "");
    Dictionary dictionary;

    if (!dictionary.loadFromFile("dictionary.txt"))
    {
        std::cout << "Файл словаря не найден. Используется встроенный словарь.\n";
        dictionary.loadDefaultWords();
    }

    while (true)
    {
        std::string input;
        std::cout << "\nВведите начало слова (exit для выхода): ";
        std::cin >> input;

        if (input == "exit")
            break;

        if (!Validation::isValidPrefix(input))
        {
            std::cout << "Ошибка ввода. Используйте только буквы.\n";
            continue;
        }

        auto suggestions = dictionary.getSuggestions(input);

        if (suggestions.empty())
        {
            std::cout << "Подсказки не найдены\n";
        }
        else
        {
            std::cout << "Возможные варианты:\n";
            for (const auto& word : suggestions)
                std::cout << " - " << word << '\n';
        }
    }

    return 0;
}