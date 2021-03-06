#include "StaticHelper.h"

// Compares 2 strings
bool StaticHelper::CompareStringCaseInsensitive(std::string_view str1, std::string_view str2)
{
    if (str1.length() != str2.length())
        return false;

    for (size_t i = 0; i < str1.length(); i++)
        if (tolower(str1[i]) != tolower(str2[i]))
            return false;

    return true;
}
