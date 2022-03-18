class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int len = bits.size();
        int i = 0;
        int step;
        while (i < len) {
            if (bits[i] == 0) step = 1;
            else step = 2;
            i += step;
        }
        if (step == 1) return true;
        else return false;
    }
};