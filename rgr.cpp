#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Шифр Гронсфельда, Шифр Плейфера, Простая табличная перестановка
string Gronsfeld(string text, string key, string encrypted_text, vector<char> alphabet)
{
    for (int i = 0; key.size() < (count_if(text.begin(), text.end(), [](int c) { return c != ' '; })); i++) {
        key += key[i];
    }
    for (int i = 0; encrypted_text.size() < (count_if(text.begin(), text.end(), [](int c) { return c != ' '; })); i++) {
        encrypted_text += char((int)(text[0]) + key[0] - '0');
    }
    return encrypted_text;
}
int main()
{
    setlocale(0, "");
    string text, key, encrypted_text;
    int test = 0;
    vector<char>alphabet;
    cout << "Введите текст, который хотите зашифровать" << endl;
    getline(cin, text);
    cout << "Введите ключ шифровки" << endl;
    getline(cin, key);
    for (int i = 65; i < 91; i++) alphabet.push_back(char(i));
    cout << Gronsfeld(text, key, encrypted_text, alphabet) << endl;
    test = (int)(text[0]) + key[0] - '0'; // вывод значения аски
    cout << test;
}
