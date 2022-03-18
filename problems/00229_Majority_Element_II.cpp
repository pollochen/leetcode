class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0;
        int count2 = 0;
        int val_cur1 = INT_MIN;
        int val_cur2 = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val_cur1) {
                count1++;
            } else if (nums[i] == val_cur2) {
                count2++;
            } else if (count1 == 0) {
                val_cur1 = nums[i];
                count1 = 1;
            } else if (count2 == 0) {
                val_cur2 = nums[i];
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val_cur1) count1++;
            if (nums[i] == val_cur2) count2++;
        }
        vector<int> result;
        if (count1 > nums.size()/3) result.push_back(val_cur1);
        if (count2 > nums.size()/3) result.push_back(val_cur2);
        return result;
    }
};