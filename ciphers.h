#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "windows.h"

using namespace std;

string Gronsfeld_Encrypt(string text, string key);
string Gronsfeld_Decrypt(string text, string key);

