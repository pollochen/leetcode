// BFS search
// Runtime: 13 ms, faster than 35.74% of C++ online submissions for Rotting Oranges.
// Memory Usage: 13.2 MB, less than 50.49% of C++ online submissions for Rotting Oranges.
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int orange_count = 0; // numbers of oranges
        int row_cnt = grid.size();
        int col_cnt = grid[0].size();
        queue<pair<int, int>> que;
        for (int row = 0; row < row_cnt; row++) {
            for (int col = 0; col < col_cnt; col++) {
                if (grid[row][col] > 0) {
                    orange_count++;
                }
                if (grid[row][col] == 2) {
                    que.push({ row, col });
                }
            }
        }

        // check if no orange
        if (orange_count == 0) return 0;
        
        int count = 0;
        int result = 0;
        int row, col;
        int size;
        while (que.empty() == false) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                pair<int, int> x = que.front();
                row = x.first;
                col = x.second;
                // remove this node from queue and add count
                count++;
                que.pop();
                // check left
                if (col > 0) {
                    if (grid[row][col - 1] == 1) {
                        // mark it as rotten
                        grid[row][col - 1] = 2;
                        que.push({row, col - 1});
                    }
                }
                // check right
                if (col < col_cnt - 1) {
                    if (grid[row][col + 1] == 1) {
                        // mark it as rotten
                        grid[row][col + 1] = 2;
                        que.push({ row, col + 1 });
                    }
                }
                // check up
                if (row > 0) {
                    if (grid[row-1][col] == 1) {
                        // mark it as rotten
                        grid[row-1][col] = 2;
                        que.push({ row -1, col});
                    }
                }

                // check down
                if (row < row_cnt - 1) {
                    if (grid[row + 1][col] == 1) {
                        // mark it as rotten
                        grid[row + 1][col] = 2;
                        que.push({ row + 1, col });
                    }
                }
            }
            // all rotten
            if (count == orange_count) {
                return result;
            }
            // add one minute
            result++;
        }

        // reaching here means we have removed all rotten oranges but there are fresh oranges
        return -1;
    }
};