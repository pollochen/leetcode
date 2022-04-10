class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> out;
        combinationSumX(candidates, 0, 0, target, out, result);
        return result;
    }

    void combinationSumX(vector<int> &candidates, int pos_start, int sum, int target, vector<int> &out,vector<vector<int>> &result)
    {

        if (sum == target) {
            result.push_back(out);
            return;
        }

        for (int i = pos_start;i < candidates.size(); i++) {
            int val = candidates[i];
            if ((sum + val) <= target) {
                out.push_back(val);
                sum += val;
                combinationSumX(candidates, i, sum, target, out, result);
                out.pop_back();
                sum -= val;
            }
        }
    }
};

// recursion
// Runtime: 8 ms, faster than 73.26 % of C++ online submissions for Combination Sum.
// Memory Usage : 10.8 MB, less than 88.58 % of C++ online submissions for Combination Sum.
class Solution {
public:
    void x(vector<int>& candidates, int target, int start, vector<int>& out, vector<vector<int>>& result)
    {
        if (target < 0) return;

        if (target == 0) {
            result.push_back(out);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            int num = candidates[i];
            if (target - num >= 0) {
                out.push_back(num);
                x(candidates, target - num, i, out, result);
                out.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> out;
        vector<vector<int>> result;
        x(candidates, target, 0, out, result);
        return result;
    }
};