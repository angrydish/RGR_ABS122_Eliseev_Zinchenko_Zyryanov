// 1) Шифр Вижинера
// 2) Шифровка с помощью квадрата Полибия
// 3) Двойная табличная перестановка
// Nikita Eliseev

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string VigenereEncrypt(string text, string key, vector<char>& alphabet)
{
    vector<int> K1;
    vector<int> K2;
    string crypt, crypt1;
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
    for(int i = 0, d = 0; i < text.size(); i++)
    {
        if (text[i] == ' ')
        {
            crypt1.push_back(' '); 
            d++;
        }
        else
        {
            crypt1.push_back(crypt[i-d]);
        }
    }
    return crypt1;
}

string VigenereDecrypt(string text, string key, vector<char>& alphabet)
{
    vector<int> K1;
    vector<int> K2;
    string crypt, crypt1;
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
    for (int i = 0, j = 0, c = 0; i < K1.size(); i++)
    {
        K2.push_back(key[j] - 97);
        j++;
        if (j == key.size())
            j = 0;
        crypt.push_back((((K1[i] - K2[i]) > 0 ? K1[i] - K2[i] : K1[i] + 26 - K2[i]) % 26) + 97);
    }
    for (int i = 0, d = 0; i < text.size(); i++)
    {
        if (text[i] == ' ')
        {
            crypt1.push_back(' ');
            d++;
        }
        else
        {
            crypt1.push_back(crypt[i - d]);
        }
    }
    return crypt1;
}


int main()
{
    setlocale(0, "");
    vector<char> alphabet;
    string text, key, slovo;
    cout << "Введите исходное сообщение: ";
    getline(cin, text);
    cout << "Введите ключ шифрования: ";
    getline(cin, key);
    for (int i = 65 + 32; i < 91 + 32; i++) alphabet.push_back(char(i));
    slovo = VigenereEncrypt(text, key, alphabet);
    cout << "Зашифрованное сообщение: " << slovo << endl;

    slovo = VigenereDecrypt(VigenereEncrypt(text, key, alphabet), key, alphabet);
    cout << "Расшифрованное сообщение: " << slovo << endl;
}
