// brute force
// TLE
class Solution {
public:
    bool check(vector<int> &nums, int start, int end, int t)
    {
        if (end > nums.size() - 1) end = nums.size() - 1;
        for (int i = start; i < end; i++) {
            for (int j = i + 1; j <= end; j++) {
                if (labs((long)nums[i] - (long)nums[j]) <= t) {
                    return true;
                }                
            }
        }
        return false;
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size() < 2) return false;
        int count = nums.size() - k;
        if (count <= 0) count = 1;
        for (int i = 0; i < count; i++) {
            if (check(nums, i, i+k, t) == true) return true;
        }    
        return false;
    }
};

test case:
[1,2,3,1]
3
0
[0]
0
0
[1,2,2,3,4,5]
3
0
[-2147483648,2147483647]
1
1
[-5,5,5,5,5,15]
6
6
[-3,3]
2
4