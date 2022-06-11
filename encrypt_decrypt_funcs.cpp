#include "ecrypt_decrypt_funcs.h"
void user_menu()
{
    cout << "Добро пожаловать!" << endl << "Выберите шифр:" << endl;
    for (int i = 0; i < 80; i++) cout << "-";
    cout << endl;
    cout << "\tНажмите \"1\" для выбора шифра Вижинера" << endl
        << "\tНажмите \"2\" для выбора шифра с помощью квадрата Полибия" << endl
        << "\tНажмите \"3\" для выбора шифра двойной табличной перестановкой" << endl
        << "\tНажмите \"4\" для выбора шифра Гронсфельда" << endl
        << "\tНажмите \"5\" для выбора табличной шифровке с ключевым словом" << endl
        << "\tНажмите \"6\" для выбора шифра Атбаш" << endl
        << "\tНажмите \"0\" для выхода из программы" << endl;
    for (int i = 0; i < 80; i++) cout << "-";
    cout << endl;
}

string DoubleTableSwapEncrypt(const string text, const string key)
{
    string slovo, crypt;
    int m = 0, n = 0;
    slovo = text;
    m = (int)sqrt(slovo.size());
    while (m * n < slovo.size()) n++;

    if (key.size() != m + n)
    {
        return "wrong.key.size";
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
            return "wrong.stolbec";
        }
        stlb.insert((key[i] - '0') - 1);
        stolbci.push_back((key[i] - '0') - 1);
    }
    for (int i = n; i < n + m; i++)
    {
        if (key[i] == '0' || (key[i] - '0') > m)
        {
            return "wrong.stroka";
        }
        strk.insert((key[i] - '0') - 1);
        stroki.push_back((key[i] - '0') - 1);
    }
    if (strk.size() != m || stlb.size() != n)
    {
        return "equal.znacheniya";
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
string DoubleTableSwapDecrypt(const string text, const string key)
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
            cout << "Неверно введен ключ: номер столбца больше количества столбцов." << endl;
            exit(0);
        }
        stlb.insert((key[i] - '0') - 1);
        stolbci.push_back((key[i] - '0') - 1);
    }
    for (int i = n; i < n + m; i++)
    {
        if (key[i] == '0' || (key[i] - '0') > m)
        {
            cout << "Неверно введен ключ: номер строки больше количества строк." << endl;
            exit(0);
        }
        strk.insert((key[i] - '0') - 1);
        stroki.push_back((key[i] - '0') - 1);
    }
    if (strk.size() != m || stlb.size() != n)
    {
        cout << "В ключе введены повторяющиеся значения для переставления строк или столбцов." << endl;
        exit(0);
    }
    for (int i = 0, k = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++, k++)
        {
            table[i][j] = text[k];
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
            crypt += j;
        }
    }
    return crypt;
}
string PolybiusSquare_encrypt(const string xd, const string key)
{
    string alph = "abcdefghiklmnopqrstuvwxyz";
    vector<int> x;
    vector<int> y;
    vector<int> x1;
    vector<int> y1;
    string crypt;
    string text;
    set<char> unique_key;
    for (auto i : key)
    {
        unique_key.insert(i);
    }
    if (unique_key.size() != key.size())
    {
        return "-1";
    }
    //formirovanie stroki(key + alphabet) dlya formirovaniya kdavrata
    alph = key + alph;
    for (int i = 0; i < xd.size(); i++)
    {
        if (xd[i] != ' ' && xd[i] != ',' && xd[i] != '.' && xd[i] != '?' && xd[i] != '!' && xd[i] != ':' && xd[i] != '-')
        {
            text.push_back(xd[i]);
        }
        else
        {
            continue;
        }
    }
    if (text.size() % 2 != 0)
    {
        return "size.error";
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
                j = -1;
                ind += 1;
            }
            if (text[ind] == 'j')
            {
                int ind_j = 0;
                int ind_i = 0;
                for (int z = 0; z < 5; z++)
                {
                    for (int c = 0; c < 5; c++)
                    {
                        if (key_square[z][c] == 'i')
                        {
                            ind_j = c;
                            ind_i = z;
                        }
                    }
                }
                x.push_back(ind_j);
                y.push_back(ind_i);
                i = 0;
                j = -1;
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
    string crypt1;
    for (int i = 0, d = 0; i < xd.size(); i++)
    {
        if (xd[i] == ' ')
        {
            crypt1.push_back(' ');
            d++;
        }
        else if (xd[i] == ',')
        {
            crypt1.push_back(',');
            d++;
        }
        else if (xd[i] == '.')
        {
            crypt1.push_back('.');
            d++;
        }
        else if (xd[i] == '!')
        {
            crypt1.push_back('!');
            d++;
        }
        else if (xd[i] == '?')
        {
            crypt1.push_back('?');
            d++;
        }
        else if (xd[i] == ':')
        {
            crypt1.push_back(':');
            d++;
        }
        else if (xd[i] == '-')
        {
            crypt1.push_back('-');
            d++;
        }
        else
        {
            crypt1.push_back(crypt[i - d]);
        }
    }
    return crypt1;
}
string PolybiusSquare_decrypt(const string xd, const string key)
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
        if (xd[i] != ' ' && xd[i] != ',' && xd[i] != '.' && xd[i] != '?' && xd[i] != '!' && xd[i] != ':' && xd[i] != '-')
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
    string crypt1;
    for (int i = 0, d = 0; i < xd.size(); i++)
    {
        if (xd[i] == ' ')
        {
            crypt1.push_back(' ');
            d++;
        }
        else if (xd[i] == ',')
        {
            crypt1.push_back(',');
            d++;
        }
        else if (xd[i] == '.')
        {
            crypt1.push_back('.');
            d++;
        }
        else if (xd[i] == '!')
        {
            crypt1.push_back('!');
            d++;
        }
        else if (xd[i] == '?')
        {
            crypt1.push_back('?');
            d++;
        }
        else if (xd[i] == ':')
        {
            crypt1.push_back(':');
            d++;
        }
        else if (xd[i] == '-')
        {
            crypt1.push_back('-');
            d++;
        }
        else
        {
            crypt1.push_back(decrypt[i - d]);
        }
    }
    return crypt1;
}
string VigenereEncrypt(const string text, const string key)
{
    vector<int> K1;
    vector<int> K2;
    vector<char> alphabet;
    string crypt, crypt1;
    for (int i = 65 + 32; i < 91 + 32; i++) alphabet.push_back(char(i));
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
        else if (text[i] == ',')
        {
            crypt1.push_back(',');
            d++;
        }
        else if (text[i] == '.')
        {
            crypt1.push_back('.');
            d++;
        }
        else if (text[i] == '!')
        {
            crypt1.push_back('!');
            d++;
        }
        else if (text[i] == '?')
        {
            crypt1.push_back('?');
            d++;
        }
        else if (text[i] == ':')
        {
            crypt1.push_back(':');
            d++;
        }
        else if (text[i] == '-')
        {
            crypt1.push_back('-');
            d++;
        }
        else
        {
            crypt1.push_back(crypt[i - d]);
        }
    }
    return crypt1;
}
string VigenereDecrypt(const string text, const string key)
{
    vector<int> K1;
    vector<int> K2;
    vector<char> alphabet;
    string crypt, crypt1;
    for (int i = 65 + 32; i < 91 + 32; i++) alphabet.push_back(char(i));
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
        else if (text[i] == ',')
        {
            crypt1.push_back(',');
            d++;
        }
        else if (text[i] == '.')
        {
            crypt1.push_back('.');
            d++;
        }
        else if (text[i] == '!')
        {
            crypt1.push_back('!');
            d++;
        }
        else if (text[i] == '?')
        {
            crypt1.push_back('?');
            d++;
        }
        else if (text[i] == ':')
        {
            crypt1.push_back(':');
            d++;
        }
        else if (text[i] == '-')
        {
            crypt1.push_back('-');
            d++;
        }
        else
        {
            crypt1.push_back(crypt[i - d]);
        }
    }
    return crypt1;
}

