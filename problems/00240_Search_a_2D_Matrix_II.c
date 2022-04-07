// search from bottom left
// Runtime: 151 ms, faster than 34.08% of C online submissions for Search a 2D Matrix II.
// Memory Usage: 9.5 MB, less than 10.37% of C online submissions for Search a 2D Matrix II.
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int row_cnt = matrixSize;
    int col_cnt = matrixColSize[0];
    int row = row_cnt - 1;
    int col = 0;
    while(row >= 0 && col < col_cnt) {
        if (target == matrix[row][col]) return true;
        if (target > matrix[row][col]) col++;
        else row--; 
    }
    return false;
}