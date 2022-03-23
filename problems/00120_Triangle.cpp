// memory: row * col
// Runtime: 14 ms, faster than 19.25% of C++ online submissions for Triangle.
// Memory Usage: 9 MB, less than 37.21% of C++ online submissions for Triangle.
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row_cnt = triangle.size();
        int col_cnt = triangle.size();
        vector<vector<int>> dp(row_cnt, vector<int>(col_cnt, 0));
        dp[0][0] = triangle[0][0];

        if (row_cnt == 1) {
            return dp[0][0];
        }

        int val;
        int result = INT_MAX;
        for (int row = 1; row < triangle.size(); row++) {
            for (int col = 0; col <= row; col++) {
                val = triangle[row][col];
                if (col == 0) {
                    dp[row][col] = dp[row-1][col] + val;
                }else if (col == row) {
                    dp[row][col] = dp[row-1][col-1] + val;
                } else {
                    dp[row][col] = min(dp[row-1][col-1] + val, dp[row-1][col] + val);
                }

                if (row == triangle.size() - 1) {
                    result = min(result, dp[row][col]);
                }
            }
        }
        return result;
    }
};

// memory: row
// Runtime: 13 ms, faster than 23.40% of C++ online submissions for Triangle.
// Memory Usage: 8.7 MB, less than 50.38% of C++ online submissions for Triangle.
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row_cnt = triangle.size();
        int col_cnt = triangle.size();
        vector<int> dp(row_cnt);
        dp[0] = triangle[0][0];

        if (row_cnt == 1) {
            return dp[0];
        }

        int val;
        int result = INT_MAX;
        for (int row = 1; row < triangle.size(); row++) {
            // we need to update dp from [row] to [0]
            for (int col = row; col >= 0; col--) {
                val = triangle[row][col];
                if (col == 0) {
                    dp[col] = dp[col] + val;
                }else if (col == row) {
                    dp[col] = dp[col-1] + val;
                } else {
                    dp[col] = min(dp[col-1] + val, dp[col] + val);
                }

                if (row == triangle.size() - 1) {
                    result = min(result, dp[col]);
                }
            }
        }
        return result;
    }
};

// very smart edition (bottom-up)
// https://leetcode.com/problems/triangle/discuss/1870863/C%2B%2Bor-faster-than-98-11-line-solution
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = triangle.size() - 2; i >= 0; --i){
            for (int j = 0; j <= i; ++j){
                triangle[i][j] += min(triangle[i+1][j],triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};

vector<int> int_array_to_vector(int *nums, int count)
{
    vector<int> result;
    for (int i = 0; i < count; i++) {
        result.push_back(nums[i]);
    }
    return result;
}

void test_00120_Triangle(void)
{
    Solution s;
    int t1_1[] = {2};
    int t1_2[] = {3, 4};
    int t1_3[] = {6, 5, 7};
    int t1_4[] = {4, 1, 8, 3};
    vector<vector<int>> t1;
    t1.push_back(int_array_to_vector(t1_1, 1));
    t1.push_back(int_array_to_vector(t1_2, 2));
    t1.push_back(int_array_to_vector(t1_3, 3));
    t1.push_back(int_array_to_vector(t1_4, 4));
    printf("%d\n", s.minimumTotal(t1));

    vector<vector<int>> t2;
    int t2_1[] = {-10};
    t2.push_back(int_array_to_vector(t2_1, 1));
    printf("%d\n", s.minimumTotal(t2));
}
