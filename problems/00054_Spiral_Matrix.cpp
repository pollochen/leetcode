// brute force
// Runtime: 0 ms, faster than 100.00 % of C++ online submissions for Spiral Matrix.
// Memory Usage : 7 MB, less than 30.80 % of C++ online submissions for Spiral Matrix.
class Solution {
public:
#define DIR_R 0
#define DIR_D 1
#define DIR_L 2
#define DIR_U 3
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size();
        int n = matrix[0].size();
        int dir = DIR_R;
        int steps_h = n - 1;
        int steps_v = m - 1;
        int row = 0, col = 0;

        for (int i = 0; i <= steps_h; i++) {
            result.push_back(matrix[row][i]);
        }

        col += steps_h;
        dir = (dir + 1) % 4;

        while ( (steps_h != 0 && (dir == DIR_R || dir == DIR_L)) || (steps_v != 0 && (dir == DIR_U || dir == DIR_D))) {
            if (dir == DIR_R) {
                for (int i = 1; i <= steps_h; i++) {
                    result.push_back(matrix[row][col + i]);
                }
                col += steps_h;
                steps_h--;
            } else if (dir == DIR_L) {
                for (int i = 1; i <= steps_h; i++) {
                    result.push_back(matrix[row][col - i]);
                }
                col -= steps_h;
                steps_h--;
            } else if (dir == DIR_U) {
                for (int i = 1; i <= steps_v; i++) {
                    result.push_back(matrix[row-i][col]);
                }
                row -= steps_v;
                steps_v--;
            } else {
                for (int i = 1; i <= steps_v; i++) {
                    result.push_back(matrix[row+i][col]);
                }
                row += steps_v;
                steps_v--;
            }
            dir = (dir + 1) % 4;
        }
        return result;
    }
};