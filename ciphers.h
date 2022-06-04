#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "windows.h"
#include <fstream>
#include <set>

using namespace std;

void user_menu();
string Gronsfeld_Encrypt(string text, string key);
string Gronsfeld_Decrypt(string text, string key);
string TablePermutation_Encrypt(string text, string key);
string TablePermutation_Decrypt(string text, string key);
string Atbash_Encrypt(string text);
string Atbash_Decrypt(string text);