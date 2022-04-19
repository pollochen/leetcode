// Runtime: 26 ms, faster than 83.19% of C++ online submissions for Shift 2D Grid.
// Memory Usage: 16 MB, less than 10.54% of C++ online submissions for Shift 2D Grid.
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row_cnt = grid.size();
        int col_cnt = grid[0].size();
        int len = row_cnt * col_cnt;
        k = k % len; // make sure k is inside [0~len-1]

        if (k == 0) { return grid; }

        // serialize matrix to vector
        vector<int> x;
        for (int row = 0; row < row_cnt; row++) {
            for (int col = 0; col < col_cnt; col++) {
                x.push_back(grid[row][col]);
            }
        }
        // pick x[len - k, len - 1] to y[0, k]
        vector<int> y;
        for (int i = len - k; i < len; i++) {
            y.push_back(x[i]);
        }
        // pick x[0, k] to y[k + 1, len - 1]
        for (int i = 0; i < len - k; i++) {
            y.push_back(x[i]);
        }
        // de-serialize vector to matrix
        vector<vector<int>> result(row_cnt, vector<int>(col_cnt));
        for (int row = 0; row < row_cnt; row++) {
            for (int col = 0; col < col_cnt; col++) {
                result[row][col] = y[row * col_cnt + col];
            }
        }
        return result;
    }
};