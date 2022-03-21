// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Paths II.
// Memory Usage: 7.9 MB, less than 11.75% of C++ online submissions for Unique Paths II.
class Solution {
private:
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row_cnt = obstacleGrid.size();
        int col_cnt = obstacleGrid[0].size();
        int val_up;
        int val_left;
        vector<vector<int>> dp(row_cnt, vector<int>(col_cnt, 0));

        // init col 0
        for (int i = 0; i < row_cnt; i++) {
            if (obstacleGrid[i][0] == 1) {
                break; // later will be 0
            }
            dp[i][0] = 1;
        }

        // init row 0
        for (int i = 0; i < col_cnt; i++) {
            if (obstacleGrid[0][i] == 1) {
                break; // later will be 0
            }
            dp[0][i] = 1;
        }

        for (int row = 1; row < row_cnt; row++) {
            for (int col = 1; col < col_cnt; col++) {
                // if obstacle = true, it's dp would be 0
                if (obstacleGrid[row][col] == 1) {
                    dp[row][col] = 0;
                    continue;
                }
                // otherwise it's dp will be (dp[up] + dp[left])
                dp[row][col] = dp[row-1][col] + dp[row][col-1];
            }
        }
        return dp[row_cnt-1][col_cnt-1];
    }
};

// test case
[[0,0,1],[0,1,0],[1,0,0]] ==> 0
[[1,0]] ==> 0