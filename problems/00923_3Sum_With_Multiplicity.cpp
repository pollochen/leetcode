// https://leetcode.com/problems/3sum-with-multiplicity/discuss/1918457/C%2B%2B-Simplest-Solution-or-W-Easy-Explanation-or-Intuitive
// Runtime: 1630 ms, faster than 5.11% of C++ online submissions for 3Sum With Multiplicity.
// Memory Usage: 10.8 MB, less than 20.41% of C++ online submissions for 3Sum With Multiplicity.
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int X) {
        int n = arr.size(), mod = 1e9+7, ans = 0;
        unordered_map<int, int> m;

        for(int i=0; i<n; i++) {
            ans = (ans + m[X - arr[i]]) % mod;

            // calculate and remember 2sum for [0, i], [1, i], ... [i-1, i]
            for(int j=0; j<i; j++) m[arr[i] + arr[j]]++;
        }
        return ans;
    }
};