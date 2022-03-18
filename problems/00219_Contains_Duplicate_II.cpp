// https://www.cnblogs.com/grandyang/p/4539680.html
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k == 0) return false;

        map<int, int> m;

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            if ((m.find(x) != m.end()) && (abs(i- m[x]) <= k)) {
                return true;
            } else {
                m[x] = i;
            }
        }

        return false;
    }
};