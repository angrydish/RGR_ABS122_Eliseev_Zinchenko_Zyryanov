// 1) Шифр Вижинера
// 2) Шифровка с помощью квадрата Полибия
// 3) Двойная табличная перестановка
// Nikita Eliseev
// 4) Шифр Гронсфельда
// 5) Табличная шифровка с ключевым словом
// 6) Шифр Атбаш
// Zinchenko Matvey
#include "ecrypt_decrypt_funcs.h";
int main()
{
    ifstream fin;
    ofstream fout;
    setlocale(0, "");
    string text, key, user_pswd, user_choice = "0";
    string file_name_in, file_name_out, fin_text;
    int password = 1111;
    int user_choice_int = -1;
    bool error_flag = false;
    bool error_flag2 = true;

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
        fout.open("out.txt");
        text = "mama mila ramu";
        key = "qwe";

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

        key = "41322341";
        cout << "Шифровка двойной табличной перестановкой:" << endl;
        cout << "Введенное сообщение:" << text << endl;
        cout << "Введенный ключ:" << key << endl;
        cout << "Зашифрованное сообщение:" << DoubleTableSwapEncrypt(text, key) << endl;
        cout << "Расшифрованное сообщение:" << DoubleTableSwapDecrypt(DoubleTableSwapEncrypt(text, key), key) << endl << endl;

        fout << "Шифровка двойной табличной перестановкой:" << endl;
        fout << "Введенное сообщение:" << text << endl;
        fout << "Введенный ключ:" << key << endl;
        fout << "Зашифрованное сообщение:" << DoubleTableSwapEncrypt(text, key) << endl;
        fout << "Расшифрованное сообщение:" << DoubleTableSwapDecrypt(DoubleTableSwapEncrypt(text, key), key) << endl << endl;

        text = "ПерРвонАчалЬные ДокАзательства - ЯвляЮтся пЕрвоиСтОчнИками, СведЕний о оБстоятЕльсТвах!?";
        key = "2456";

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

        text = "sMeTaNa V sKvOrEcHnIkE???";
        key = "567";

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

        text = "БроДяГа - паРень Молодой.";
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

        text = "I wanna eat pizzaa!!!";
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

        text = "ВряД ли мНе пОмОгут Эти. КТО ЭТИ?";
        cout << "Шифр Атбаш: " << endl;
        cout << "Введенное сообщение: " << text << endl;
        cout << "Зашифрованное сообщение:" << Atbash_Encrypt(text) << endl;
        cout << "Расшифрованное сообщение:" << Atbash_Encrypt(Atbash_Encrypt(text)) << endl << endl;

        fout << "Шифр Атбаш: " << endl;
        fout << "Введенное сообщение: " << text << endl;
        fout << "Зашифрованное сообщение: " << Atbash_Encrypt(text) << endl;
        fout << "Расшифрованное сообщение: " << Atbash_Encrypt(Atbash_Encrypt(text)) << endl << endl;

        text = "Lets celebrate, great";
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
        cout << "Введите имя файла ввода:";
        getline(cin, file_name_in);
        fin.open(file_name_in);
        if (!fin.is_open())
        {
            cout << "Не удалось открыть файл ввода." << endl;
            system("pause");
            exit(0);
        }
        cout << "Введите имя файла вывода:";
        getline(cin, file_name_out);
        fout.open(file_name_out);
        if (!fout.is_open())
        {
            cout << "Не удалось открыть файл вывода." << endl;
            system("pause");
            exit(0);
        }
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
            if (stoi(user_pswd) == password && user_pswd.size() == 4)
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
                            << endl << endl << "1) Допускаются только латинские символы и ,.?!:-."
                            << endl << "2) В ключе не должно быть пробелов." << endl << endl;
                        //cout << "Введите исходное сообщение:";
                        bool ChoiseToLeave = false;
                        int attempt = 0;
                        while (true)
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
                            if (stoi(user_pswd) != password && user_pswd.size() == 4)
                            {
                                cout << "Неверный пароль." << endl;
                            }
                            else if (user_pswd.size() != 4)
                            {
                                cout << "Неверный пароль." << endl;
                            }
                            else
                            {
                                break;
                            }
                            attempt++;
                        }
                        if (ChoiseToLeave) break;
                        string to_do;
                    metka1:
                        cout << endl << "Что вы хотите сделать?\n\"1\" - зашифровать\n\"2\" - расшифровать" << endl;
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
                                if (!((text[i] <= 90 && text[i] >= 65) || (text[i] <= 122 && text[i] >= 97)) && text[i] != ' ' && text[i] != ',' && text[i] != '.' && text[i] != '?' && text[i] != '!' && text[i] != ':' && text[i] != '-')
                                {
                                    system("cls");
                                    cout << "Обнаружен символ, с которым программа не работает." << endl;
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
                                fout << VigenereEncrypt(text, key) << endl;
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
                        cout << "Шифровка с помощью квадрата Полибия (разрешено ,.?!:-.) :"
                            << endl << "1) Шифровка квадратом Полибия применима только к выражениям, у которых четное количество символов."
                            << endl << "2) Символы в ключе обязательно должны быть уникальны." << endl;
                        //cout << "Введите исходное сообщение:";
                        //getline(cin, text);
                        text = "";
                        fin.close();
                        fin.open(file_name_in);
                        bool ChoiseToLeave = false;
                        int attempt = 0;
                        while (true)
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
                            if (stoi(user_pswd) != password && user_pswd.size() == 4)
                            {
                                cout << "Неверный пароль." << endl;
                            }
                            else if (user_pswd.size() != 4)
                            {
                                cout << "Неверный пароль." << endl;
                            }
                            else
                            {
                                break;
                            }
                            attempt++;
                        }
                        if (ChoiseToLeave) break;
                        string to_do;
                        cout << "Шифровка квадратом Полибия:" << endl;
                    metka2:
                        cout << "Что вы хотите сделать?\n\"1\" - зашифровать\n\"2\" - расшифровать" << endl;
                        getline(cin, to_do);
                        try
                        {
                            stoi(to_do);
                        }
                        catch (const std::exception&)
                        {
                            cout << "Необходимо выбрать число." << endl;
                            goto metka2;
                        }
                        if (to_do == "1" || to_do == "2")
                        {

                        }
                        else goto metka2;

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
                                    cout << "Обнаружен символ, с которым программа не работает." << endl;
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
                                fout << PolybiusSquare_encrypt(text, key) << endl;
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
                            << endl << "1) Ключ (последовательность цифр) необходимо вводить размера M+N, где M - количество строк, N - количество столбцов."
                            << endl << "\nЧисла M и N можно вычислить так: M - целая часть от корня из длины всего сообщения, а N "
                            << endl << "будет числом, при умножении которого на M получится число большее или равное длине строки."
                            << endl << "Сначала пишется N цифр, затем еще M цифр." << endl;
                        cout << endl << "Пример: \"paparimskiy\", ключ: \"2341312\" (сначала меняем столбцы, их 4, по паттерну 2341, затем строки по паттерну 312, их 3) " << endl << endl;
                        bool ChoiseToLeave = false;
                        int attempt = 0;
                        while (true)
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
                            if (stoi(user_pswd) != password && user_pswd.size() == 4)
                            {
                                cout << "Неверный пароль." << endl;
                            }
                            else if (user_pswd.size() != 4)
                            {
                                cout << "Неверный пароль." << endl;
                            }
                            else
                            {
                                break;
                            }
                            attempt++;
                        }
                        user_pswd = "-1";
                        if (ChoiseToLeave) break;
                        string to_do;
                        cout << "Шифровка двойной табличной перестановкой:" << endl;
                    metka3:
                        cout << "Что вы хотите сделать?\n\"1\" - зашифровать\n\"2\" - расшифровать" << endl;
                        getline(cin, to_do);
                        try
                        {
                            stoi(to_do);
                        }
                        catch (const std::exception&)
                        {
                            cout << "Необходимо выбрать число." << endl;
                            goto metka3;
                        }
                        if (to_do == "1" || to_do == "2")
                        {

                        }
                        else goto metka3;

                        fin.close();
                        fin.open(file_name_in);
                        while (!fin.eof())
                        {
                            getline(fin, text);
                            if (text == "") continue;
                            for (int i = 0; i < text.size(); i++)
                            {
                                if (text[i] < 32 || text[i]>127)
                                {
                                    cout << "В строке есть русские символы." << endl;
                                    error_flag = true;
                                    break;
                                }
                            }
                            if (error_flag == true)
                            {
                                error_flag = false;
                                continue;
                            }
                            cout << "Введенное сообщение:\'" << text << "\' (" << text.size() << ")" << endl;
                            cout << "Введите ключ шифрования:";
                            getline(cin, key);
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
                                cout << "В ключе введены повторяющиеся значения для перестановки строк или столбцов." << endl;
                                system("pause");
                                break;
                            }
                            switch (stoi(to_do))
                            {
                            case 1:
                            {
                                //cout << "Введенное сообщение:" << text << endl;
                                cout << "Введенный ключ:" << key << endl;
                                cout << "Зашифрованное сообщение:\"" << DoubleTableSwapEncrypt(text, key) << "\"" << endl;
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
                        system("cls");
                        cout << "Шифр Гронсфельда:"
                            << endl << "1) Допускаются только английский или русский алфавит."
                            << endl << "2) В ключе не должно быть пробелов." << endl;
                        fin.close();
                        fin.open(file_name_in);
                        bool ChoiseToLeave = false;
                        int attempt = 0;
                        while (true)
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
                            if (stoi(user_pswd) != password && user_pswd.size() == 4)
                            {
                                cout << "Неверный пароль." << endl;
                            }
                            else if (user_pswd.size() != 4)
                            {
                                cout << "Неверный пароль." << endl;
                            }
                            else
                            {
                                break;
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
                        while (!fin.eof())
                        {
                            getline(fin, text);
                            if (text == "") continue;
                            error_flag2 = true;
                            while (true) {
                                int cod_ascii = (int)unsigned char(text[0]);
                                if (!((cod_ascii <= 90 && cod_ascii >= 65) || (cod_ascii <= 122 && cod_ascii >= 97)) && !(cod_ascii <= 255 && cod_ascii >= 192)) {
                                    cout << endl;
                                    cout << "Введеное сообщение:";
                                    cout << text << endl;
                                    cout << "Исходный текст должен начинаться с символов русского или английского алфавита " << endl;
                                    break;
                                }
                                int k = 0;
                                int m = 0;
                                for (int i = 0; i < text.size(); i++) {
                                    int cod_ascii = (int)unsigned char(text[i]);
                                    if (!((cod_ascii <= 90 && cod_ascii >= 65) || (cod_ascii <= 122 && cod_ascii >= 97)) && !(cod_ascii <= 255 && cod_ascii >= 192) && text[i] != ' ' && text[i] != ',' && text[i] != '.' && text[i] != '?' && text[i] != '!' && text[i] != ':' && text[i] != '-') {
                                        cout << endl;
                                        cout << "Введеное сообщение:";
                                        cout << text << endl;
                                        cout << "Программа работает только с русскими или английскими символами" << endl;
                                        error_flag2 = false;
                                        break;
                                    }
                                }
                                if (error_flag2 == false)
                                {
                                    error_flag2 = true;
                                    break;
                                }
                                for (int i = 0; i < text.size(); i++)
                                {
                                    int cod_ascii = (int)unsigned char(text[i]);
                                    if (!((cod_ascii <= 90 && cod_ascii >= 65) || (cod_ascii <= 122 && cod_ascii >= 97)) && text[i] != ' ' && text[i] != ',' && text[i] != '.' && text[i] != '?' && text[i] != '!' && text[i] != ':' && text[i] != '-')
                                    {
                                        k += 1;
                                    }
                                    else if (!(cod_ascii <= 255 && cod_ascii >= 192) && text[i] != ' ' && text[i] != ',' && text[i] != '.' && text[i] != '?' && text[i] != '!' && text[i] != ':' && text[i] != '-') {
                                        m += 1;
                                    }
                                }
                                if (m != 0 && k != 0) {
                                    cout << endl;
                                    cout << "Введеное сообщение:";
                                    cout << text << endl;
                                    cout << "Программа работает только с русскими или английскими символами, нельзя ввести сразу английские и русские символы " << endl;
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
                                break;
                            }
                        }
                        system("pause");
                        break;
                    }
                    case 5:
                    {
                        system("cls");
                        cout << "Табличная шифровка с ключевым словом:"
                            << endl << "1) Шифровка применима только к выражениям, у которых количество букв в тексте делится на количество символов в ключе нацело."
                            << endl << "2) Ключ принимает в себя, либо уникальный набор чисел(кроме 0), либо набор букв английского или русского алфавита." << endl;
                        fin.close();
                        fin.open(file_name_in);
                        bool ChoiseToLeave = false;
                        int attempt = 0;
                        while (true)
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
                            if (stoi(user_pswd) != password && user_pswd.size() == 4)
                            {
                                cout << "Неверный пароль." << endl;
                            }
                            else if (user_pswd.size() != 4)
                            {
                                cout << "Неверный пароль." << endl;
                            }
                            else
                            {
                                break;
                            }
                            attempt++;
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
                        set<char> unique_key;
                        for (int i = 0; i < key.size(); i++) {
                            unique_key.insert(key[i]);
                            int cod_ascii = (int)unsigned char(key[i]);
                            if (!(cod_ascii <= 122 && cod_ascii >= 97) && !(cod_ascii <= 255 && cod_ascii >= 224) && !(cod_ascii >= 48 && cod_ascii <= 57) && key[i] != ' ') {
                                system("cls");
                                cout << "Ключ принимает одни цифры или чисто русские или английские символы с нижним регистром" << endl;
                                system("pause");
                                error_flag = true;
                                break;
                            }
                            if ((cod_ascii <= 122 && cod_ascii >= 97) && (cod_ascii >= 49 && cod_ascii <= 57) && key[i] != ' ')
                            {
                                m += 1;
                            }
                            else if ((cod_ascii <= 255 && cod_ascii >= 224) && (cod_ascii >= 49 && cod_ascii <= 57) && key[i] != ' ') {
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
                            else if (cod_ascii == 48) {
                                system("cls");
                                cout << "В ключе не должно быть нулей" << endl;
                                system("pause");
                                error_flag = true;
                                break;
                            }
                        }
                        if ((m != 0 && k != 0) || (m != 0 && c != 0) || (k != 0 && c != 0)) {
                            system("cls");
                            cout << "ключ должен быть исключительно из чисел, либо с нижними регистроми английских или русских символов." << endl;
                            system("pause");
                            error_flag = true;
                            break;
                        }
                        if (c != 0) {
                            if (unique_key.size() != key.size())
                            {
                                system("cls");
                                cout << "ключ из цифр не должен содержать одинаковые значения." << endl;
                                system("pause");
                                error_flag = true;
                                break;
                            }
                        }
                        if (key.size() > 9) {
                            system("cls");
                            cout << "ключ не может быть больше 9 символов" << endl;
                            system("pause");
                            error_flag = true;
                            break;
                        }
                        if (error_flag == true)
                        {
                            error_flag = false;
                            break;
                        }
                        error_flag2 = true;
                        while (!fin.eof())
                        {
                            string mama;
                            getline(fin, text);
                            if (text == "") continue;
                            while (true) {
                                int k2 = 0;
                                int m2 = 0;
                                for (int i = 0; i < text.size(); i++) {
                                    int cod_ascii = (int)unsigned char(text[i]);
                                    if (!((cod_ascii <= 90 && cod_ascii >= 65) || (cod_ascii <= 122 && cod_ascii >= 97)) && !(cod_ascii <= 255 && cod_ascii >= 192) && text[i] != ' ' && text[i] != ',' && text[i] != '.' && text[i] != '?' && text[i] != '!' && text[i] != ':' && text[i] != '-') {
                                        cout << endl;
                                        cout << "Введенное сообщение: " << text << endl;
                                        cout << "Программа работает только с русскими или английскими символами" << endl;
                                        error_flag2 = false;
                                        break;
                                    }
                                    if (!((cod_ascii <= 90 && cod_ascii >= 65) || (cod_ascii <= 122 && cod_ascii >= 97)) && text[i] != ' ' && text[i] != ',' && text[i] != '.' && text[i] != '?' && text[i] != '!' && text[i] != ':' && text[i] != '-')
                                    {
                                        k2 += 1;
                                    }
                                    else if (!(cod_ascii <= 255 && cod_ascii >= 192) && text[i] != ' ' && text[i] != ',' && text[i] != '.' && text[i] != '?' && text[i] != '!' && text[i] != ':' && text[i] != '-') {
                                        m2 += 1;
                                    }
                                    if (text[i] != ' ' && text[i] != ',' && text[i] != '.' && text[i] != '?' && text[i] != '!' && text[i] != ':' && text[i] != '-') {
                                        mama += text[i];
                                    }
                                }
                                if (error_flag2 == false)
                                {
                                    error_flag2 = true;
                                    break;
                                }
                                if (m2 != 0 && k2 != 0) {
                                    cout << endl;
                                    cout << "Введенное сообщение: " << text << endl;
                                    cout << "Программа работает только с русскими или английскими символами, нельзя ввести сразу англиские и руские символы " << endl;
                                    break;
                                }
                                else if (mama.size() % key.size() != 0) {
                                    cout << endl;
                                    cout << "Введенное сообщение: " << text << endl;
                                    cout << "Шифровка применима только к выражениям, у которых количество букв в тексте делится на количество символов в ключе нацело. " << endl;
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
                                break;
                            }
                        }
                        system("pause");
                        break;
                    }
                    case 6:
                    {
                        system("cls");
                        cout << "Шифр Атбаша:" << endl;
                        fin.close();
                        fin.open(file_name_in);
                        bool ChoiseToLeave = false;
                        int attempt = 0;
                        while (true)
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
                            if (stoi(user_pswd) != password && user_pswd.size() == 4)
                            {
                                cout << "Неверный пароль." << endl;
                            }
                            else if (user_pswd.size() != 4)
                            {
                                cout << "Неверный пароль." << endl;
                            }
                            else
                            {
                                break;
                            }
                            attempt++;
                        }
                        user_pswd = "-1";
                        if (ChoiseToLeave) break;
                        string to_do;
                        cout << "Шифровка Атбаша:" << endl;
                        cout << "Что вы хотите сделать?\n\"1\" - зашифровать\n\"2\" - расшифровать" << endl;
                        getline(cin, to_do);
                        while (!fin.eof())
                        {
                            getline(fin, text);
                            if (text == "") continue;
                            error_flag2 = true;
                            while (true) {
                                int c = 0;
                                int t = 0;
                                int cod_ascii = (int)unsigned char(text[0]);
                                if (!((cod_ascii <= 90 && cod_ascii >= 65) || (cod_ascii <= 122 && cod_ascii >= 97)) && !(cod_ascii <= 255 && cod_ascii >= 192)) {
                                    cout << endl;
                                    cout << "Введеное сообщение:";
                                    cout << text << endl;
                                    cout << "Исходный текст должен начинаться с символов русского или английского алфавита " << endl;
                                    break;
                                }
                                for (int i = 0; i < text.size(); i++) {
                                    int cod_ascii = (int)unsigned char(text[i]);
                                    if (!((cod_ascii <= 90 && cod_ascii >= 65) || (cod_ascii <= 122 && cod_ascii >= 97)) && !(cod_ascii <= 255 && cod_ascii >= 192) && text[i] != ' ' && text[i] != ',' && text[i] != '.' && text[i] != '?' && text[i] != '!' && text[i] != ':' && text[i] != '-') {
                                        cout << endl;
                                        cout << "Исходное сообщение: " << text << endl;
                                        cout << "Программа работает только с русскими или английскими символами" << endl;
                                        error_flag2 = false;
                                        break;
                                    }
                                }
                                if (error_flag2 == false)
                                {
                                    error_flag = true;
                                    break;
                                }
                                for (int i = 0; i < text.size(); i++)
                                {
                                    int cod_ascii = (int)unsigned char(text[i]);
                                    if (!((cod_ascii <= 90 && cod_ascii >= 65) || (cod_ascii <= 122 && cod_ascii >= 97)) && text[i] != ' ' && text[i] != ',' && text[i] != '.' && text[i] != '?' && text[i] != '!' && text[i] != ':' && text[i] != '-')
                                    {
                                        c += 1;
                                    }
                                    else if (!(cod_ascii <= 255 && cod_ascii >= 192) && text[i] != ' ' && text[i] != ',' && text[i] != '.' && text[i] != '?' && text[i] != '!' && text[i] != ':' && text[i] != '-') {
                                        t += 1;
                                    }
                                }
                                if (c != 0 && t != 0) {
                                    cout << endl;
                                    cout << "Исходное сообщение: " << text << endl;
                                    cout << "Программа работает только с русскими или английскими символами, нельзя ввести сразу англиские и руские символы " << endl;
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
                                break;
                            }
                        }
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