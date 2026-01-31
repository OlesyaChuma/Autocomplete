#include "Validation.h"
#include <cctype>

bool Validation::isValidPrefix(const std::string& input)
{
    if (input.empty())
        return false;

    for (char symbol : input)
    {
        if (!std::isalpha(static_cast<unsigned char>(symbol)))
            return false;
    }

    return true;
}