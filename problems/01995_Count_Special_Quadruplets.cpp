class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int result = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                for (int l = j+1; l < n; l++) {
                    for (int m = l+1; m < n; m++) {
                        if (nums[i] + nums[j] + nums[l] == nums[m]) result++;
                    }
                }
            }
        }
        return result;
    }
};