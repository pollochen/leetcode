// https://www.cnblogs.com/grandyang/p/5968340.html
/*
3 -> [1,2,3] 1
4 -> [1,2,3] [2,3,4] [1,2,3,4] 1 + 2
5 -> [1,2,3] [2,3,4] [1,2,3,4]
     [3,4,5] [2, 3, 4, 5] [1,2,3,4,5] f(n-1) + 3
6 -> [1,2,3] [2,3,4] [1,2,3,4]
     [3,4,5] [2,3,4,5] [1,2,3,4,5]
     [4,5,6] [3,4,5,6] [2,3,4,5,6] [1,2,3,4,5,6] f(n-1) + 4 = (1 + 2 + 3) + 4

fn = (1 + ... + n-2)
*/
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int result = 0;
        int cur = 0;
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
                cur++;
                result += cur;
            } else {
                cur = 0;
            }
        }
        return result;
    }
};