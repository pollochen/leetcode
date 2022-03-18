// https://www.cnblogs.com/grandyang/p/4219878.html
class Solution {
public:
    int trailingZeroes(int n) {
        int result = 0;
        while (n > 0) {
            result += n/5;
            n = n/5;
        }
        return result;
    }
};

void test_172_Factorial_Trailing_Zeroes(void)
{
    Solution s;
    printf("%d\n", s.trailingZeroes(3));
    printf("%d\n", s.trailingZeroes(5));
    printf("%d\n", s.trailingZeroes(1));
    printf("%d\n", s.trailingZeroes(0));
    printf("%d\n", s.trailingZeroes(10));
    printf("%d\n", s.trailingZeroes(15));
    printf("%d\n", s.trailingZeroes(100));
}
