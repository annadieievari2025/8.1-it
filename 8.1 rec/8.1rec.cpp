#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <Windows.h>
using namespace std;

void CheckLettersRecursive(const char* str, bool found[5], int i = 0)
{
    const char* pattern = "while";

    if (str[i] == '\0')
        return;

    for (int j = 0; j < 5; j++)
        if (str[i] == pattern[j])
            found[j] = true;

    CheckLettersRecursive(str, found, i + 1);
}

bool HasAllWhileLettersRecursive(const char* str)
{
    bool found[5] = { false, false, false, false, false };
    CheckLettersRecursive(str, found);

    for (bool f : found)
        if (!f)
            return false;
    return true;
}
void ReplaceWhileRecursive(const char* src, char* dest, int i, int j)
{
    const char* pattern = "while";
    const char* replacement = "**";
    int patLen = strlen(pattern);

    if (src[i] == '\0')
    {
        dest[j] = '\0';
        return;
    }

    bool match = true;
    for (int k = 0; k < patLen && src[i + k] != '\0'; k++)
        if (src[i + k] != pattern[k])
        {
            match = false;
            break;
        }

    if (match)
    {
        dest[j++] = '*';
        dest[j++] = '*';
        ReplaceWhileRecursive(src, dest, i + patLen, j);
    }
    else
    {
        dest[j++] = src[i];
        ReplaceWhileRecursive(src, dest, i + 1, j);
    }
}

char* ReplaceWhileWithStarsRecursive(char* str)
{
    size_t len = strlen(str);
    char* result = new char[len * 2 + 1];
    ReplaceWhileRecursive(str, result, 0, 0);
    strcpy_s(str, len * 2 + 1, result);
    return result;
}

int main()
{
    SetConsoleOutputCP(1251);
    char str[201];
    cout << "Введіть рядок: ";
    cin.getline(str, 200);

    if (HasAllWhileLettersRecursive(str))
        cout << "Всі літери 'while' є в рядку.\n";
    else
        cout << "Не всі літери 'while' є в рядку.\n";

    char* modified = ReplaceWhileWithStarsRecursive(str);

    cout << "Модифікований рядок (парам): " << str << endl;
    cout << "Модифікований рядок (результат): " << modified << endl;

    delete[] modified;
    return 0;
}
