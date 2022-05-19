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
    vector<char>split;
    //for (auto i : alphabet)
    //    cout << i << " ";
    for (auto i : text)
        if (i != ' ')
            split.push_back(i);
    //cout << endl;
    //for (auto i : split)
    //    cout << i;
    cout << endl;
    vector<int> K1;
    vector<int> K2;
    vector<int> K3;
    for (int i = 0; i < split.size(); i++)
    {
        K1.push_back(split[i]);
        cout << K1[i]<<"\t";
    }
    cout << endl;
    for (int i = 0, j = 0; i < K1.size(); i++)
    {
        K2.push_back(key[j]);
        j++;
        if (j == 6)
            j = 0;
    }
    for (auto i : K2)
        cout << i <<"\t";
    for (int i = 0; i < K1.size(); i++)
    {
        K3.push_back(K1[i]);
    }
}

int main()
{
    setlocale(0, "");
    vector<char> alphabet;
    string text, key;
    cout << "Введите исходное сообщение: ";
    //cin >> text;
    text = "she is listening";
    cout << text << endl;
    cout << "Введите ключ шифрования: ";
    //cin >> key;
    key = "pascal";
    cout << key << endl;
    for (int i = 65+32; i < 91+32; i++)
    {
        alphabet.push_back(char(i));
    }
    vigenere(text, key, alphabet);
}
