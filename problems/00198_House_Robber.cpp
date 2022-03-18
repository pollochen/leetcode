class Solution {
public:
    int rob(vector<int>& nums) {
        int sum = 0;
        int rob = 0;
        int skip = 0;
        for (int i = 0; i < nums.size(); i++) {
            int rob_i = max(rob, skip + nums[i]);
            int skip_i = max(skip, rob);
            rob = rob_i;
            skip = skip_i;
        }
        sum = max(rob, skip);
        return sum;
    }
};