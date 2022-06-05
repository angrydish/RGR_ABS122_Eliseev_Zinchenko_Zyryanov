﻿#include "ciphers.h"
// 1) Шифр Гронсфельда
// 2) Табличная шифровка с ключевым словом
// 3) Шифр Атбаш
// Zinchenko Matvey

int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ifstream fin;
    ofstream fout;
    string text, key, user_pswd, user_choice = "0";
    string file_name_in = "in.txt", file_name_out, fin_text;
    int password = 1111;
    int user_choice_int = -1;
    bool error_flag = false;

    cout << "Введите имя файла вывода:";
    getline(cin, file_name_out);
    fout.open(file_name_out);
    if (!fout.is_open())
    {
        cout << "Не удалось открыть файл вывода." << endl;
        exit(0);
    }

    string fast_check;
    cout << "Быстрая проверка?(1 - да, 0 - нет):";
    OMT:
    getline(cin, fast_check);

    try
    {
        stoi(fast_check);
    }
    catch (const std::exception&)
    {
        cout << "Введи цифру, пожалуйста." << endl;
        goto OMT;
    }

    if (stoi(fast_check) == 1)
    {
        text = "ПерРвонАчалЬные ДокАзательства ЯвляЮтся пЕрвоиСтОчнИками СведЕний о оБстоятЕльсТвах";
        key = "2456";
        cout << "Исходное сообщение: " << text << endl;
        cout << "Ключ: " << key << endl << endl;

        cout << "Шифр Гронсфельда: " << endl;
        cout << "Введенное сообщение: " << text << endl;
        cout << "Введенный ключ: " << key << endl;
        cout << "Зашифрованное сообщение: " << Gronsfeld_Encrypt(text, key) << endl;
        cout << "Расшифрованное сообщение: " << Gronsfeld_Decrypt(Gronsfeld_Encrypt(text, key), key) << endl << endl;

        fout << "Шифр Гронсфельда: " << endl;
        fout << "Введенное сообщение: " << text << endl;
        fout << "Введенный ключ: " << key << endl;
        fout << "Зашифрованное сообщение: " << Gronsfeld_Encrypt(text, key) << endl;
        fout << "Расшифрованное сообщение: " << Gronsfeld_Decrypt(Gronsfeld_Encrypt(text, key), key) << endl << endl;

        text = "sMeTaNa V sKvOrEcHnIkE";
        key = "567";
        cout << "Исходное сообщение: " << text << endl;
        cout << "Ключ: " << key << endl << endl;

        cout << "Шифр Гронсфельда: " << endl;
        cout << "Введенное сообщение: " << text << endl;
        cout << "Введенный ключ: " << key << endl;
        cout << "Зашифрованное сообщение: " << Gronsfeld_Encrypt(text, key) << endl;
        cout << "Расшифрованное сообщение: " << Gronsfeld_Decrypt(Gronsfeld_Encrypt(text, key), key) << endl << endl;

        fout << "Шифр Гронсфельда: " << endl;
        fout << "Введенное сообщение: " << text << endl;
        fout << "Введенный ключ: " << key << endl;
        fout << "Зашифрованное сообщение: " << Gronsfeld_Encrypt(text, key) << endl;
        fout << "Расшифрованное сообщение: " << Gronsfeld_Decrypt(Gronsfeld_Encrypt(text, key), key) << endl << endl;

        text = "БроДяГа паРень Молодой";
        key = "пока"; 

        cout << "Табличная шифровка с ключевым словом: " << endl;
        cout << "Введенное сообщение: " << text << endl;
        cout << "Введенный ключ: " << key << endl;
        cout << "Зашифрованное сообщение:" << TablePermutation_Encrypt(text, key) << endl;
        cout << "Расшифрованное сообщение:" << TablePermutation_Decrypt(TablePermutation_Encrypt(text, key), key) << endl << endl;

        fout << "Табличная шифровка с ключевым словом: " << endl;
        fout << "Введенное сообщение: " << text << endl;
        fout << "Введенный ключ: " << key << endl;
        fout << "Зашифрованное сообщение: " << TablePermutation_Encrypt(text, key) << endl;
        fout << "Расшифрованное сообщение: " << TablePermutation_Decrypt(TablePermutation_Encrypt(text, key), key) << endl << endl;

        text = "I wanna eat pizzaa";
        key = "52413";
        cout << "Табличная шифровка с ключевым словом: " << endl;
        cout << "Введенное сообщение: " << text << endl;
        cout << "Введенный ключ: " << key << endl;
        cout << "Зашифрованное сообщение:" << TablePermutation_Encrypt(text, key) << endl;
        cout << "Расшифрованное сообщение:" << TablePermutation_Decrypt(TablePermutation_Encrypt(text, key), key) << endl << endl;

        fout << "Табличная шифровка с ключевым словом: " << endl;
        fout << "Введенное сообщение: " << text << endl;
        fout << "Введенный ключ: " << key << endl;
        fout << "Зашифрованное сообщение: " << TablePermutation_Encrypt(text, key) << endl;
        fout << "Расшифрованное сообщение: " << TablePermutation_Decrypt(TablePermutation_Encrypt(text, key), key) << endl << endl;

        text = "ВряД ли мНе пОмОгут Эти";
        cout << "Шифр Атбаш: " << endl;
        cout << "Введенное сообщение: " << text << endl;
        cout << "Зашифрованное сообщение:" << Atbash_Encrypt(text) << endl;
        cout << "Расшифрованное сообщение:" << Atbash_Encrypt(Atbash_Encrypt(text)) << endl << endl;

        fout << "Шифр Атбаш: " << endl;
        fout << "Введенное сообщение: " << text << endl;
        fout << "Зашифрованное сообщение: " << Atbash_Encrypt(text) << endl;
        fout << "Расшифрованное сообщение: " << Atbash_Encrypt(Atbash_Encrypt(text)) << endl << endl;

        text = "Lets celebrate";
        cout << "Шифр Атбаш: " << endl;
        cout << "Введенное сообщение: " << text << endl;
        cout << "Зашифрованное сообщение:" << Atbash_Encrypt(text) << endl;
        cout << "Расшифрованное сообщение:" << Atbash_Encrypt(Atbash_Encrypt(text)) << endl << endl;

        fout << "Шифр Атбаш: " << endl;
        fout << "Введенное сообщение: " << text << endl;
        fout << "Зашифрованное сообщение: " << Atbash_Encrypt(text) << endl;
        fout << "Расшифрованное сообщение: " << Atbash_Encrypt(Atbash_Encrypt(text)) << endl << endl;

        fout.close();
        system("notepad out.txt");
        system("pause");
        exit(0);
    }
    else if (stoi(fast_check) == 0)
    {

        while (true)
        {
            fin.close();
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
                    user_pswd = "-1";
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
                        cout << "Шифр Гронсфельда:"
                            << endl << "1) Допускаются только английский или русский алфавит."
                            << endl << "2) В ключе не должно быть пробелов." << endl;
                        bool ChoiseToLeave = false;
                        while (stoi(user_pswd) != password)
                        {
                            cout << "Если вы не хотите использовать это шифрование, напишите \"E_X_I_T\"" << endl;
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
                                continue;
                            }
                            if (stoi(user_pswd) != password)
                            {
                                cout << "Неверный пароль." << endl;
                            }
                        }
                        if (ChoiseToLeave) break;
                        string to_do;
                        cout << "Что вы хотите сделать?\n\"1\" - зашифровать\n\"2\" - расшифровать" << endl;
                        getline(cin, to_do);
                        cout << "Введите ключ шифрования:";
                        getline(cin, key);
                        for (int i = 0; i < key.size(); i++)
                        {
                            if (!(key[i] <= 58 && key[i] >= 47) && key[i] != ' ')
                            {
                                system("cls");
                                cout << "Ключ должен состоять только из чисел." << endl;
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
                        cout << "Введите сообщение: ";
                        getline(cin, text);
                        int k = 0;
                        int m = 0;
                        for (int i = 0; i < text.size(); i++) {
                            int cod_ascii = tolower((int)unsigned char(text[i]));
                            if (!((cod_ascii <= 90 && cod_ascii >= 65) || (cod_ascii <= 122 && cod_ascii >= 97)) && !(cod_ascii <= 255 && cod_ascii >= 192) && text[i] != ' ' && text[i] != ',' && text[i] != '.' && text[i] != '?' && text[i] != '!' && text[i] != ':' && text[i] != '-'){
                                system("cls");
                                cout << "Программа работает только с русскими или английскими символами" << endl;
                                system("pause");
                                error_flag = true;
                                break;
                            }
                        }
                        for (int i = 0; i < text.size(); i++)
                        {
                            int cod_ascii = tolower((int)unsigned char(text[i]));
                            if (!((cod_ascii <= 90 && cod_ascii >= 65) || (cod_ascii <= 122 && cod_ascii >= 97)) && text[i] != ' ' && text[i] != ',' && text[i] != '.' && text[i] != '?' && text[i] != '!' && text[i] != ':' && text[i] != '-')
                            {
                                k += 1;
                            }
                            else if (!(cod_ascii <= 255 && cod_ascii >= 192) && text[i] != ' ' && text[i] != ',' && text[i] != '.' && text[i] != '?' && text[i] != '!' && text[i] != ':' && text[i] != '-') {
                                m += 1;
                            }
                        }
                        if (m != 0 && k != 0) {
                            system("cls");
                            cout << "Программа работает только с русскими или английскими символами, нельзя ввести сразу англискии и рускии символы " << endl;
                            system("pause");
                            error_flag = true;
                        }
                        if (error_flag == true)
                        {
                            error_flag = false;
                            break;
                        }
                        cout << endl;
                        cout << "Шифр Гронсфельда: " << endl;
                        switch (stoi(to_do))
                        {
                        case 1:
                        {
                            cout << "Введенное сообщение:" << text << endl;
                            cout << "Введенный ключ:" << key << endl;
                            cout << "Зашифрованное сообщение:" << Gronsfeld_Encrypt(text, key) << endl;
                            fout << Gronsfeld_Encrypt(text, key) << endl;
                            break;
                        }
                        case 2:
                        {
                            cout << "Введенное сообщение:" << text << endl;
                            cout << "Введенный ключ:" << key << endl;
                            cout << "Расшифрованное сообщение:" << Gronsfeld_Decrypt(text, key) << endl;
                            fout << Gronsfeld_Decrypt(text, key) << endl;
                            break;
                        }
                        }
                        user_pswd = "-1";
                        system("pause");
                        break;
                    }
                    case 2:
                    {
                        system("cls");
                        cout << "Табличная шифровка с ключевым словом:"
                            << endl << "1) Шифровка применима только к выражениям, у которых количество букв() в тексте делится на количество символов в ключе нацело."
                            << endl << "2) Ключ принимает в себя, либо уникальный набор чисел(кроме 0), либо набор букв английского или русского алфавита." << endl;
                        bool ChoiseToLeave = false;
                        while (stoi(user_pswd) != password)
                        {
                            cout << "Если вы не хотите использовать это шифрование, напишите \"E_X_I_T\"" << endl;
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
                                continue;
                            }
                            if (stoi(user_pswd) != password)
                            {
                                cout << "Неверный пароль." << endl;
                            }
                        }
                        if (ChoiseToLeave) break;
                        string to_do;
                        cout << "Что вы хотите сделать?\n\"1\" - зашифровать\n\"2\" - расшифровать" << endl;
                        getline(cin, to_do);
                        cout << "Введите ключ шифрования:";
                        getline(cin, key);
                        int k = 0;
                        int m = 0;
                        int c = 0;
                        for (int i = 0; i < key.size(); i++) {
                            int cod_ascii = tolower((int)unsigned char(key[i]));
                            if (!((cod_ascii <= 90 && cod_ascii >= 65) || (cod_ascii <= 122 && cod_ascii >= 97)) && !(cod_ascii <= 255 && cod_ascii >= 192) && !(cod_ascii >= 49 && cod_ascii <= 57) && key[i] != ' ') {
                                system("cls");
                                cout << "Ключ принимает одни цифры или чисто русские или английские символы" << endl;
                                system("pause");
                                error_flag = true;
                                break;
                            }
                        }
                        for (int i = 0; i < key.size(); i++)
                        {
                            int cod_ascii = tolower((int)unsigned char(key[i]));
                            if (!(cod_ascii <= 122 && cod_ascii >= 97) && !(cod_ascii >= 49 && cod_ascii <= 57) && key[i] != ' ')
                            {
                                m += 1;
                            }
                            else if (!(cod_ascii <= 255 && cod_ascii >= 224) && !(cod_ascii >= 49 && cod_ascii <= 57) && key[i] != ' ') {
                                k += 1;
                            }
                            else if (cod_ascii >= 49 && cod_ascii <= 57 && key[i] != ' ') {
                                c += 1;
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
                        if ((m != 0 && k != 0) || (m != 0 && c!=0) || (k != 0 && c != 0)) {
                            system("cls");
                            cout << "ключ должен быть исключительно из чисел, либо с нижними регистроми английских или русских символов." << endl;
                            system("pause");
                            error_flag = true;
                            break;
                        }
                        if (error_flag == true)
                        {
                            error_flag = false;
                            break;
                        }
                        cout << "Введите сообщение: ";
                        getline(cin, text);
                        int k2 = 0;
                        int m2 = 0;
                        for(int i = 0; i < text.size(); i++) {
                            int cod_ascii = tolower((int)unsigned char(text[i]));
                            if (!((cod_ascii <= 90 && cod_ascii >= 65) || (cod_ascii <= 122 && cod_ascii >= 97)) && !(cod_ascii <= 255 && cod_ascii >= 192) && text[i] != ' ' && text[i] != ',' && text[i] != '.' && text[i] != '?' && text[i] != '!' && text[i] != ':' && text[i] != '-') {
                                system("cls");
                                cout << "Программа работает только с русскими или английскими символами" << endl;
                                system("pause");
                                error_flag = true;
                                break;
                            }
                        }
                        for (int i = 0; i < text.size(); i++)
                        {
                            int cod_ascii = tolower((int)unsigned char(text[i]));
                            if (!((cod_ascii <= 90 && cod_ascii >= 65) || (cod_ascii <= 122 && cod_ascii >= 97)) && text[i] != ' ' && text[i] != ',' && text[i] != '.' && text[i] != '?' && text[i] != '!' && text[i] != ':' && text[i] != '-')
                            {
                                k2 += 1;
                            }
                            else if (!(cod_ascii <= 255 && cod_ascii >= 192) && text[i] != ' ' && text[i] != ',' && text[i] != '.' && text[i] != '?' && text[i] != '!' && text[i] != ':' && text[i] != '-') {
                                m2 += 1;
                            }
                        }
                        if (m2 != 0 && k2 != 0) {
                            system("cls");
                            cout << "Программа работает только с русскими или английскими символами, нельзя ввести сразу англискии и рускии символы " << endl;
                            system("pause");
                            error_flag = true;
                        }
                        if (TablePermutation_Encrypt(text, key) == "this won't work")
                        {
                            cout << "Табличная шифровка с ключевым словом применима только к выражениям, у которых количество букв в тексте делится на количество символов в ключе нацело." << endl;
                            system("pause");
                            break;
                        }
                        if (TablePermutation_Encrypt(text, key) == "-1")
                        {
                            cout << "Если вы ввели в качестве ключа числа, то они все должны быть уникальными." << endl;
                            system("pause");
                            break;
                        }
                        if (error_flag == true)
                        {
                            error_flag = false;
                            break;
                        }
                        cout << endl;
                        cout << "Табличная шифровка с ключевым словом:" << endl;
                        switch (stoi(to_do))
                        {
                        case 1:
                        {
                            cout << "Введенное сообщение:" << text << endl;
                            cout << "Введенный ключ:" << key << endl;
                            cout << "Зашифрованное сообщение:" << TablePermutation_Encrypt(text, key) << endl;
                            fout << TablePermutation_Encrypt(text, key) << endl;
                            break;
                        }
                        case 2:
                        {
                            cout << "Введенное сообщение:" << text << endl;
                            cout << "Введенный ключ:" << key << endl;
                            cout << "Расшифрованное сообщение:" << TablePermutation_Decrypt(text, key) << endl;
                            fout << TablePermutation_Decrypt(text, key) << endl;
                            break;
                        }
                        }
                        user_pswd = "-1";
                        system("pause");
                        break;
                    }
                    case 3:
                    {
                        system("cls");
                        cout << "Шифр Атбаша:" << endl;
                        bool ChoiseToLeave = false;
                        int attempt = 0;
                        while (stoi(user_pswd) != password)
                        {
                            cout << "Если вы не хотите использовать это шифрование, напишите \"E_X_I_T\"" << endl;   
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
                                continue;
                            }
                            if (stoi(user_pswd) != password)
                            {
                                cout << "Неверный пароль." << endl;
                            }
                        }
                        user_pswd = "-1";
                        if (ChoiseToLeave) break;
                        string to_do;
                        cout << "Шифровка Атбаша:" << endl;
                        cout << "Что вы хотите сделать?\n\"1\" - зашифровать\n\"2\" - расшифровать" << endl;
                        getline(cin, to_do);
                        cout << "Введите сообщение: ";
                        getline(cin, text);
                        int c = 0;
                        int t = 0;
                        for (int i = 0; i < text.size(); i++) {
                            int cod_ascii = tolower((int)unsigned char(text[i]));
                            if (!((cod_ascii <= 90 && cod_ascii >= 65) || (cod_ascii <= 122 && cod_ascii >= 97)) && !(cod_ascii <= 255 && cod_ascii >= 192) && text[i] != ' ' && text[i] != ',' && text[i] != '.' && text[i] != '?' && text[i] != '!' && text[i] != ':' && text[i] != '-') {
                                system("cls");
                                cout << "Программа работает только с русскими или английскими символами" << endl;
                                system("pause");
                                error_flag = true;
                                break;
                            }
                        }
                        for (int i = 0; i < text.size(); i++)
                        {
                            int cod_ascii = tolower((int)unsigned char(text[i]));
                            if (!((cod_ascii <= 90 && cod_ascii >= 65) || (cod_ascii <= 122 && cod_ascii >= 97)) && text[i] != ' ' && text[i] != ',' && text[i] != '.' && text[i] != '?' && text[i] != '!' && text[i] != ':' && text[i] != '-')
                            {
                                c += 1;
                            }
                            else if (!(cod_ascii <= 255 && cod_ascii >= 192) && text[i] != ' ' && text[i] != ',' && text[i] != '.' && text[i] != '?' && text[i] != '!' && text[i] != ':' && text[i] != '-') {
                                t += 1;
                            }
                        }
                        if (c != 0 && t != 0) {
                            system("cls");
                            cout << "Программа работает только с русскими или английскими символами, нельзя ввести сразу англиские и руские символы " << endl;
                            system("pause");
                            error_flag = true;
                        }
                        if (error_flag == true)
                        {
                            error_flag = false;
                            break;
                        }
                        cout << "Введенное сообщение:" << text << endl;
                        switch (stoi(to_do))
                        {
                        case 1:
                        {
                            cout << "Зашифрованное сообщение:" << Atbash_Encrypt(text) << endl;
                            fout << Atbash_Encrypt(text) << endl;
                            break;
                        }
                        case 2:
                        {
                            cout << "Расшифрованное сообщение:" << Atbash_Decrypt(text) << endl;
                            fout << Atbash_Decrypt(text) << endl;
                            break;
                        }
                        }
                        user_pswd = "-1";
                        system("pause");
                        break;
                    }
                    case 0:
                    {
                        system("cls");
                        cout << "Программа завершена." << endl;
                        fout.close();
                        system("notepad out.txt");
                        exit(0);
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
}
