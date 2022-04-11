// BFS
// https://leetcode.com/problems/shortest-path-in-binary-matrix/discuss/1920266/Faster-oror-Easy-To-Understand-oror-C%2B%2B-Code
// Runtime: 68 ms, faster than 81.74% of C++ online submissions for Shortest Path in Binary Matrix.
// Memory Usage: 19.3 MB, less than 82.31% of C++ online submissions for Shortest Path in Binary Matrix.
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int size;
        int n = grid.size();
        int result = 1;

                    //  U,  L,  D, R, UL, DL, DR, UR
        int dx[8] = {   0, -1,  0, 1, -1,  1,  1, -1 };
        int dy[8] = {  -1,  0,  1, 0, -1, -1,  1,  1 };

        if (grid[0][0] == 1) return -1;

        q.push({0, 0});

        while (q.empty() == false) {
            size = q.size();
            for (int i = 0; i < size; i++) {
                pair<int, int> x = q.front(); q.pop();
                // check if reach (n-1, n-1)
                if (x.first == n-1 && x.second == n-1) {
                    // we go end with x iterations which is smallest
                    return result;
                }
                // seach 8 directions
                for (int dir = 0; dir < 8; dir++) {
                    int next_x = x.first  + dx[dir];
                    int next_y = x.second + dy[dir];
                    if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n && grid[next_x][next_y] == 0) {
                        // push if 0
                        q.push({next_x, next_y});
                        // mark as 1
                        grid[next_x][next_y] = 1;
                    }
                }
            }
            result++;
        }

        // can't reach (n-1, n-1)
        return -1;
    }
};