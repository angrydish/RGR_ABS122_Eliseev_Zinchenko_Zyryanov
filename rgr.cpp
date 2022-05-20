// 1) Шифр Вижинера
// 2) Шифровка с помощью квадрата Полибия
// 3) Двойная табличная перестановка
// Nikita Eliseev

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string PolybiusSquare(string xd, string key, vector<char>& alphabet)
{
    string alph = "abcdefghiklmnopqrstuvwxyz";
    vector<int> x;
    vector<int> y;
    vector<int> x1;
    vector<int> y1;
    string crypt;
    string text;
    alph = key + alph;
    for (int i = 0; i < xd.size(); i++)
    {
        if (xd[i] != ' ')
        {
            text.push_back(xd[i]);
        }
        else
        {
            continue;
        }
    }
    vector<vector<char>> key_square =
    {
        {'a','b','c','d','e'},
        {'f','g','h','i','k'},
        {'l','m','n','o','p'},
        {'q','r','s','t','u'},
        {'v','w','x','y','z'},
    };

    for (int j = 0; j < key.size(); j++)
    {
        for (int i = key.size(); i < alph.size(); i++)
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
            key_square[i][j] = alph[5 * i + j];
        }
    }

    //cout << endl << "Квадрат Полибия с ключом:" << endl;
    //for (int i = 0; i < 5; i++)
    //{
    //    for (int j = 0; j < 5; j++)
    //    {
    //        cout << key_square[i][j] << " ";
    //    }
    //    cout << endl;
    //}
    for (int i = 0, ind = 0; i < 5 && ind < text.size(); i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (key_square[i][j] == text[ind]) 
            {
                x.push_back(j);
                y.push_back(i);
                i = 0;
                j = 0;
                ind += 1;
            }
        }
    }
    for (int i = 0; i < text.size(); i += 2)
        x1.push_back(x[i]);
    for (int i = 0; i < text.size(); i += 2)
        x1.push_back(y[i]);

    for (int i = 1; i < text.size(); i += 2)
        y1.push_back(x[i]);
    for (int i = 1; i < text.size(); i += 2)
        y1.push_back(y[i]);

    //for (auto i : x)
    //{
    //    cout << i << " ";
    //}
    //cout << endl;
    //for (auto i : y)
    //{
    //    cout << i << " ";
    //}
    //cout << endl << endl;
    //for (auto i : x1)
    //{
    //    cout << i << " ";
    //}
    //cout << endl;
    //for (auto i : y1)
    //{
    //    cout << i << " ";
    //}

    for (int i = 0;i < x1.size(); i++)
    {
        crypt.push_back(key_square[y1[i]][x1[i]]);
    }
    return crypt;

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
    cout << endl << "Шифр Вижинера:" << endl;
    slovo = VigenereEncrypt(text, key, alphabet);
    cout << "Зашифрованное сообщение: " << slovo << endl;
    slovo = VigenereDecrypt(VigenereEncrypt(text, key, alphabet), key, alphabet);
    cout << "Расшифрованное сообщение: " << slovo << endl;

    cout << endl << "Шифровка с помощью квадрата Полибия:" << endl;
    if (text.size() % 2 != 0)
    {
        cout << "Шифровка квадратом Полибия применима только к выражениям, у которых четное количество символов";
        while (text.size() % 2 != 0)
        {
            cout << endl << "Введите сообщение с четным количеством символов: ";
            getline(cin, text);
        }
    }
    slovo = PolybiusSquare(text, key, alphabet);
    cout << "Зашифрованное сообщение: " << slovo;
}
