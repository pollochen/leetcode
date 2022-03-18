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