// Runtime: 4 ms, faster than 79.81% of C online submissions for Rotate Image.
// Memory Usage: 6.4 MB, less than 26.96% of C online submissions for Rotate Image.
void swap_int(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int n = matrixSize;
    // rotate by diag
    for (int row = 0; row < n; row++) {
        for (int col = row+1; col < n; col++) {
            swap_int(&matrix[row][col], &matrix[col][row]);
        }
    }
    // switch col
    for (int col = 0; col < n / 2; col++) {
        for (int row = 0; row < n; row++) {
            swap_int(&matrix[row][col], &matrix[row][n-1-col]);
        }
    }
}