#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
string PolybiusSquare_decrypt(string xd, string key);
string PolybiusSquare_encrypt(string xd, string key);
string VigenereDecrypt(string text, string key, vector<char>& alphabet);
string VigenereEncrypt(string text, string key, vector<char>& alphabet);
void DoubleTableSwapEncrypt(string text, string key);