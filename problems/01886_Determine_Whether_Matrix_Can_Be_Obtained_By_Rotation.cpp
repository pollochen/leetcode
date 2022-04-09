// Runtime: 8 ms, faster than 44.81% of C++ online submissions for Determine Whether Matrix Can Be Obtained By Rotation.
// Memory Usage: 11.1 MB, less than 91.86% of C++ online submissions for Determine Whether Matrix Can Be Obtained By Rotation.
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
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if (mat == target) return true;
        for (int i = 0; i < 3; i++) {
            rotate(mat);
            if (mat == target) return true;                
        }
        return false;
    }
};