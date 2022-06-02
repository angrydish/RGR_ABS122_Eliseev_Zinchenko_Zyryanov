// 1) Шифр Вижинера
// 2) Шифровка с помощью квадрата Полибия
// 3) Двойная табличная перестановка
// Nikita Eliseev
#include "ecrypt_decrypt_funcs.h"

void user_menu()
{
    cout << "Добро пожаловать!"<<endl<<"Выберите шифр:" << endl;
    for (int i = 0; i < 50; i++) cout << "-";
    cout << endl;
    cout << "Нажмите \"1\" для выбора шифра Вижинера"<<endl
         << "Нажмите \"2\" для выбора шифра с помощью квадрата Полибия"<<endl
         << "Нажмите \"3\" для выбора шифра двойной табличной перестановкой" << endl;
    for (int i = 0; i < 50; i++) cout << "-";
    cout << endl;
}

int main()
{
    setlocale(0, "");
    string text, key, slovo, user_pswd, user_choice = "0";
    int password = 1111;
    int user_choice_int = 0;
    bool error_flag = false;
    while (true)
    {
        cout << "Пароль:";
        getline(cin, user_pswd);
        try
        {
            stoi(user_pswd);
        }
        catch (const std::exception&)
        {
            cout << "Символы пароля должны быть цифрами." << endl;
            continue;
        }
        if (stoi(user_pswd) == password)
        {
            user_pswd = "-1";
            while (true)
            {
                system("cls");
                user_menu();
                getline(cin, user_choice);
                try
                {
                    user_choice_int = stoi(user_choice);
                }
                catch (const std::exception&)
                {
                    cout << "Необходимо ввести цифру, а не что бы то ни было кроме цифр." << endl;
                    system("pause");
                    continue;
                }
                switch (user_choice_int)
                {
                    case 1:
                    {
                        system("cls");
                        cout << "Шифр Вижинера:"
                             << endl << "Допускаются только латинские символы." << endl;
                        cout << "Введите исходное сообщение:";
                        getline(cin, text);
                        for (int i = 0; i < text.size(); i++)
                        {
                            if (!((text[i] <= 90 && text[i] >= 65)|| (text[i] <= 122 && text[i] >= 97))&& text[i] != ' ')
                            {
                                system("cls");
                                cout << "Программа работает только с латинскими символами." << endl;
                                system("pause");
                                error_flag = true;
                                break;
                            }
                        }
                        if (error_flag == true)
                        {
                            error_flag = false;
                            break;
                        }
                        cout << "Введите ключ шифрования:";
                        getline(cin, key);
                        for (int i = 0; i < key.size(); i++)
                        {
                            if (!((key[i] <= 90 && key[i] >= 65) || (text[i] <= 122 && key[i] >= 97)) && key[i] != ' ')
                            {
                                system("cls");
                                cout << "Программа работает исключительно с латинскими символами." << endl;
                                system("pause");
                                error_flag = true;
                                break;
                            }
                            else if (key[i] == ' ')
                            {
                                system("cls");
                                cout << "В ключе не должно быть пробелов" << endl;
                                system("pause");

                                error_flag = true;
                                break;
                            }
                        }
                        if (error_flag == true)
                        {
                            error_flag = false;
                            break;
                        }
                        for (int i = 0; i < text.size(); i++)// заглавные в строчые
                        {
                            if (65 <= text[i] && text[i] <= 90)
                            {
                                text[i] += 32;
                            }
                        }
                        for (int i = 0; i < key.size(); i++)// заглавные в строчые
                        {
                            if (65 <= key[i] && key[i] <= 90)
                            {
                                key[i] += 32;
                            }
                        }
                        bool ChoiseToLeave = false;
                        int attempt = 0;
                        while (stoi(user_pswd) != password)
                        {
                            if (attempt == 3)
                            {
                                cout << "Если вы не хотите использовать это шифрование, напишите \"E_X_I_T\"" << endl;
                                attempt = 0;
                            }
                            cout << "Введите пароль:";
                            getline(cin, user_pswd);
                            if (user_pswd == "E_X_I_T")
                            {
                                user_pswd = "-1";
                                ChoiseToLeave = true;
                                break;
                            }
                            try
                            {
                                stoi(user_pswd);
                            }
                            catch (const std::exception&)
                            {
                                cout << "Символы пароля должны быть цифрами." << endl;
                                user_pswd = "-1";
                                attempt++;
                                continue;
                            }
                            attempt++;
                        }
                        if (!ChoiseToLeave)
                        {
                            cout << "Зашифрованное сообщение:" << VigenereEncrypt(text, key) << endl;
                            cout << "Расшифрованное сообщение:" << VigenereDecrypt(VigenereEncrypt(text, key),key) << endl;
                            user_pswd = "-1";
                            system("pause");
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }
                    case 2:
                    {
                        break;
                    }
                    case 3:
                    {
                        break;
                    }
                    default:
                    {
                        cout << "Необходимо выбрать из предложенных цифр." << endl;
                        system("pause");
                        break;
                    }
                }
            }
        }
        else
        {
            cout << "Неверный пароль." << endl;
        }
        
    }
}
