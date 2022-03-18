// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <map>
#include <conio.h> 
#include <time.h>
using namespace std;

// TODO: reference additional headers your program requires here
void print_vector_int(vector<int> &x);
void print_matrix_string(vector<vector<string>> matrix);
void print_matrix_char(vector<vector<char>> matrix);
void print_matrix_int(vector<vector<int>> matrix);
bool is_digit(char ch);