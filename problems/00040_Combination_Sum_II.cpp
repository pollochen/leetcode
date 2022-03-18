// https://leetcode.com/problems/combination-sum-ii/solution/
class Solution {
public:
    void combinationSum2x(vector<int>& candidates, int pos_start, int sum, int target, vector<int> &out, vector<vector<int>> &result) {
        if (sum == target) {
            result.push_back(out);
            return;
        }

        //int i = pos_start;
        for (int i = pos_start; i < candidates.size(); i++) {
            int candidate = candidates[i];
            if (i > pos_start && candidates[i] == candidates[i-1]) continue; // the array is sorted so duplicated number can be skipped in this iteration
            if ((sum + candidate) <= target) {
                // push this node
                out.push_back(candidate);
                // call next
                combinationSum2x(candidates, i+1, sum + candidate, target, out, result);
                // pop this node
                out.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> out;
        sort(candidates.begin(), candidates.end());
        combinationSum2x(candidates, 0, 0, target, out, result);
        return result;
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

void test_00040_Combination_Sum_II(void)
{
    Solution s;
    int nums_1[] = {10,1,2,7,6,1,5};
    int nums_2[] = {2,5,2,1,2};
    print_matrix_int(s.combinationSum2(int_array_to_vector(nums_1, sizeof(nums_1)/sizeof(int)), 8));
    print_matrix_int(s.combinationSum2(int_array_to_vector(nums_2, sizeof(nums_2)/sizeof(int)), 5));
}
