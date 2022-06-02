#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "windows.h"

using namespace std;

// Шифр Гронсфельда, Шифр Плейфера, Простая табличная перестановка
string Gronsfeld_Encrypt(string text, string key, vector<char>&alphabet)
{
    string encrypted_text;
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
        }
        else {
            auto n = find(alphabet.begin(), alphabet.end(), text[i]); 
            int index = n - alphabet.begin() + key[i] - '0';
            if (index >= size(alphabet)) {
                encrypted_text += alphabet[(index - size(alphabet))];
            }else{
                encrypted_text += alphabet[index];
            }
            
        }
    }
    return encrypted_text;
}
string Gronsfeld_Decrypt(string text, string key, vector<char>& alphabet)
{
    string decrypt_text;
    for (int i = 0; key.size() < (count_if(text.begin(), text.end(), [](int c) { return c != ' '; })); i++) {
        key += key[i];
    }
    for (int i = 0; i < text.size(); i++) {
        if (text[i] == ' ') {
            key.insert(i, 1, char(32));
        }
    }
    for (int i = 0; decrypt_text.size() < text.size(); i++) {
        if (text[i] == ' ') {
            decrypt_text.insert(i, 1, char(32));
        }
        else {
            auto n = find(alphabet.begin(), alphabet.end(), text[i]);
            int index = n - alphabet.begin() - (key[i] - '0');
            if (index < 0) {
                decrypt_text += alphabet[(index + size(alphabet))];
            }else {
                decrypt_text += alphabet[index];
            }
        }
    }
    return decrypt_text;
}
int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string text, key, slovo;
    vector<char>alphabet_engl;
    for (int i = 97; i < 123; i++) alphabet_engl.push_back(char(i));
    vector<char>alphabet_rus;
    for (int i = 224; i < 256; i++) alphabet_rus.push_back(char(i));
    cout << "Введите сообщение, которое хотите зашифровать: ";
    getline(cin, text);
    cout << "Введите ключ шифровки: ";
    getline(cin, key);
    if (find(alphabet_engl.begin(), alphabet_engl.end(), text[0]) != alphabet_engl.end()) {
        slovo = Gronsfeld_Encrypt(text, key, alphabet_engl);
        cout << "Зашифрованное сообщение: " << slovo << endl;
        slovo = Gronsfeld_Decrypt(slovo, key, alphabet_engl);
        cout << "Расшифрованное сообщение: " << slovo << endl;
    }else {
        slovo = Gronsfeld_Encrypt(text, key, alphabet_rus);
        cout << "Зашифрованное сообщение: " << slovo << endl;
        slovo = Gronsfeld_Decrypt(slovo, key, alphabet_rus);
        cout << "Расшифрованое сообщение: " << slovo << endl;
    }
}
