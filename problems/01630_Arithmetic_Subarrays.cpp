// https://leetcode.com/problems/arithmetic-subarrays/discuss/1923850/C%2B%2B-sort-no-sort-two-simple-solution-with-explanation
// subarray + sort + check
// Runtime: 52 ms, faster than 90.10% of C++ online submissions for Arithmetic Subarrays.
// Memory Usage: 25.7 MB, less than 75.42% of C++ online submissions for Arithmetic Subarrays.
class Solution {
public:
    bool check(vector<int> &nums)
    {
        // initial condition
        if (nums.size() <= 2) return true;
        // save the intial diff value
        int diff = nums[1] - nums[0];
        for (int i = 2; i < nums.size(); i++)
        {
            if ((nums[i] - nums[i-1]) != diff) return false;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> result;
        int cnt = l.size();
        int start, end;
        for (int i = 0; i < cnt; i++) {
            start = l[i];
            end   = r[i];
            // make subarray from nums[start, end]
            vector<int> tmp(nums.begin() + start, nums.begin() + end + 1);
            // sort the subarray
            sort(tmp.begin(), tmp.end());
            // check if the subarry is valid
            result.push_back(check(tmp));
        }

        return result;
    }
};
// hash version
// Runtime: 312 ms, faster than 5.05% of C++ online submissions for Arithmetic Subarrays.
// Memory Usage: 76.9 MB, less than 5.24% of C++ online submissions for Arithmetic Subarrays.
class Solution {
public:
    bool check(vector<int>& nums, int start, int end)
    {
        unordered_map<int, int> umap;
        int val_min = INT_MAX;
        int val_max = INT_MIN;
        for (int i = start; i <= end; i++) {
            val_min = min(nums[i], val_min);
            val_max = max(nums[i], val_max);
            umap[nums[i]]++;
        }

        int cnt  = end - start;
        int step = (val_max - val_min) / (cnt);
        int cur  = val_min;
        while (cnt >= 0) {
            if (umap[cur] == 0) return false;
            umap[cur]--;
            cur += step;
            cnt--;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> result;
        int cnt = l.size();
        int start, end;
        for (int i = 0; i < cnt; i++) {
            result.push_back(check(nums, l[i], r[i]));
        }

        return result;
    }
};

// hash version with check
// Runtime: 212 ms, faster than 7.25% of C++ online submissions for Arithmetic Subarrays.
// Memory Usage: 75.9 MB, less than 5.24% of C++ online submissions for Arithmetic Subarrays.
class Solution {
public:
    bool check(vector<int>& nums, int start, int end)
    {
        unordered_map<int, int> umap;
        int val_min = INT_MAX;
        int val_max = INT_MIN;
        for (int i = start; i <= end; i++) {
            val_min = min(nums[i], val_min);
            val_max = max(nums[i], val_max);
            umap[nums[i]]++;
        }

        int cnt  = end - start;
        int step = (val_max - val_min) / (cnt);
        if ((val_max - val_min) % cnt != 0) return false;
        int cur  = val_min;
        while (cnt >= 0) {
            if (umap[cur] == 0) return false;
            umap[cur]--;
            cur += step;
            cnt--;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> result;
        int cnt = l.size();
        int start, end;
        for (int i = 0; i < cnt; i++) {
            result.push_back(check(nums, l[i], r[i]));
        }

        return result;
    }
};