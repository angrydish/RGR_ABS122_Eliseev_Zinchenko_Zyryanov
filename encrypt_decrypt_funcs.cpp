#include "ecrypt_decrypt_funcs.h"

string DoubleTableSwapEncrypt(const string text, string key)
{
    string slovo, crypt;
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
        cout << "�������� ����� �����, ��� ������ ���� ������ ���������� ����� � �������� ("<<m+n<<")." << endl;
        exit(0);
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
            cout << "������� ������ ����: ����� ������� ������ ���������� ��������." << endl;
            exit(0);
        }
        stlb.insert((key[i] - '0') - 1);
        stolbci.push_back((key[i]-'0')-1);
    }
    for (int i = n; i < n + m; i++)
    {
        if (key[i] == '0' || (key[i] - '0') > m)
        {
            cout << "������� ������ ����: ����� ������ ������ ���������� �����." << endl;
            exit(0);
        }
        strk.insert((key[i] - '0') - 1);
        stroki.push_back((key[i] - '0')-1);
    }
    if (strk.size() != m || stlb.size() != n)
    {
        cout << "� ����� ������� ������������� �������� ��� ������������� ����� ��� ��������." << endl;
        exit(0);
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
        }
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
    temp = 0;
    for (auto z : stroki)
    {
        for (int j = 0; j < n; j++)
        {
            table_swap_strk[z][j] = table_swap_stlb[temp][j];
        }
        temp++;
    }
    for (auto i : table_swap_strk)
    {
        for (auto j : i)
        {
            if (j != '_')
            {
                crypt += j;
            }
            else
            {
                crypt += ' ';
            }
        }
    }
    return crypt;
}

string DoubleTableSwapDecrypt(const string text, string key)
{
    string crypt;
    int m = 0, n = 0;
    m = (int)sqrt(text.size());
    while (m * n < text.size()) n++;
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
            cout << "������� ������ ����: ����� ������� ������ ���������� ��������." << endl;
            exit(0);
        }
        stlb.insert((key[i] - '0') - 1);
        stolbci.push_back((key[i] - '0') - 1);
    }
    for (int i = n; i < n + m; i++)
    {
        if (key[i] == '0' || (key[i] - '0') > m)
        {
            cout << "������� ������ ����: ����� ������ ������ ���������� �����." << endl;
            exit(0);
        }
        strk.insert((key[i] - '0') - 1);
        stroki.push_back((key[i] - '0') - 1);
    }
    if (strk.size() != m || stlb.size() != n)
    {
        cout << "� ����� ������� ������������� �������� ��� ������������� ����� ��� ��������." << endl;
        exit(0);
    }
    for (int i = 0, k = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++, k++)
        {
            if (text[k] == ' ')
            {
                table[i][j] = '_';
            }
            else
            {
                table[i][j] = text[k];
            }
        }
    }
     int temp = 0;
    for (auto z : stolbci)
    {
        for (int i = 0; i < m; i++)
        {
            table_swap_stlb[i][temp] = table[i][z];
        }
        temp++;
    }
    temp = 0;
    for (auto z : stroki)
    {
        for (int j = 0; j < n; j++)
        {
            table_swap_strk[temp][j] = table_swap_stlb[z][j];
        }
        temp++;
    }
    for (auto i : table_swap_strk) {
        for (auto j : i)
        {
            if (j == '_') continue;
            else
            {
                crypt += j;
            }
        }
        cout << endl;
    }
    return crypt;
}

string PolybiusSquare_decrypt(const string xd, string key)
{
    set<char> unique_key;
    for (auto i : key)
    {
        unique_key.insert(key[i]);
    }
    if (unique_key.size() != key.size())
    {
        cout << "������ ������ � ����� ������ ���� ��������." << endl;
        exit(0);
    }
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

string PolybiusSquare_encrypt(const string xd, string key)
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

    //formirovanie zashivrovannogo soobshenija s pomoshju kvadrata polibija i sootvetstvujushih koordinat
    for (int i = 0; i < x1.size(); i++)
    {
        crypt.push_back(key_square[y1[i]][x1[i]]);
    }
    return crypt;
}

string VigenereEncrypt(const string text, string key, vector<char>& alphabet)
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

string VigenereDecrypt(const string text, string key, vector<char>& alphabet)
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
