// brute force
// Runtime: 205 ms, faster than 66.16% of C++ online submissions for Find the Town Judge.
// Memory Usage: 60.6 MB, less than 93.79% of C++ online submissions for Find the Town Judge.
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int freqs[1002];
        int count = 0;
        int result = -1;
        if (n == 1) return 1;
        memset(freqs, 0, sizeof(freqs));
        for (int i = 0; i < trust.size(); i++) {
            int trusted = trust[i][1];
            freqs[trusted]++;
            if (freqs[trusted] == (n - 1)) {
                count++;
                if (count >= 2) {
                    return -1;
                }
                result = trusted;
            }
        }
        // check the town judge trusts nobody.
        for (int i = 0; i < trust.size(); i++) {
            int who = trust[i][0];
            if (who == result) return -1;
        }
        return result;
    }
};