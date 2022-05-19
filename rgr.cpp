// 1) Шифр Вижинера
// 2) Шифровка с помощью квадрата Полибия
// 3) Двойная табличная перестановка
// Nikita Eliseev

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void vigenere(string text, string key, vector<char>& alphabet)
{
    vector<int> K1;
    vector<int> K2;
    vector<int> K3;
    vector<char>split;
    string crypt;
    //for (auto i : alphabet)
    //    cout << i << " ";
    for (auto i : text)
        if (i != ' ')
            split.push_back(i);

    for (int i = 0; i < text.size(); i++)
    {
        for (int j = 0; j < alphabet.size(); j++)
        {
            if (text[i] == alphabet[j])
            {
                K1.push_back(j);
            }
        }
    }
    for (int i = 0, j = 0; i < K1.size(); i++)
    {
        K2.push_back(key[j] - 97);
        j++;
        if (j == key.size())
            j = 0;
        crypt.push_back(((K1[i] + K2[i]) % 26) + 97);
    }

    //for (auto i : K1)
    //    cout << i << "\t";
    //cout << endl;
    //for (auto i : K2)
    //    cout << i << "\t";
    //cout << endl;
    //for (auto i : K3)
    //    cout << i << "\t";
    cout << "Зашифрованное сообщение: " << crypt;
}

int main()
{
    setlocale(0, "");
    vector<char> alphabet;
    string text, key;
    cout << "Введите исходное сообщение: ";
    //getline(cin, text);
    text = "fortenite ili babage";
    cout << text << endl;
    cout << "Введите ключ шифрования: ";
    //getline(cin, key);
    key = "xd";
    cout << key << endl;
    for (int i = 65 + 32; i < 91 + 32; i++) alphabet.push_back(char(i));
    //cout << alphabet.size();
    vigenere(text, key, alphabet);
}