string Gronsfeld_Encrypt(const string text_cs, const string key_cs)
{
    setlocale(LC_ALL, "Rus");
    string text = text_cs;
    string key = key_cs;
    string encrypted_text;
    vector<int>index_isupper;
    vector<char>alphabet;
    vector<char>alphabet_sim = { ' ', '!', '.', '-', ',', ':', '?' };

    int cod_ascii = tolower((int)unsigned char(text[0]));

    if ((cod_ascii > 96 && cod_ascii < 123) || (cod_ascii > 64 && cod_ascii < 91)) {
        for (int i = 97; i < 123; i++) alphabet.push_back(char(i));
    }
    else if (cod_ascii > 223 && cod_ascii < 256) {
        for (int i = 224; i < 256; i++) alphabet.push_back(char(i));
    }
    for (int i = 0; key.size() < text.size(); i++) {
        key += key[i];
    }
    for (int i = 0; i < text.size(); i++) {
        int cod = (int)unsigned char(text[i]);
        if ((cod > 191 && cod < 224) || (cod > 64 && cod < 91)) {
            index_isupper.push_back(i);
            text[i] = (char)tolower(text[i]);
        }
        else if (isupper(text[i])) {
            index_isupper.push_back(i);
            text[i] = (char)tolower(text[i]);
        }
    }
    for (int i = 0; encrypted_text.size() < text.size(); i++) {
        if (text[i] == ' ' || text[i] == ',' || text[i] == '.' || text[i] == '?' || text[i] == '!' || text[i] == ':' || text[i] == '-') {
            auto n = find(alphabet_sim.begin(), alphabet_sim.end(), text[i]);
            int index = n - alphabet_sim.begin() + key[i] - '0';
            if (index >= alphabet_sim.size()) {
                encrypted_text += alphabet_sim[(index - alphabet_sim.size())];
            }
            else {
                encrypted_text += alphabet_sim[index];
            }
        }
        else {
            auto n = find(alphabet.begin(), alphabet.end(), text[i]);
            int index = n - alphabet.begin() + key[i] - '0';
            if (index >= alphabet.size()) {
                encrypted_text += alphabet[(index - alphabet.size())];
            }
            else {
                encrypted_text += alphabet[index];
            }
        }
    }
    for (auto& it : index_isupper) {
        encrypted_text[it] = (char)toupper(encrypted_text[it]);
    }
    return encrypted_text;
}
string Gronsfeld_Decrypt(const string text_cs, const string key_cs) {
    string text = text_cs;
    string key = key_cs;
    string decrypt_text;
    vector<int>index_isupper;
    vector<char>alphabet;
    vector<char>alphabet_sim = { ' ', '!', '.', '-', ',', ':', '?' };

    int cod_ascii = tolower((int)unsigned char(text[0]));
    if (cod_ascii > 96 && cod_ascii < 123) {
        for (int i = 97; i < 123; i++) alphabet.push_back(char(i));
    }
    else if (cod_ascii > 223 && cod_ascii < 256) {
        for (int i = 224; i < 256; i++) alphabet.push_back(char(i));
    }

    for (int i = 0; key.size() < text.size(); i++) {
        key += key[i];
    }
    for (int i = 0; i < text.size(); i++) {
        int cod = (int)unsigned char(text[i]);
        if ((cod > 191 && cod < 224) || (cod > 64 && cod < 91)) {
            index_isupper.push_back(i);
            text[i] = (char)tolower(text[i]);
        }
        else if (isupper(text[i])) {
            index_isupper.push_back(i);
            text[i] = (char)tolower(text[i]);
        }
    }
    for (int i = 0; decrypt_text.size() < text.size(); i++) {
        if (text[i] == ' ' || text[i] == ',' || text[i] == '.' || text[i] == '?' || text[i] == '!' || text[i] == ':' || text[i] == '-') {
            auto n = find(alphabet_sim.begin(), alphabet_sim.end(), text[i]);
            int index = n - alphabet_sim.begin() - (key[i] - '0');
            if (index < 0) {
                decrypt_text += alphabet_sim[(index + size(alphabet_sim))];
            }
            else {
                decrypt_text += alphabet_sim[index];
            }
        }
        else {
            auto n = find(alphabet.begin(), alphabet.end(), text[i]);
            int index = n - alphabet.begin() - (key[i] - '0');
            if (index < 0) {
                decrypt_text += alphabet[(index + size(alphabet))];
            }
            else {
                decrypt_text += alphabet[index];
            }
        }
    }
    for (auto& it : index_isupper) {
        decrypt_text[it] = (char)toupper(decrypt_text[it]);
    }
    return decrypt_text;
}
string TablePermutation_Encrypt(const string text, const string key_cs) {

    string encrypted_text, mama;
    string key = key_cs;

    for (int i = 0; i < text.size(); i++) {
        if (text[i] != ' ' && text[i] != ',' && text[i] != '.' && text[i] != '?' && text[i] != '!' && text[i] != ':' && text[i] != '-') {
            mama += text[i];
        }
    }
    int m = (mama.size() / key.size()) + 1;
    int n = key.size();
    vector<vector<char>> table_swap_stlb(m, vector<char>(n, 'z'));
    set<char>unique_key;
    for (int j = 0; j < key.size(); j++) {
        int min_bs = 255;
        int index = 0;
        for (int i = 0; i < key.size(); i++) {
            int cod_ascci = (int)unsigned char(key[i]);
            if ((cod_ascci > 223 && cod_ascci < 256) || (cod_ascci > 96 && cod_ascci < 123)) {
                if (cod_ascci <= min_bs) {
                    min_bs = cod_ascci;
                    index = i;
                }
            }
        }
        key[index] = (j + 1) + '0';
    }
    for (int i = 0; i < n; i++) {
        table_swap_stlb[0][i] = key[i];
    }
    for (int i = 0, t = 0; i < n; i++) {
        for (int j = 1; j < m; j++, t++) {
            table_swap_stlb[j][i] = mama[t];
        }
    }

    for (int j = 0, i = 0; j < n; j++, i++) {
        int min_bs = 255;
        int index = 0;
        for (int k = i; k < n; k++) {
            int cod_ascci = (table_swap_stlb[0][k] - '0');
            if (cod_ascci <= min_bs) {
                min_bs = cod_ascci;
                index = k;
            }
        }
        table_swap_stlb[0][index] = table_swap_stlb[0][j];
        table_swap_stlb[0][j] = ((min_bs)+'0');
        for (int s = 1; s < m; s++) {
            char a = table_swap_stlb[s][index];
            table_swap_stlb[s][index] = table_swap_stlb[s][j];
            table_swap_stlb[s][j] = a;
        }
    }
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++)
            encrypted_text += table_swap_stlb[i][j];
    }
    for (int i = 0; i < text.size(); i++) {
        if (text[i] == ' ' || text[i] == ',' || text[i] == '.' || text[i] == '?' || text[i] == '!' || text[i] == ':' || text[i] == '-') {
            encrypted_text.insert(i, 1, text[i]);
        }
    }
    return encrypted_text;
}
string TablePermutation_Decrypt(const string text, const string key_cs) {
    string decrypt_text, mama;
    string key = key_cs;
    for (int i = 0; i < text.size(); i++) {
        if (text[i] != ' ' && text[i] != ',' && text[i] != '.' && text[i] != '?' && text[i] != '!' && text[i] != ':' && text[i] != '-') {
            mama += text[i];
        }
    }
    int m = (mama.size() / key.size()) + 2;
    int n = key.size();
    vector<vector<char>> table_swap_stlb(m, vector<char>(n, 'z'));

    for (int j = 0; j < key.size(); j++) {
        int min_bs = 255;
        int index = 0;
        for (int i = 0; i < key.size(); i++) {
            int cod_ascci = (int)unsigned char(key[i]);
            if ((cod_ascci > 223 && cod_ascci < 256) || (cod_ascci > 96 && cod_ascci < 123)) {
                if (cod_ascci <= min_bs) {
                    min_bs = cod_ascci;
                    index = i;
                }
            }
        }
        key[index] = (j + 1) + '0';
    }
    for (int i = 0; i < n; i++) {
        table_swap_stlb[0][i] = key[i];
        table_swap_stlb[1][i] = (i + 1) + '0';
    }
    for (int i = 2, k = 0; i < m; i++) {
        for (int j = 0; j < n; j++, k++) {
            table_swap_stlb[i][j] = mama[k];
        }
    }
    for (int j = 0, i = 0; j < n; j++, i++) {
        int key_index = table_swap_stlb[0][j] - '0';
        int index = 0;
        int tut = 0;
        for (int k = i; k < n; k++) {
            int cod_ascci = (table_swap_stlb[1][k] - '0');
            if (cod_ascci == key_index) {
                index = k;
                tut = cod_ascci;
            }
        }
        table_swap_stlb[1][index] = table_swap_stlb[1][j];
        table_swap_stlb[1][j] = (tut + '0');
        for (int s = 2; s < m; s++) {
            char a = table_swap_stlb[s][index];
            table_swap_stlb[s][index] = table_swap_stlb[s][j];
            table_swap_stlb[s][j] = a;
        }
    }
    for (int i = 0, t = 0; i < n; i++) {
        for (int j = 2; j < m; j++, t++) {
            decrypt_text += table_swap_stlb[j][i];
        }
    }
    for (int i = 0; i < text.size(); i++) {
        if (text[i] == ' ' || text[i] == ',' || text[i] == '.' || text[i] == '?' || text[i] == '!' || text[i] == ':' || text[i] == '-') {
            decrypt_text.insert(i, 1, text[i]);
        }
    }
    return decrypt_text;
}
string Atbash_Encrypt(const string text_cs) {
    string text = text_cs;
    string encrypted_text;
    vector<int>index_isupper;
    vector<char>alphabet1;
    vector<char>alphabet2;

    int cod_ascii = tolower((int)unsigned char(text[0]));

    if (cod_ascii > 96 && cod_ascii < 123) {
        for (int i = 97; i < 123; i++) alphabet1.push_back(char(i));
        for (int i = 122; i > 96; i--) alphabet2.push_back(char(i));
    }
    else if (cod_ascii > 223 && cod_ascii < 256) {
        for (int i = 224; i < 256; i++) alphabet1.push_back(char(i));
        for (int i = 255; i > 223; i--) alphabet2.push_back(char(i));
    }
    for (int i = 0; i < text.size(); i++) {
        int cod = (int)unsigned char(text[i]);
        if ((cod > 191 && cod < 224) || (cod > 64 && cod < 91)) {
            index_isupper.push_back(i);
            text[i] = (char)tolower(text[i]);
        }
        else if (isupper(text[i])) {
            text[i] = (char)tolower(text[i]);
        }
    }
    for (int i = 0; encrypted_text.size() < text.size(); i++) {
        if (text[i] == ' ' || text[i] == ',' || text[i] == '.' || text[i] == '?' || text[i] == '!' || text[i] == ':' || text[i] == '-') {
            encrypted_text.insert(i, 1, text[i]);
        }
        else {
            auto n = find(alphabet1.begin(), alphabet1.end(), text[i]);
            int index = n - alphabet1.begin();
            encrypted_text += alphabet2[index];
        }
    }
    for (auto& it : index_isupper) {
        encrypted_text[it] = (char)toupper(encrypted_text[it]);
    }
    return encrypted_text;
}
string Atbash_Decrypt(const string text_cs) {
    string text = text_cs;
    string decrypt_text;
    vector<int>index_isupper;
    vector<char>alphabet1;
    vector<char>alphabet2;

    int cod_ascii = tolower((int)unsigned char(text[0]));

    if (cod_ascii > 96 && cod_ascii < 123) {
        for (int i = 97; i < 123; i++) alphabet2.push_back(char(i));
        for (int i = 122; i > 96; i--) alphabet1.push_back(char(i));
    }
    else if (cod_ascii > 223 && cod_ascii < 256) {
        for (int i = 224; i < 256; i++) alphabet2.push_back(char(i));
        for (int i = 255; i > 223; i--) alphabet1.push_back(char(i));
    }
    for (int i = 0; i < text.size(); i++) {
        int cod = (int)unsigned char(text[i]);
        if ((cod > 191 && cod < 224) || (cod > 64 && cod < 91)) {
            index_isupper.push_back(i);
            text[i] = (char)tolower(text[i]);
        }
        else if (isupper(text[i])) {
            text[i] = (char)tolower(text[i]);
        }
    }
    for (int i = 0; decrypt_text.size() < text.size(); i++) {
        if (text[i] == ' ' || text[i] == ',' || text[i] == '.' || text[i] == '?' || text[i] == '!' || text[i] == ':' || text[i] == '-') {
            decrypt_text.insert(i, 1, text[i]);
        }
        else {
            auto n = find(alphabet1.begin(), alphabet1.end(), text[i]);
            int index = n - alphabet1.begin();
            decrypt_text += alphabet2[index];
        }
    }
    for (auto& it : index_isupper) {
        decrypt_text[it] = (char)toupper(decrypt_text[it]);
    }
    return decrypt_text;
}