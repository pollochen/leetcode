// brute force
// Runtime: 26 ms, faster than 15.39% of C++ online submissions for The K Weakest Rows in a Matrix.
// Memory Usage: 12 MB, less than 7.93% of C++ online submissions for The K Weakest Rows in a Matrix.
bool comp(vector<int> v1, vector<int> v2)
{
    if (v1[1] < v2[1]) return true;
    if ((v1[1] == v2[1]) && (v1[0] < v2[0])) return true;
    return false;
}
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<vector<int>> info;
        vector<int> result;
		// calculate numers of 1 for each row
        for (int i = 0; i < mat.size(); i++) {
            vector<int> pair;
            int count = 0;
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 1) count++;
                else break;
            }
            pair.push_back(i);
            pair.push_back(count);
            info.push_back(pair);
        }
		// sort the row information
        sort(info.begin(), info.end(), comp);
		// publish answer
        for (int i = 0; i < k; i++) {
            result.push_back(info[i][0]);
        }
        return result;
    }
};

// faster version, no sort
// Runtime: 17 ms, faster than 50.87% of C++ online submissions for The K Weakest Rows in a Matrix.
// Memory Usage: 10.4 MB, less than 75.81% of C++ online submissions for The K Weakest Rows in a Matrix.
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> result;
        bool um[101];
        memset(um, false, sizeof(um));
		// scan cols
        for (int col = 0; col < mat[0].size(); col++) {
            for (int row = 0; row < mat.size(); row++) {
                if ((mat[row][col] == 0) && (um[row] == false)) {
					// it the value is 0 and the row was not picked before
                    k--;
                    um[row] = true;
                    result.push_back(row);
                    if (k == 0) return result;
                }
            }
        }
		// going here means there are some rows having all 1.
		// we need to publish them by index
        for (int row = 0; row < mat.size(); row++) {
            if (um[row] == false) {
                k--;
                um[row] = true;
                result.push_back(row);
                if (k == 0) return result;
            }
        }            
        return result;
    }
};