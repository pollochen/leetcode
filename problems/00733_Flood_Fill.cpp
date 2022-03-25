// Runtime: 15 ms, faster than 43.69% of C++ online submissions for Flood Fill.
// Memory Usage: 13.8 MB, less than 91.57% of C++ online submissions for Flood Fill.
class Solution {
public:
    void flood_fill_dfs(vector<vector<int>>& image, int row, int col, int target, int newColor) {
        int row_cnt = image.size();
        int col_cnt = image[0].size();
        if (image[row][col] != target) {
            return;
        }
        image[row][col] = newColor;
        // left
        if (((col - 1) >= 0) && (image[row][col-1] == target)) flood_fill_dfs(image, row, col-1, target, newColor);
        // right
        if (((col + 1) < col_cnt) && (image[row][col+1] == target)) flood_fill_dfs(image, row, col+1, target, newColor);
        // up
        if (((row - 1) >= 0) && (image[row-1][col] == target)) flood_fill_dfs(image, row-1, col, target, newColor);
        // down
        if (((row + 1) < row_cnt) && (image[row+1][col] == target)) flood_fill_dfs(image, row+1, col, target, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] != newColor) {
            flood_fill_dfs(image, sr, sc, image[sr][sc], newColor);
        }
        return image;
    }
};

// Runtime: 12 ms, faster than 61.75% of C++ online submissions for Flood Fill.
// Memory Usage: 14 MB, less than 50.54% of C++ online submissions for Flood Fill.
class Solution {
public:
    void flood_fill_dfs(vector<vector<int>>& image, int row, int col, int target, int newColor) {
        int row_cnt = image.size();
        int col_cnt = image[0].size();
        image[row][col] = newColor;
        // left
        if (((col - 1) >= 0) && (image[row][col-1] == target)) flood_fill_dfs(image, row, col-1, target, newColor);
        // right
        if (((col + 1) < col_cnt) && (image[row][col+1] == target)) flood_fill_dfs(image, row, col+1, target, newColor);
        // up
        if (((row - 1) >= 0) && (image[row-1][col] == target)) flood_fill_dfs(image, row-1, col, target, newColor);
        // down
        if (((row + 1) < row_cnt) && (image[row+1][col] == target)) flood_fill_dfs(image, row+1, col, target, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] != newColor) {
            flood_fill_dfs(image, sr, sc, image[sr][sc], newColor);
        }
        return image;
    }
};

// extreme test case
[[0,0,0],[0,1,1]]
1
1
1