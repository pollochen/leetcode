// sort and check one by one
// Runtime: 150 ms, faster than 34.53% of C++ online submissions for Contains Duplicate.
// Memory Usage: 46.7 MB, less than 76.54% of C++ online submissions for Contains Duplicate.
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i+1]) {
                return true;
            }
        }
        return false;
    }
};

// use hash map
// Runtime: 232 ms, faster than 5.12% of C++ online submissions for Contains Duplicate.
// Memory Usage: 51.4 MB, less than 61.38% of C++ online submissions for Contains Duplicate.
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> um;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            if (um.count(x) == 0) {
                // no found, insert it
                um[x] = 1;
            } else {
                // found, duplicate value x
                return true;
            }
        }
        return false;
    }
};

// use set
// Runtime: 208 ms, faster than 7.36% of C++ online submissions for Contains Duplicate.
// Memory Usage: 54.8 MB, less than 6.11% of C++ online submissions for Contains Duplicate.
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return std::set<int>(nums.begin(), nums.end()).size() != nums.size();
    }
};