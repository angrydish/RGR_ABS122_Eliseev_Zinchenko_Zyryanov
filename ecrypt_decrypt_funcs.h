#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
string PolybiusSquare_decrypt(const string xd, string key);
string PolybiusSquare_encrypt(const string xd, string key);
string VigenereDecrypt(const string text, string key, vector<char>& alphabet);
string VigenereEncrypt(const string text, string key, vector<char>& alphabet);
string DoubleTableSwapEncrypt(const string text, string key);
string DoubleTableSwapDecrypt(const string text, string key);