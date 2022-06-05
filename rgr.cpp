#include "ciphers.h"
// 1) Шифр Гронсфельда
// 2) Табличная шифровка с ключевым словом
// 3) Шифр Атбаш
// Zinchenko Matvey

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
    bool error_flag2 = true;

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
        text = "ПерРвонАчалЬные ДокАзательства - ЯвляЮтся пЕрвоиСтОчнИками, СведЕний о оБстоятЕльсТвах!?";
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

        text = "sMeTaNa V sKvOrEcHnIkE???";
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
                        fin.close();
                        fin.open(file_name_in);
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
                                    cout << "Программа работает только с русскими или английскими символами, нельзя ввести сразу англиские и руские символы " << endl;
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
                    case 2:
                    {
                        system("cls");
                        cout << "Табличная шифровка с ключевым словом:"
                            << endl << "1) Шифровка применима только к выражениям, у которых количество букв в тексте делится на количество символов в ключе нацело."
                            << endl << "2) Ключ принимает в себя, либо уникальный набор чисел(кроме 0), либо набор букв английского или русского алфавита." << endl;
                        fin.close();
                        fin.open(file_name_in);
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
                                cout << "ключ из цифер не должен содержать одинаковые значения." << endl;
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
                    case 3:
                    {
                        system("cls");
                        cout << "Шифр Атбаша:" << endl;
                        fin.close();
                        fin.open(file_name_in);
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
