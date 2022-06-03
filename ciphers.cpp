#include "ciphers.h"
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
                encrypted_text += alphabet[(index - alphabet.size())];//тут крашится
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