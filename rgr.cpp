#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Шифр Гронсфельда, Шифр Плейфера, Простая табличная перестановка
string Gronsfeld(string text, string key, string encrypted_text)
{
    setlocale(LC_ALL, "Rus");
    for (int i = 0; key.size() < (count_if(text.begin(), text.end(), [](int c) { return c != ' '; })); i++) {
        key += key[i];
    }
    for (int i = 0; i < text.size(); i++) {
        if (text[i] == ' ') {
            key.insert(i, 1, char(32));
        }
    }
    for (int i = 0; encrypted_text.size() < text.size(); i++) {
        if (text[i] == ' ') {
            encrypted_text.insert(i, 1, char(32));
        }else encrypted_text += char((int)(text[i]) + key[i] - '0');
    }
    return encrypted_text;
}
int main()
{
    setlocale(LC_ALL, "Rus");
    string text, key, encrypted_text;
    vector<char>alphabet_engl;
    cout << "Введите сообщение, которое хотите зашифровать: ";
    getline(cin, text);
    cout << "Введите ключ шифровки: ";
    getline(cin, key);
    for (int i = 65; i < 91; i++) alphabet_engl.push_back(char(i));
    encrypted_text = Gronsfeld(text, key, encrypted_text);
    cout << "Зашифрованное сообщение: " << encrypted_text << endl;
}
