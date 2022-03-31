// https://www.cnblogs.com/grandyang/p/4358848.html
// recursive and memorization
// Runtime: 4 ms, faster than 67.16% of C++ online submissions for Permutations.
// Memory Usage: 8.1 MB, less than 29.20% of C++ online submissions for Permutations.
class Solution {
public:
    void permute_x(vector<int>& nums, vector<bool> &visited, int level, vector<int> &out, vector<vector<int>> &result){
        if (level == nums.size()) {
            // reach max, output it
            result.push_back(out);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            // pick each element in nums
            if (visited[i] == true) continue;

            out.push_back(nums[i]);
            visited[i] = true;
            permute_x(nums, visited, level+1, out, result);
            visited[i] = false;
            out.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<bool> visted(nums.size());
        vector<int>  out;

        permute_x(nums, visted, 0, out, result);

        return result;
    }
};