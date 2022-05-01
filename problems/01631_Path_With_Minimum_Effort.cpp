// https://leetcode.com/problems/path-with-minimum-effort/discuss/1987830/C%2B%2B-two-solutions-Dijkstra-and-BinarySearch-%2B-BFS
// BFS + binary search
// Runtime: 402 ms, faster than 40.59% of C++ online submissions for Path With Minimum Effort.
// Memory Usage: 51 MB, less than 24.85% of C++ online submissions for Path With Minimum Effort.
class Solution {
public:
    bool isvalid(vector<vector<int>>& heights, int effort)
    {
                    // u   d   l  r
        int dr[4] = {  -1, 1,  0, 0};
        int dc[4] = {   0, 0, -1, 1};
        queue<pair<int, int>> que; // pair<row, col>

        int row_cnt = heights.size();
        int col_cnt = heights[0].size();

        vector<vector<bool>> visited(row_cnt, vector<bool>(col_cnt, false));

        que.push({0, 0});
        visited[0][0] = true;

        while (que.empty() == false) {
            pair<int, int> node = que.front();
            que.pop();

            int row = node.first;
            int col = node.second;

            // check if reach end (right, bottom)
            if (row == (row_cnt -1) && col == (col_cnt -1)) {
                return true;
            }

            int height_cur = heights[row][col];

            // check 4 directions from this node
            for (int i = 0; i < 4; i++) {
                int nr = row + dr[i];
                int nc = col + dc[i];
                // check matrix boundary
                if (nr >= 0 && nr < row_cnt && nc >= 0 && nc < col_cnt) {
                    // if node was visited, skip
                    if (visited[nr][nc] == false) {
                        // only the diff is smaller than target, push the node
                        int diff = abs(height_cur - heights[nr][nc]);
                        if (diff <= effort) {
                            visited[nr][nc] = true;
                            que.push({nr, nc});
                        }
                    }
                }
            }
        }

        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int l = 0;
        int r = 1000001;
        int result = INT_MAX;
        while (l <= r) {
            int m = (l + r) / 2;
            if (isvalid(heights, m) == true) {
                r = m - 1;
                result = m; // save the result so far
            } else {
                l = m + 1;
            }
        }
        return result;
    }
};