#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
string PolybiusSquare_decrypt(const string xd, const string key);
string PolybiusSquare_encrypt(const string xd, const string key);
string VigenereDecrypt(const string text, const string key);
string VigenereEncrypt(const string text, const string key);
string DoubleTableSwapEncrypt(const string text, const string key);
string DoubleTableSwapDecrypt(const string text, const string key);