class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        if (n < 0) return false;
        unsigned int x = n;
        return !(x & (x-1));
    }
};