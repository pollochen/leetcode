// https://www.cnblogs.com/grandyang/p/4371526.html
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reach = nums[0];
        for (int i = 1; i < nums.size() - 1; i++) {
            // can it reach i?
            if (max_reach < i) {
                return false;
            }
            // update max_reach
            int reach = nums[i] + i;
            if (reach > max_reach) max_reach = reach;
        }
        if (max_reach >= (nums.size() - 1)) {
            return true;
        }else {
            return false;
        }
    }
};