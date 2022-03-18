#include "util.h"

void print_vector_int(vector<int> &x)
{
	printf("[");
	for (int i = 0; i < x.size(); i++) {
		printf("%d, ", x[i]);
	}
	printf("]\n");
}

void print_vector_int(int* nums, int size)
{
	printf("[");
	for (int i = 0; i < size; i++) {
		printf("%d, ", nums[i]);
	}
	printf("]\n");
}

void swap_int(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void print_matrix_string(vector<vector<string>> matrix)
{
	printf("[");
	for (int i = 0; i < matrix.size(); i++) {
		printf("[");
		for (int j = 0; j < matrix[i].size(); j++) {
			printf("%s, ", matrix[i][j].c_str());
		}
		printf("], ");
	}
	printf("]\n");
}

void print_matrix_int(vector<vector<int>> matrix)
{
	printf("[");
	for (int i = 0; i < matrix.size(); i++) {
		printf("[");
		for (int j = 0; j < matrix[i].size(); j++) {
			printf("%d, ", matrix[i][j]);
		}
		printf("], ");
	}
	printf("]\n");
}

void print_matrix_char(vector<vector<char>> matrix)
{
	printf("[");
	for (int i = 0; i < matrix.size(); i++) {
		printf("[");
		for (int j = 0; j < matrix[i].size(); j++) {
			printf("%c, ", matrix[i][j]);
		}
		printf("], ");
	}
	printf("]\n");
}
bool is_digit(char ch)
{
	return ch <= '9' && ch >= '0';
}