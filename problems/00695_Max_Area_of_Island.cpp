// recursive and dfs search
// Runtime: 16 ms, faster than 91.61% of C++ online submissions for Max Area of Island.
// Memory Usage: 23.1 MB, less than 98.24% of C++ online submissions for Max Area of Island.
class Solution {
public:
    int max_area_of_island_dfs(vector<vector<int>>& grid, int row, int col)
    {
        int row_cnt = grid.size();
        int col_cnt = grid[0].size();
        if (grid[row][col] == 0) {
            return 0;
        }

        int count = 1;

        // mark this cell as read
        grid[row][col] = 0;

        // left
        if (col >= 1) count += max_area_of_island_dfs(grid, row, col-1);
        // right
        if ((col + 1) < col_cnt) count += max_area_of_island_dfs(grid, row, col+1);
        // up
        if (row >= 1) count += max_area_of_island_dfs(grid, row-1, col);
        // down
        if ((row + 1) < row_cnt) count += max_area_of_island_dfs(grid, row+1, col);

        return count;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int result = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    result = max(result, max_area_of_island_dfs(grid, i, j));
                }
            }
        }

        return result;
    }
};