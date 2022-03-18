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

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;
	Node* random;

	Node() : val(0), left(NULL), right(NULL), next(NULL), random(NULL) {}

	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL), random(NULL) {}

	Node(int _val, Node* _left, Node* _right, Node* _next)
		: val(_val), left(_left), right(_right), next(_next), random(NULL) {}
};

// TODO: reference additional headers your program requires here
void print_vector_int(vector<int> &x);
void print_vector_int(int* nums, int size);
void print_matrix_string(vector<vector<string>> matrix);
void print_matrix_char(vector<vector<char>> matrix);
void print_matrix_int(vector<vector<int>> matrix);
void print_node_list(ListNode* root);
bool is_digit(char ch);
void swap_int(int* x, int* y);

ListNode* make_list_node(vector<int> nums);