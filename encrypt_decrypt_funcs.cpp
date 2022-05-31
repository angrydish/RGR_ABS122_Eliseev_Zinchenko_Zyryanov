#include "ecrypt_decrypt_funcs.h"

void DoubleTableSwapEncrypt(string text, string key)
{
    string slovo;
    int m = 0, n = 0;
    for (int i = 0; i < text.size(); i++)
    {
        if (text[i] == ' ') continue;
        else
        {
            slovo += text[i];
        }
    }
    m = (int)sqrt(slovo.size());
    while (m * n < slovo.size()) n++;
    
    if (key.size() != m + n)
    {
        cout << "Неверная длина ключа, она должна быть суммой количества строк и столбцов ("<<m+n<<")." << endl;
        //exit(0);
    }
    
    
    
    vector<vector<char>> table(m, vector<char>(n, '\0'));
    vector<vector<char>> table_swap_stlb(m, vector<char>(n, '\0'));
    vector<vector<char>> table_swap_strk(m, vector<char>(n, '\0'));
    vector<int> stolbci;
    set<int> stlb;
    vector<int> stroki;
    set<int>strk;
    for (int i = 0; i < n; i++)
    {
        if (key[i] == '0' || (key[i] - '0') > n)
        {
            cout << "Неверно введен ключ: номер столбца больше количества столбцов." << endl;
            //exit(0);
        }
        stlb.insert((key[i] - '0') - 1);
        stolbci.push_back((key[i]-'0')-1);
    }
    for (int i = n; i < n + m; i++)
    {
        if (key[i] == '0' || (key[i] - '0') > m)
        {
            cout << "Неверно введен ключ: номер строки больше количества строк." << endl;
            //exit(0);
        }
        strk.insert((key[i] - '0') - 1);
        stroki.push_back((key[i] - '0')-1);
    }
    if (strk.size() != m || stlb.size() != n)
    {
        cout << "В ключе введены повторяющиеся значения для переставления строк или столбцов." << endl;
        //exit(0);
    }
    
    if (m * n > slovo.size())
    {
        while (m * n > slovo.size())
        {
            slovo += '_';
        }
    }
    for (int i = 0, k = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++, k++)
        {
            table[i][j] = slovo[k];
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
    int temp = 0;
    for (auto z : stolbci)
    {
        for (int i = 0; i < m; i++)
        {
            table_swap_stlb[i][z] = table[i][temp];
        }
        temp++;
    }

    for (auto i : table_swap_stlb)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

string PolybiusSquare_decrypt(string xd, string key)
{
    string alph = "abcdefghiklmnopqrstuvwxyz";
    vector<int> x;
    vector<int> y;
    vector<int> x1;
    vector<int> y1;
    string crypt;
    string text;

    //formirovanie stroki(key + alphabet) dlya formirovaniya kdavrata
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

    //formirovanie pravilnoy stroki dlya kvadrata
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
    //formirovanie kvadrata s kluchom
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


    //zapolnenie koordinat kajdoi bukvi v sootvetstvuushie vectora
    for (int i = 0, ind = 0; i < 5 && ind < text.size(); i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (key_square[i][j] == text[ind])
            {
                x.push_back(j);
                y.push_back(i);
                i = 0;
                j = -1;
                ind += 1;
            }
        }
    }

    //vivod coordinat simvolov v kvadrate polibiya
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


    for (int i = 0; i < text.size() / 2; i++)
    {
        x1.push_back(x[i]);
        x1.push_back(y[i]);
    }
    for (int i = text.size() / 2; i < text.size(); i++)
    {
        y1.push_back(x[i]);
        y1.push_back(y[i]);
    }
    string decrypt;
    for (int i = 0; i < x1.size(); i++)
    {
        decrypt.push_back(key_square[y1[i]][x1[i]]);
    }
    return decrypt;
}

string PolybiusSquare_encrypt(string xd, string key)
{
    string alph = "abcdefghiklmnopqrstuvwxyz";
    vector<int> x;
    vector<int> y;
    vector<int> x1;
    vector<int> y1;
    string crypt;
    string text;

    //formirovanie stroki(key + alphabet) dlya formirovaniya kdavrata
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

    //formirovanie pravilnoy stroki dlya kvadrata
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
    //formirovanie kvadrata s kluchom
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


    //zapolnenie koordinat kajdoi bukvi v sootvetstvujushie vectora
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

    //mehanizm shifrovki po pravilam shifrovaniya s pomoshju kvadrata polibiya
    for (int i = 0; i < text.size(); i += 2)
        x1.push_back(x[i]);
    for (int i = 0; i < text.size(); i += 2)
        x1.push_back(y[i]);

    for (int i = 1; i < text.size(); i += 2)
        y1.push_back(x[i]);
    for (int i = 1; i < text.size(); i += 2)
        y1.push_back(y[i]);


    //vivod koordinat simvolov v kvadrate
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

    //formirovanie zashivrovannogo soobshenija s pomoshju kvadrata polibija i sootvetstvujushih koordinat
    for (int i = 0; i < x1.size(); i++)
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
