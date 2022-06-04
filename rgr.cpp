// 1) Шифр Вижинера
// 2) Шифровка с помощью квадрата Полибия
// 3) Двойная табличная перестановка
// Nikita Eliseev
#include "ecrypt_decrypt_funcs.h"
int main()
{
    ifstream fin;
    ofstream fout;
    setlocale(0, "");
    string text, key, user_pswd, user_choice = "0";
    string file_name_in = "in.txt", file_name_out, fin_text;
    int password = 1111;
    int user_choice_int = -1;
    bool error_flag = false;
    
    fin.open(file_name_in);
    if (!fin.is_open())
    {
        cout << "Не удалось открыть файл ввода." << endl;
        exit(0);
    }
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
        text = "mama mila ramu";
        key = "qwe";
        cout << "Исходное сообщение:" << text << endl;
        cout << "Ключ:" << key << endl << endl;

        cout << "Шифр Вижинера:" << endl;
        cout << "Введенное сообщение:" << text << endl;
        cout << "Введенный ключ:" << key << endl;
        cout << "Зашифрованное сообщение:" << VigenereEncrypt(text, key) << endl;
        cout << "Расшифрованное сообщение:" << VigenereDecrypt(VigenereEncrypt(text, key), key) << endl << endl;

        fout << "Шифр Вижинера:" << endl;
        fout << "Введенное сообщение:" << text << endl;
        fout << "Введенный ключ:" << key << endl;
        fout << "Зашифрованное сообщение:" << VigenereEncrypt(text, key) << endl;
        fout << "Расшифрованное сообщение:" << VigenereDecrypt(VigenereEncrypt(text, key), key) << endl << endl;

        text = "goroh v kastrule";
        key = "dima";
        cout << "Шифровка с помощью квадрата Полибия:" << endl;
        cout << "Введенное сообщение:" << text << endl;
        cout << "Введенный ключ:" << key << endl;
        cout << "Зашифрованное сообщение:" << PolybiusSquare_encrypt(text, key) << endl;
        cout << "Расшифрованное сообщение:" << PolybiusSquare_decrypt(PolybiusSquare_encrypt(text, key), key) << endl << endl;

        fout << "Шифровка с помощью квадрата Полибия:" << endl;
        fout << "Введенное сообщение:" << text << endl;
        fout << "Введенный ключ:" << key << endl;
        fout << "Зашифрованное сообщение:" << PolybiusSquare_encrypt(text, key) << endl;
        fout << "Расшифрованное сообщение:" << PolybiusSquare_decrypt(PolybiusSquare_encrypt(text, key), key) << endl << endl;

        key = "41532231";
        cout << "Шифровка двойной табличной перестановкой:" << endl;
        cout << "Введенное сообщение:" << text << endl;
        cout << "Введенный ключ:" << key << endl;
        cout << "Зашифрованное сообщение:" << DoubleTableSwapEncrypt(text, key) << endl;
        cout << "Расшифрованное сообщение:" << DoubleTableSwapDecrypt(DoubleTableSwapEncrypt(text, key), key) << endl;

        fout << "Шифровка двойной табличной перестановкой:" << endl;
        fout << "Введенное сообщение:" << text << endl;
        fout << "Введенный ключ:" << key << endl;
        fout << "Зашифрованное сообщение:" << DoubleTableSwapEncrypt(text, key) << endl;
        fout << "Расшифрованное сообщение:" << DoubleTableSwapDecrypt(DoubleTableSwapEncrypt(text, key), key) << endl;
        fout.close();
        system("pause");
        exit(0);
    }
    else if (stoi(fast_check) == 0)
    {
        
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
                    user_pswd = "-1";
                    system("cls");
                    user_menu();
                    fin.close();
                    fin.open(file_name_in);
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
                            << endl << "1) Допускаются только латинские символы."
                            << endl << "2) В ключе не должно быть пробелов." << endl;
                        //cout << "Введите исходное сообщение:";
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
                            if (stoi(user_pswd) != password)
                            {
                                cout << "Неверный пароль." << endl;
                            }
                            attempt++;
                        }
                        if (ChoiseToLeave) break;
                        string to_do;
                        cout << "Что вы хотите сделать?\n\"1\" - зашифровать\n\"2\" - расшифровать" << endl;
                        getline(cin, to_do);
                        cout << "Введите ключ шифрования:";
                        getline(cin, key);
                        for (int i = 0; i < key.size(); i++)
                        {
                            if (!((key[i] <= 90 && key[i] >= 65) || (key[i] <= 122 && key[i] >= 97)) && key[i] != ' ')
                            {
                                system("cls");
                                cout << "Ключ должен состоять только из латинских символов." << endl;
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
                        while (!fin.eof())
                        {
                            getline(fin, text);
                            if (text == "") continue;
                            for (int i = 0; i < text.size(); i++)
                            {
                                if (!((text[i] <= 90 && text[i] >= 65) || (text[i] <= 122 && text[i] >= 97)) && text[i] != ' ' && text[i]!=',' && text[i] !='.' && text[i]!='?' && text[i]!='!' && text[i]!=':' && text[i]!='-')
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
                            cout << "Шифр Вижинера:" << endl;
                            switch (stoi(to_do))
                            {
                            case 1:
                            {
                                cout << "Введенное сообщение:" << text << endl;
                                cout << "Введенный ключ:" << key << endl;
                                cout << "Зашифрованное сообщение:" << VigenereEncrypt(text, key) << endl;
                                fout<< VigenereEncrypt(text, key) << endl;
                                break;
                            }
                            case 2:
                            {
                                cout << "Введенное сообщение:" << text << endl;
                                cout << "Введенный ключ:" << key << endl;
                                cout << "Расшифрованное сообщение:" << VigenereDecrypt(text, key) << endl;
                                fout << VigenereDecrypt(text, key) << endl;
                                break;
                            }
                            }
                            user_pswd = "-1";
                        }
                        system("pause");
                        break;
                    }
                    case 2:
                    {
                        system("cls");
                        cout << "Шифровка с помощью квадрата Полибия:"
                            << endl << "1) Шифровка квадратом Полибия применима только к выражениям, у которых четное количество символов."
                            << endl << "2) Символы в ключе обязательно должны быть уникальны." << endl;
                        //cout << "Введите исходное сообщение:";
                        //getline(cin, text);
                        text = "";
                        fin.close();
                        fin.open(file_name_in);
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
                            if (stoi(user_pswd) != password)
                            {
                                cout << "Неверный пароль." << endl;
                            }
                            attempt++;
                        }
                        if (ChoiseToLeave) break;
                        string to_do;
                        cout << "Шифровка квадратом Полибия:" << endl;
                        metka1:
                        cout << "Что вы хотите сделать?\n\"1\" - зашифровать\n\"2\" - расшифровать" << endl;
                        getline(cin, to_do);
                        try
                        {
                            stoi(to_do);
                        }
                        catch (const std::exception&)
                        {
                            cout << "Необходимо выбрать число." << endl;
                            goto metka1;
                        }
                        if (to_do == "1" || to_do == "2")
                        {

                        }
                        else goto metka1;
                        
                        cout << "Введите ключ шифрования:";
                        getline(cin, key);
                        if (PolybiusSquare_encrypt(text, key) == "size.error")
                        {
                            cout << "Шифровка квадратом Полибия применима только к выражениям, у которых четное количество символов" << endl;
                            system("pause");
                            break;
                        }
                        for (int i = 0; i < key.size(); i++)
                        {
                            if (!((key[i] <= 90 && key[i] >= 65) || (key[i] <= 122 && key[i] >= 97)) && key[i] != ' ')
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
                        if (PolybiusSquare_encrypt(text, key) == "-1")
                        {
                            cout << "Каждый символ в ключе должен быть уникален." << endl;
                            system("pause");
                            break;
                        }
                        
                        while (!fin.eof())
                        {
                            getline(fin, text);
                            if (text == "") continue;
                            for (int i = 0; i < text.size(); i++)
                            {
                                if (!((text[i] <= 90 && text[i] >= 65) || (text[i] <= 122 && text[i] >= 97)) && text[i] != ' ' && text[i] != ',' && text[i] != '.' && text[i] != '?' && text[i] != '!' && text[i] != ':' && text[i] != '-')
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
                            switch (stoi(to_do))
                            {
                            case 1:
                            {
                                cout << "Введенное сообщение:" << text << endl;
                                cout << "Введенный ключ:" << key << endl;
                                cout << "Зашифрованное сообщение:" << PolybiusSquare_encrypt(text, key) << endl;
                                fout <<  PolybiusSquare_encrypt(text, key) << endl;
                                break;
                            }
                            case 2:
                            {
                                cout << "Введенное сообщение:" << text << endl;
                                cout << "Введенный ключ:" << key << endl;
                                cout << "Расшифрованное сообщение:" << PolybiusSquare_decrypt(text, key) << endl;
                                fout << PolybiusSquare_decrypt(text, key) << endl;
                                break;
                            }
                            }
                            user_pswd = "-1";
                        }
                        system("pause");
                        break;
                    }
                    case 3:
                    {
                        system("cls");
                        cout << "Шифровка двойной табличной перестановкой:" << endl
                            << endl << "1) Ключ (последовательность цифр) необходимо вводить в формате M * N, где M - количество строк, N - количество столбцов."
                            << endl << "\nЧисла M и N можно вычислить так: M - целая часть от корня из длины всего сообщения, а N "
                            << endl << "будет числом, при умножении которого на M получится число большее или равное длине строки." << endl;
                        cout << endl << "Пример: \"paparimskiy\", ключ: \"2341312\" (сначала меняем столбцы, их 4, по паттерну 2341, затем строки по паттерну 312, их 3) " << endl << endl;
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
                            if (stoi(user_pswd) != password)
                            {
                                cout << "Неверный пароль." << endl;
                            }
                            attempt++;
                        }
                        user_pswd = "-1";
                        if (ChoiseToLeave) break;
                        string to_do;
                        cout << "Шифровка двойной табличной перестановкой:" << endl;
                        cout << "Что вы хотите сделать?\n\"1\" - зашифровать\n\"2\" - расшифровать" << endl;
                        getline(cin, to_do);
                        
                        fin.close();
                        fin.open(file_name_in);
                        while (!fin.eof())
                        {
                            getline(fin, text);
                            if (text == "") continue;
                            for (int i = 0; i < text.size(); i++)
                            {
                                if (!((text[i] <= 90 && text[i] >= 65) || (text[i] <= 122 && text[i] >= 97)) && text[i] != ' ')
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
                            cout << "Введенное сообщение:" << text <<" ("<<text.size()<<") - пробелы" << endl;
                            cout << "Введите ключ шифрования:";
                            getline(cin, key);
                            /*try
                            {
                                stoi(key);
                            }
                            catch (const std::exception&)
                            {
                                cout << "Символы ключа шифрования должны быть цифрами.(либо ключ не влезает в int)" << endl;
                                system("pause");
                                break;
                            }*/
                            for (int as = 0; as < key.size(); as++)
                            {
                                if (key[as] < 49 || key[as]>57)
                                {
                                    cout << "Символы ключа шифрования должны быть цифрами." << endl;
                                    system("pause");
                                    break;
                                }
                            }
                            if (DoubleTableSwapEncrypt(text, key) == "wrong.key.size")
                            {
                                cout << "Неверная длина ключа, она должна быть суммой количества строк и столбцов." << endl;
                                system("pause");
                                break;
                            }
                            if (DoubleTableSwapEncrypt(text, key) == "wrong.stolbec")
                            {
                                cout << "Неверно введен ключ: номер столбца больше количества столбцов." << endl;
                                system("pause");
                                break;
                            }
                            if (DoubleTableSwapEncrypt(text, key) == "wrong.stroka")
                            {
                                cout << "Неверно введен ключ: номер строки больше количества строк." << endl;
                                system("pause");
                                break;
                            }
                            if (DoubleTableSwapEncrypt(text, key) == "equal.znacheniya")
                            {
                                cout << "В ключе введены повторяющиеся значения для переставления строк или столбцов." << endl;
                                system("pause");
                                break;
                            }
                            switch (stoi(to_do))
                            {
                            case 1:
                            {
                                //cout << "Введенное сообщение:" << text << endl;
                                cout << "Введенный ключ:" << key << endl;
                                cout << "Зашифрованное сообщение:" << DoubleTableSwapEncrypt(text, key) << endl;
                                fout << DoubleTableSwapEncrypt(text, key) << endl;
                                break;
                            }
                            case 2:
                            {
                                //cout << "Введенное сообщение:" << text << endl;
                                cout << "Введенный ключ:" << key << endl;
                                cout << "Расшифрованное сообщение:" << DoubleTableSwapDecrypt(text, key) << endl;
                                fout << DoubleTableSwapDecrypt(text, key) << endl;
                                break;
                            }
                            }
                            user_pswd = "-1";
                        }
                        system("pause");
                        break;
                    }
                    case 4:
                    {
                        cout << "В разработке другим студентом." << endl;
                        system("pause");
                        break;
                    }
                    case 5:
                    {
                        cout << "В разработке другим студентом." << endl;
                        system("pause");
                        break;
                    }
                    case 6:
                    {
                        cout << "В разработке другим студентом." << endl;
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