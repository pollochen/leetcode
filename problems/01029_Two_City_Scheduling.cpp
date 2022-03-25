// https://www.cnblogs.com/grandyang/p/14401556.html
// Runtime: 8 ms, faster than 42.77% of C++ online submissions for Two City Scheduling.
// Memory Usage: 8 MB, less than 47.20% of C++ online submissions for Two City Scheduling.
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int result = 0;
        vector<int> refund;
        for (int i = 0; i < costs.size(); i++) {
            // assume every goes to city A, we get cost A
            result += costs[i][0];
            // save the differences if we go to city B instead of B
            refund.push_back(costs[i][1] - costs[i][0]);
        }
        // sort the differences (smaller means going to B is a better idea)
        sort(refund.begin(), refund.end());
        // add differences with N elements since we need N persons go to city B
        for (int i = 0; i < costs.size() / 2; i++) {
            result += refund[i];
        }
        return result;
    }
};