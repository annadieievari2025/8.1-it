#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <Windows.h>
using namespace std;

bool HasAllWhileLetters(const char* str)
{
    const char* pattern = "while";
    bool found[5] = { false, false, false, false, false }; 

    for (size_t i = 0; str[i] != '\0'; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            if (str[i] == pattern[j])
                found[j] = true;
        }
    }

    for (bool f : found)
        if (!f)
            return false;

    return true;
}

char* ReplaceWhileWithStars(char* str)
{
    const char* pattern = "while";
    const char* replacement = "**";

    size_t len = strlen(str);
    size_t patLen = strlen(pattern);

    char* result = new char[len * 2 + 1];
    result[0] = '\0';

    size_t i = 0;
    while (i < len)
    {
        bool match = true;

        for (size_t j = 0; j < patLen && (i + j) < len; j++)
        {
            if (str[i + j] != pattern[j])
            {
                match = false;
                break;
            }
        }

        if (match)
        {
            strcat_s(result, len * 2 + 1, replacement);
            i += patLen;
        }
        else
        {
            size_t resLen = strlen(result);
            result[resLen] = str[i];
            result[resLen + 1] = '\0';
            i++;
        }
    }

    strcpy_s(str, len * 2 + 1, result);
    return result;
}

int main()
{
    SetConsoleOutputCP(1251);
    char str[201];
    cout << "Enter string: ";
    cin.getline(str, 200);

    if (HasAllWhileLetters(str))
        cout << "Всі букви 'while' наявні в літерному рядку.\n";
    else
        cout << "Не всі букви 'while' наявні в літерному рядку.\n";

    char* modified = ReplaceWhileWithStars(str);

    cout << "Модифікований рядок (парам): " << str << endl;
    cout << "Модифікований рядок (результат): " << modified << endl;

    delete[] modified;
    return 0;
}
