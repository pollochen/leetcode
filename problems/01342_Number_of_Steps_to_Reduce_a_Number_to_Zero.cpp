class Solution {
public:
    int numberOfSteps(int num) {
        int cnt = 0;
        if (num == 0) return 0;
        while (num != 0) {
            if (num & 1) cnt +=2;
            else cnt++;
            num = num >> 1;
        }
        cnt--;
        return cnt;
    }
};