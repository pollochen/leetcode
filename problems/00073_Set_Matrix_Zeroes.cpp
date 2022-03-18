// https://www.cnblogs.com/grandyang/p/4341590.html
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row_cnt = matrix.size();
        int col_cnt = matrix[0].size();
        int row;
        int col;
        bool is_row_0_zero = false;
        bool is_col_0_zero = false;

        // check if row[0] should be zero out
        for (col = 0; col < col_cnt; col++) {
            if (matrix[0][col] == 0) {
                is_row_0_zero = true;
                break;
            }
        }

        // check if col[0] should be zero out
        for (row = 0; row < row_cnt; row++) {
            if (matrix[row][0] == 0) {
                is_col_0_zero = true;
                break;
            }
        }

        // come out the zero mask of row[0] and col[0]
        for (row = 1; row < row_cnt; row++) {
            for (col = 1; col < col_cnt; col++) {
                if (matrix[row][col] == 0) {
                    matrix[0][col] = 0;
                    matrix[row][0] = 0;
                }
            }
        }
        // mark zero for each node
        for (row = 1; row < row_cnt; row++) {
            for (col = 1; col < col_cnt; col++) {
                if (matrix[row][0] == 0 || matrix[0][col] == 0) {
                    matrix[row][col] = 0;
                }
            }
        }
        // mark zero for row[0]
        if (is_row_0_zero == true) {
            for (col = 0; col < col_cnt; col++) {
                matrix[0][col] = 0;
            }
        }
        // mark zero for col[0]
        if (is_col_0_zero == true) {
            for (row = 0; row < row_cnt; row++) {
                matrix[row][0] = 0;
            }
        }
    }
};