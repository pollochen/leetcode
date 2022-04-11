// Runtime: 3 ms, faster than 33.41 % of C++ online submissions for Spiral Matrix II.
// Memory Usage : 6.7 MB, less than 17.96 % of C++ online submissions for Spiral Matrix II.
class Solution {
public:
#define DIR_R 0
#define DIR_D 1
#define DIR_L 2
#define DIR_U 3
    vector<vector<int>> generateMatrix(int num) {
        vector<vector<int>> matrix(num, vector<int>(num));
        int m = matrix.size();
        int n = matrix[0].size();
        int dir = DIR_R;
        int steps_h = n - 1;
        int steps_v = m - 1;
        int row = 0, col = 0;
        int count = 1;

        for (int i = 0; i <= steps_h; i++) {
            matrix[row][i] = count++;
        }

        col += steps_h;
        dir = (dir + 1) % 4;

        while ( (steps_h != 0 && (dir == DIR_R || dir == DIR_L)) || (steps_v != 0 && (dir == DIR_U || dir == DIR_D))) {
            if (dir == DIR_R) {
                for (int i = 1; i <= steps_h; i++) {
                    matrix[row][col + i] = count++;
                }
                col += steps_h;
                steps_h--;
            } else if (dir == DIR_L) {
                for (int i = 1; i <= steps_h; i++) {
                    matrix[row][col - i] = count++;
                }
                col -= steps_h;
                steps_h--;
            } else if (dir == DIR_U) {
                for (int i = 1; i <= steps_v; i++) {
                    matrix[row-i][col] = count++;
                }
                row -= steps_v;
                steps_v--;
            } else {
                for (int i = 1; i <= steps_v; i++) {
                    matrix[row+i][col] = count++;
                }
                row += steps_v;
                steps_v--;
            }
            dir = (dir + 1) % 4;
        }
        return matrix;
    }
};