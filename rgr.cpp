// 1) Шифр Вижинера
// 2) Шифровка с помощью квадрата Полибия
// 3) Двойная табличная перестановка
// Nikita Eliseev

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void PolybiusSquare(string text, string key, vector<char>& alphabet)
{
    string alph = "abcdefghiklmnopqrstuvwxyz";

    alph = key + alph;
    vector<vector<char>> vec1 =
    {
        {'a','b','c','d','e'},
        {'f','g','h','i','k'},
        {'l','m','n','o','p'},
        {'q','r','s','t','u'},
        {'v','w','x','y','z'},
    };
    for (int i = key.size(); i < alph.size(); i++)
    {
        for (int j = 0; j < key.size(); j++)
        {
            if ((alph[i] == alph[j]) || ((alph[i] == alph[j]) && alph[i] == 'i') || (alph[i] == 'i' && alph[j] == 'j'))
            {
                for (int k = i; k < alph.size(); k++)
                {
                    alph[k] = alph[k + 1];
                }
                i = key.size();
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            vec1[i][j] = alph[5 * i + j];
        }
    }

    cout << endl << "Квадрат Полибия с ключом:" << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << vec1[i][j] << " ";
        }
        cout << endl;
    }
    //cout << endl << alph << " " << alph.size();
}

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
        {
            j = 0;
        }
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
    for (int i = 0, j = 0; i < K1.size(); i++)
    {
        K2.push_back(key[j] - 97);
        j++;
        if (j == key.size())
        {
            j = 0;
        }
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
    for (int i = 0; i < text.size(); i++)
    {
        if (65 <= text[i] && text[i] <= 90)
        {
            text[i] += 32;
        }
    }
    cout << "Введите ключ шифрования: ";
    getline(cin, key);
    for (int i = 65 + 32; i < 91 + 32; i++) alphabet.push_back(char(i));
    slovo = VigenereEncrypt(text, key, alphabet);
    cout << "Зашифрованное сообщение: " << slovo << endl;

    slovo = VigenereDecrypt(VigenereEncrypt(text, key, alphabet), key, alphabet);
    cout << "Расшифрованное сообщение: " << slovo << endl;

    PolybiusSquare(text, key, alphabet);
}
