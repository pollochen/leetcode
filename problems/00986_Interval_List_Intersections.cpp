// https://leetcode.com/problems/interval-list-intersections/solution/
// Runtime: 52 ms, faster than 35.28% of C++ online submissions for Interval List Intersections.
// Memory Usage: 18.7 MB, less than 77.92% of C++ online submissions for Interval List Intersections.
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> result;
        int i = 0;
        int j = 0;
        int start;
        int end;
        vector<int> out;
        while (i < firstList.size() && j < secondList.size()) {
            // check the intersection
            start = max(firstList[i][0], secondList[j][0]); // max for start points
            end   = min(firstList[i][1], secondList[j][1]); // min for end points
            
            if (start <= end) {
                // if start <= end, it means intersection exists
                out.clear();
                out.push_back(start);
                out.push_back(end);
                result.push_back(out);
            }
            
            // check end points, smaller end ponit should be removed
            if (firstList[i][1] < secondList[j][1]) i++;
            else j++;
        }
        return result;
    }
};