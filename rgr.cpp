// 1) Шифр Вижинера
// 2) Шифровка с помощью квадрата Полибия
// 3) Двойная табличная перестановка
// Nikita Eliseev
#include "ecrypt_decrypt_funcs.h"

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
    cout << "Зашифрованное сообщение: " << PolybiusSquare_encrypt(text, key) << endl;
    cout << "Расшифрованное сообщение: " << PolybiusSquare_decrypt(PolybiusSquare_encrypt(text, key), key) << endl;
}
