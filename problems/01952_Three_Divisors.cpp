class Solution {
public:
    bool isThree(int n) {
        if (n == 1) return false;
        int cnt = 2;
        for (int i = 2; i < n-1; i++) {
            if ((n % i) == 0) cnt++;
            if (cnt > 3) break;
        }
        if (cnt == 3) return true;
        else return false;
    }
};