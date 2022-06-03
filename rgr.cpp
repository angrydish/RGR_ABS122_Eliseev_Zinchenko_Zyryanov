#include "ciphers.h"

int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    string text, key, slovo;
    
    cout << "Введите сообщение, которое хотите зашифровать: ";
    getline(cin, text);

    cout << "Введите ключ шифровки: ";
    getline(cin, key);

    /*slovo = Gronsfeld_Encrypt(text, key);
    cout << "Зашифрованное сообщение: " << slovo << endl;

    slovo = Gronsfeld_Decrypt(slovo, key);
    cout << "Расшифрованное сообщение: " << slovo << endl;*/
}
