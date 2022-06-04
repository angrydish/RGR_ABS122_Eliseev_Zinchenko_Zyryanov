#include "ciphers.h"
void user_menu()
{
    cout << "Äîáðî ïîæàëîâàòü!" << endl << "Âûáåðèòå øèôð:" << endl;
    for (int i = 0; i < 80; i++) cout << "-";
    cout << endl;
    cout << "\tÍàæìèòå \"1\" äëÿ âûáîðà øèôðà Âèæèíåðà" << endl
        << "\tÍàæìèòå \"2\" äëÿ âûáîðà øèôðà ñ ïîìîùüþ êâàäðàòà Ïîëèáèÿ" << endl
        << "\tÍàæìèòå \"3\" äëÿ âûáîðà øèôðà äâîéíîé òàáëè÷íîé ïåðåñòàíîâêîé" << endl
        << "\tÍàæìèòå \"4\" äëÿ âûáîðà øèôðà Ãðîíñôåëüäà" << endl
        << "\tÍàæìèòå \"5\" äëÿ âûáîðà øèôðà ïðîñòîé òàáëè÷íîé ïåðåñòàíîâêîé" << endl
        << "\tÍàæìèòå \"6\" äëÿ âûáîðà øèôðà Ïëåéôåðà" << endl
        << "\tÍàæìèòå \"0\" äëÿ âûõîäà èç ïðîãðàììû" << endl;
    for (int i = 0; i < 80; i++) cout << "-";
    cout << endl;
}
string Gronsfeld_Encrypt(string text, string key)
{
    setlocale(LC_ALL, "Rus");

    string encrypted_text;
    vector<int>index_isupper;
    vector<char>alphabet;

    int cod_ascii = tolower((int)unsigned char(text[0]));

    if (cod_ascii > 96 && cod_ascii < 123) {
        for (int i = 97; i < 123; i++) alphabet.push_back(char(i));
    }
    else if (cod_ascii > 223 && cod_ascii < 256) {
        for (int i = 224; i < 256; i++) alphabet.push_back(char(i));
    }

    for (int i = 0; key.size() < (count_if(text.begin(), text.end(), [](int c) { return c != ' '; })); i++) {
        key += key[i];
    }
    for (int i = 0; i < text.size(); i++) {
        int cod = (int)unsigned char(text[i]);
        if (text[i] == ' ') {
            key.insert(i, 1, char(32));
        }
        else if ((cod > 191 && cod < 224) || (cod > 64 && cod < 91)) {
            index_isupper.push_back(i);
            text[i] = (char)tolower(text[i]);
        }
        else if (isupper(text[i])) {
            index_isupper.push_back(i);
            text[i] = (char)tolower(text[i]);
        }
    }
    for (int i = 0; encrypted_text.size() < text.size(); i++) {
        if (text[i] == ' ') {
            encrypted_text.insert(i, 1, char(32));
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
string Gronsfeld_Decrypt(string text, string key) {
    string decrypt_text;
    vector<int>index_isupper;
    vector<char>alphabet;

    int cod_ascii = tolower((int)unsigned char(text[0]));
    if (cod_ascii > 96 && cod_ascii < 123) {
        for (int i = 97; i < 123; i++) alphabet.push_back(char(i));
    }
    else if (cod_ascii > 223 && cod_ascii < 256) {
        for (int i = 224; i < 256; i++) alphabet.push_back(char(i));
    }

    for (int i = 0; key.size() < (count_if(text.begin(), text.end(), [](int c) { return c != ' '; })); i++) {
        key += key[i];
    }
    for (int i = 0; i < text.size(); i++) {
        int cod = (int)unsigned char(text[i]);
        if (text[i] == ' ') {
            key.insert(i, 1, char(32));
        }
        else if ((cod > 191 && cod < 224) || (cod > 64 && cod < 91)) {
            index_isupper.push_back(i);
            text[i] = (char)tolower(text[i]);
        }
        else if (isupper(text[i])) {
            index_isupper.push_back(i);
            text[i] = (char)tolower(text[i]);
        }
    }
    for (int i = 0; decrypt_text.size() < text.size(); i++) {
        if (text[i] == ' ') {
            decrypt_text.insert(i, 1, char(32));
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
string TablePermutation_Encrypt(string text, string key) {

    string encrypted_text, mama;

    for (int i = 0; i < text.size(); i++) {
        if (text[i] != ' ') {
            mama += text[i];
        }
    }

    int m = (mama.size() / key.size()) + 1;
    int n = key.size();
    vector<vector<char>> table_swap_stlb(m, vector<char>(n, 'z'));
    set<char>unique_key;

    if (mama.size() % key.size() != 0) {
        return "this won't work";
    }

    for (int j = 0; j < key.size(); j++) {
        int min_bs = 255;
        int index = 0;
        for (int i = 0; i < key.size(); i++) {
            if (key[i] == '0') {
                return "null cannot be entered in the key";
            }
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
    for (int j = 0; j < key.size(); j++) {
        int cod_ascci = (int)unsigned char(key[j]);
        if (!((cod_ascci > 223 && cod_ascci < 256) || (cod_ascci > 96 && cod_ascci < 123))) {
            unique_key.insert(text[j]);
    }
    if (unique_key.size() != key.size())
    {
        return "-1";
    }
    for (int i = 0; i < n; i++) {
        table_swap_stlb[0][i] = key[i];
    }
    for (int i = 0, t = 0; i < n; i++) {
        for (int j = 1; j < m; j++, t++) {
            table_swap_stlb[j][i] = text[t];
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
    return encrypted_text;
}
string TablePermutation_Decrypt(string text, string key){
    string decrypt_text, mama;

    for (int i = 0; i < text.size(); i++) {
        if (text[i] != ' ') {
            mama += text[i];
        }
    }

    int m = (mama.size() / key.size()) + 2;
    int n = key.size();
    vector<vector<char>> table_swap_stlb(m, vector<char>(n, 'z'));

    if (mama.size() % key.size() != 0) {
        return "this won't work";
    }

    for (int j = 0; j < key.size(); j++) {
        int min_bs = 255;
        int index = 0;
        for (int i = 0; i < key.size(); i++) {
            if (key[i] == '0') {
                return "null cannot be entered in the key";
            }
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
            table_swap_stlb[i][j] = text[k];
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
    return decrypt_text;
}
string Atbash_Encrypt(string text) {

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
        if (text[i] == ' ') {
            encrypted_text.insert(i, 1, char(32));
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
string Atbash_Decrypt(string text) {
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
        if (text[i] == ' ') {
            decrypt_text.insert(i, 1, char(32));
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