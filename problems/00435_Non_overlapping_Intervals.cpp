// https://leetcode.com/problems/non-overlapping-intervals/discuss/1907846/C%2B%2B-oror-Two-Ways-oror-95
// Runtime: 577 ms, faster than 58.68% of C++ online submissions for Non-overlapping Intervals.
// Memory Usage: 89.9 MB, less than 47.72% of C++ online submissions for Non-overlapping Intervals.
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int result = 0;
        // sort by start point
        sort(intervals.begin(), intervals.end());
        int end_point = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < end_point) {
                // overlap occur, we should keep smaller end point and remove larger end point
				// larger end point means it overlaps more
                result++;
                end_point = min(intervals[i][1], end_point);
            } else {
				// no overlap, set new end point
                end_point = intervals[i][1];
            }
        }
        return result;
    }
};