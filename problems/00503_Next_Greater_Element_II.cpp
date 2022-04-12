// https://leetcode.com/problems/next-greater-element-ii/solution/
// monotnoic stack with duplicate array
// Runtime: 36 ms, faster than 83.44% of C++ online submissions for Next Greater Element II.
// Memory Usage: 24 MB, less than 40.90% of C++ online submissions for Next Greater Element II.
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> result(nums.size(), -1);
        stack<int> stk;
        int idx;
        for (int i = ((nums.size() * 2) - 1); i >= 0; i--) {
            idx = i % nums.size();
            while(stk.empty() == false && stk.top() <= nums[idx]) {
                stk.pop();
            }
            if (stk.empty() == true) {
                //result.push_back(-1);
            } else {
                result[idx] = stk.top();
            }
            stk.push(nums[idx]);
        }
        return result;
    }
};