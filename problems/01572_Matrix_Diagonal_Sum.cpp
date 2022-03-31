class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
		int n = mat.size();
		int result = 0;
        
		for (int i = 0; i < n; i++) {
    		// scan primary diagonal
			int num = mat[i][i];
			result += num;
    		// scan secondary diagonal
            num = mat[n-1-i][i];
            result += num;
		}
        if ((n % 2) == 1) {
            result -= mat[n/2][n/2];
        }
		return result;   
    }
};

// brute force
// Runtime: 7 ms, faster than 99.55% of C++ online submissions for Matrix Diagonal Sum.
// Memory Usage: 11.3 MB, less than 11.37% of C++ online submissions for Matrix Diagonal Sum.
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int result = 0;
        int j;
        for (int i = 0; i < n; i++) {
            result += mat[i][i];
            result += mat[n-1-i][i];
        }
        if (n & 1) {
            result -= mat[n/2][n/2]; // decrase duplicate one
        }
        return result;
    }
};