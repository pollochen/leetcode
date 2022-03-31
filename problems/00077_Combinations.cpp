// https://www.cnblogs.com/grandyang/p/4332522.html
class Solution {
public:
    void combine_x(int n, int k, int level, vector<int> &out, vector<vector<int>> &result){
        if (out.size() == k) {
            // reach max, output it
            result.push_back(out);
            return;
        }
        for (int i = level; i <= n; i++) {
            out.push_back(i);
            combine_x(n, k, i+1, out, result);
            out.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int>  out;

        combine_x(n, k, 1, out, result);
        return result;
    }
};

// recursion with backtracking
// Runtime: 24 ms, faster than 84.76% of C++ online submissions for Combinations.
// Memory Usage: 9.1 MB, less than 78.34% of C++ online submissions for Combinations.
class Solution {
public:
    void combination_x(int n, int k, int start, vector<int> &out, vector<vector<int>> &result)
    {
        if (out.size() == k) {
            result.push_back(out);
            return;
        }
        for (int i = start; i <= n; i++) {
            // pick [i]
            out.push_back(i);
            combination_x(n, k, i+1, out, result);
            out.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> out;
        combination_x(n, k, 1, out, result);
        return result;
    }
}