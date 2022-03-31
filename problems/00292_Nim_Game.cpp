// Runtime: 5 ms, faster than 7.19% of C++ online submissions for Nim Game.
// Memory Usage: 5.9 MB, less than 16.48% of C++ online submissions for Nim Game.
class Solution {
public:
    bool canWinNim(int n) {
        if ((n % 4) == 0) return false;
        else return true;
    }
};