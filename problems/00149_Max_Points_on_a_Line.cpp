// https://leetcode.com/problems/max-points-on-a-line/discuss/1946802/Sharing-my-simple-solution-with-clean-code
// Runtime: 65 ms, faster than 17.56% of C++ online submissions for Max Points on a Line.
// Memory Usage: 17.6 MB, less than 8.53% of C++ online submissions for Max Points on a Line.
class Solution {
public:
    
    pair<int, int> get_slope(vector<int> &a, vector<int> &b)
    {
        int x = a[0] - b[0];
        int y = a[1] - b[1];
        int div = gcd(x, y);
        return {x/div, y/div};
    }
    
    int maxPoints(vector<vector<int>>& points) {
        int result = 1; // 1 ponit case
        int size = points.size();

        // for each point i, we match each point j's slope with i
        for (int i = 0; i < size; i++) {
            
            map<pair<int, int>, int> map; // map: slop -> line count
            int cnt = 1;
            
            for (int j = 0; j < size; j++) {
                if (i != j) {
                    // calculate slope for points [i, j]
                    pair<int, int> slope = get_slope(points[i], points[j]);
                    map[slope]++;
                    cnt = max(cnt, map[slope] + 1); // 1 count means 2 points
                }
            }
            // save max points in this iteration
            result = max(result, cnt);
        }
        return result;
    }
};