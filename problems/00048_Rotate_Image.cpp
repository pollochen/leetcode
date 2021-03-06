// https://www.geeksforgeeks.org/rotate-a-matrix-by-90-degree-in-clockwise-direction-without-using-any-extra-space/
// Runtime: 3 ms, faster than 63.03% of C++ online submissions for Rotate Image.
// Memory Usage : 7.2 MB, less than 33.09 % of C++ online submissions for Rotate Image.
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // First rotation
        // with respect to main diagonal
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < row; col++) {
                swap(matrix[row][col], matrix[col][row]);
            }
        }

        // Second rotation
        // with respect to middle column
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n/2; col++) {
                swap(matrix[row][col], matrix[row][n - 1 - col]);
            }
        }
    }
};