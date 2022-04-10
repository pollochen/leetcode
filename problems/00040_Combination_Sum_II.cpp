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

// recursion with sorted array
// Runtime: 7 ms, faster than 69.52 % of C++ online submissions for Combination Sum II.
// Memory Usage : 10.7 MB, less than 68.29 % of C++ online submissions for Combination Sum II.
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
                if ((i == start) || (i > start && candidates[i - 1] != candidates[i])) {
                    // only select same number once in the same iteration
                    out.push_back(num);
                    x(candidates, target - num, i + 1, out, result); // must be (i + 1) since i is selected
                    out.pop_back();
                }
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> out;
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end()); // sort
        x(candidates, target, 0, out, result);
        return result;
    }
};
// recursion with sorted array + more condition check
// Runtime: 0 ms, faster than 100.00 % of C++ online submissions for Combination Sum II.
// Memory Usage : 10.5 MB, less than 87.00 % of C++ online submissions for Combination Sum II.
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
                if ((i == start) || (i > start && candidates[i - 1] != candidates[i])) {
                    out.push_back(num);
                    x(candidates, target - num, i + 1, out, result);
                    out.pop_back();
                }
            } else {
                // since the array is sorted, the later case won't match
                // we can stop this iteration
                break;
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> out;
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end()); // sort
        x(candidates, target, 0, out, result);
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
