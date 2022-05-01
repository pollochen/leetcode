// brute force
// TLE
class Solution {
public:

    void dfs(int n, int sum, vector<int> &out, vector<vector<int>> &result)
    {
        if (sum > n) return;

        if (sum == n) {
            result.push_back(out);
            return;
        }

        for (int i = 1; i < n; i++) {
            out.push_back(i);
            dfs(n, sum + i, out, result);
            out.pop_back();
        }
    }

    int get_product(vector<int> &sum)
    {
        if (sum.size() >= 2) {
            int ret = 1;
            for (int i = 0; i < sum.size(); i++) {
                ret = sum[i] * ret;
            }
            return ret;
        } else {
            return 0;
        }
    }

    int integerBreak(int n) {
        vector<vector<int>> sums;
        vector<int> out;
        dfs(n, 0, out, sums);

        int result = 0;
        for (int i = 0; i < sums.size(); i++) {
            result = max(result, get_product(sums[i]));
        }
        return result;
    }
};

// 1-D DP
/*
n=0 0
n=1 0
n=2 1+1
n=3 1+1+1 = 1 + f(2)
    1+2
n=4 1+1+1+1
    1+2+1 = 1 + f(3)
    2+1+1 = 2 + f(2)
    1+3
    2+2
n=5 (1+1+1+1+1, 1+2+1+1, 1+3+1, 2+2+1) = 1+f(4)
    (1+1+1+2, 1+2+2)                   = 2+f(3)
    1+4
    2+3
n=6 1+f(5)
    2+f(4)
    3+f(3)
    1+5
    2+4
    3+3
n=7
    1 + f(6)
    2 + f(5)
    3 + f(4)
    1 + 6
    2 + 5
    3 + 4
n=8 1 + f(7)
    2 + f(6)
    3 + f(5)
    4 + f(4)
    1 + 7
    2 + 6
    3 + 5
    4 + 4
*/
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Integer Break.
// Memory Usage: 6.3 MB, less than 6.54% of C++ online submissions for Integer Break.
class Solution {
public:
    int integerBreak(int n) {
        int result = 0;
        vector<int> dp(n+1);

        dp[0] = 0;
        dp[1] = 0;
        // i: [2, n]
        for (int i = 2; i <=n; i++) {
            // j: [1, i/2]
            for (int j = 1; j <= i / 2; j++) {
                int x = max(dp[i-j] * j, (i-j) * j); // dp[i] = max(dp[i-j] * j or (i-j) * j) for each 1 =< j < i
                dp[i] = max(dp[i], x);
            }
            result = max(dp[i], result);
        }
        return result;
    }
};