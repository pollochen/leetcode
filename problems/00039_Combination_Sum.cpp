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