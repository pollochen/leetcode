// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Pascal's Triangle.
// Memory Usage: 6.5 MB, less than 71.91% of C++ online submissions for Pascal's Triangle.
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        // if col index = 0 or col index = row -1, col[j] = 1
        // else col[i][j] = row[i-1][j-1] + row[i-1][j]
        vector<vector<int>> result;
        // row starts from 1 ~ numRows
        for (int i = 1; i <= numRows; i++) {
            vector<int> out;
            // elements is [0 ~ i]
            for (int j = 0; j < i; j++) {
                if (j == 0 || j == i-1) {
                    out.push_back(1);
                } else {
                    // row indx 1 would be [1] --> vector [0]
                    // we need to get row index [i-1] so real offset is [i-2]
                    vector<int> prev = result[i-1-1];
                    out.push_back(prev[j-1] + prev[j]);
                }
            }
            result.push_back(out);
        }
        return result;
    }
};

void print_matrix_int(vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            printf("%5d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void test_00118_Pascals_Triangle(void)
{
    Solution s;
    vector<vector<int>> result = s.generate(5);
    print_matrix_int(result);

    result = s.generate(1);
    print_matrix_int(result);

    result = s.generate(10);
    print_matrix_int(result);
}