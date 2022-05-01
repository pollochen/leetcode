// brute forace (intuitve)
// Runtime: 121 ms, faster than 72.67% of C++ online submissions for Lemonade Change.
// Memory Usage: 83.5 MB, less than 51.08% of C++ online submissions for Lemonade Change.
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int map[21];
        map[5] = 0;
        map[10] = 0;
        map[20] = 0;
        int x;
        for (int i = 0; i < bills.size(); i++) {
            x = bills[i];
            map[x]++;
            // pay change
            if (x == 10) {
                // change = 5
                if (map[5] == 0) return false;
                map[5]--;
            } else if (x == 20) {
                // change = 15
                if (map[5] > 0 && map[10] > 0) {
                    // 10 + 5
                    map[10]--;
                    map[5]--;
                } else if (map[5] >= 3) {
                    // 5+5+5
                    map[5] -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};