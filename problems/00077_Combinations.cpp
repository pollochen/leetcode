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