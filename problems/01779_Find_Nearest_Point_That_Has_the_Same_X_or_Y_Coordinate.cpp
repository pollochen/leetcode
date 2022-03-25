// Runtime: 164 ms, faster than 85.83% of C++ online submissions for Find Nearest Point That Has the Same X or Y Coordinate.
// Memory Usage: 59.3 MB, less than 73.82% of C++ online submissions for Find Nearest Point That Has the Same X or Y Coordinate.
class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int result = -1;
        int distance = INT_MAX;
        int d;
        for (int i = 0; i < points.size(); i++) {
            if (points[i][0] == x || points[i][1] == y) {
                // match found, calculate distance
                d = abs(points[i][0] - x) + abs(points[i][1] - y);
                if (d < distance) {
                    // min distance found, mark this index as result
                    distance = d;
                    result = i;
                }
            }
        }

        return result;
    }
};