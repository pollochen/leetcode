// Runtime: 19 ms, faster than 26.64% of C++ online submissions for Reshape the Matrix.
// Memory Usage: 10.6 MB, less than 94.73% of C++ online submissions for Reshape the Matrix.
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        int org_size = m * n;
        int dst_size = r * c;
        int idx_r_org;
        int idx_c_org;
        int idx_r_dst;
        int idx_c_dst;
        if (org_size != dst_size) return mat; // invalid shape
        if (m == r && n == c) return mat; // same shape

        vector<vector<int>> result(r, vector<int>(c));

        for (int i = 0; i < org_size; i++) {
           idx_r_org = i / n;
           idx_c_org = i % n;
           idx_r_dst = i / c;
           idx_c_dst = i % c;
           result[idx_r_dst][idx_c_dst] = mat[idx_r_org][idx_c_org];
        }
        return result;
    }
};

// reduce variables...
// Runtime: 8 ms, faster than 93.13% of C++ online submissions for Reshape the Matrix.
// Memory Usage: 10.6 MB, less than 94.73% of C++ online submissions for Reshape the Matrix.
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        int org_size = m * n;
        int dst_size = r * c;
        if (org_size != dst_size) return mat; // invalid shape
        if (m == r && n == c) return mat; // same shape

        vector<vector<int>> result(r, vector<int>(c));

        for (int i = 0; i < org_size; i++) {
           result[i/c][i%c] = mat[i / n][i % n];
        }
        return result;
    }
};