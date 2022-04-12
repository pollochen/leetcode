// https://leetcode.com/problems/zigzag-conversion/solution/
// Approach 1: Sort by Row
// Runtime: 12 ms, faster than 67.91% of C++ online submissions for Zigzag Conversion.
// Memory Usage: 10.6 MB, less than 45.35% of C++ online submissions for Zigzag Conversion.
#define DOWN 1
#define UP   2

class Solution {
public:
    int min_int(int x, int y)
    {
        if (x < y) return x;
        else return y;
    }    
    string convert(string s, int numRows) {
        string result;
        int row_cnt = min_int(s.length(), numRows);
        
        if (numRows == 1) return s;
        
        vector<string> rows(row_cnt);
        
        int dir = DOWN;
        int row = 0;
        for (int i = 0; i < s.length(); i++) {
            rows[row].push_back(s[i]);
            if (dir == DOWN) {
                // down
                row++;
                if (row == row_cnt) {
                    dir = UP;
                    row = row_cnt - 2;
                }                
            } else {
                // up
                row--;
                if (row < 0) {
                    row = 1;
                    dir = DOWN;
                }
            }
        }
        
        for (int i = 0; i < row_cnt; i++) {
            result += rows[i];
        }
        
        return result;
    }
};