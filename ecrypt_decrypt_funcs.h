#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <fstream>
using namespace std;

void user_menu();
string PolybiusSquare_encrypt(const string xd, const string key);
string PolybiusSquare_decrypt(const string xd, const string key);
string VigenereEncrypt(const string text, const string key);
string VigenereDecrypt(const string text, const string key);
string DoubleTableSwapEncrypt(const string text, const string key);
string DoubleTableSwapDecrypt(const string text, const string key);

string Gronsfeld_Encrypt(const string text_cs, const string key_cs);
string Gronsfeld_Decrypt(const string text_cs, const string key_cs);
string TablePermutation_Encrypt(const string text, const string key_cs);
string TablePermutation_Decrypt(const string text, const string key_cs);
string Atbash_Encrypt(const string text_cs);
string Atbash_Decrypt(const string text_cs);