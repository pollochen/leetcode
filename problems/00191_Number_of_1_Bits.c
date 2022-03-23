// brute force
// Runtime: 0 ms, faster than 100.00% of C online submissions for Number of 1 Bits.
// Memory Usage: 5.4 MB, less than 92.25% of C online submissions for Number of 1 Bits.
int hammingWeight(uint32_t n) {
    int result = 0;
    while (n > 0) {
        if (n & 0x1) result++;
        n = n >> 1;
    }
    return result;
}

void test_00191_Number_of_1_Bits(void)
{
    printf("%d\n", hammingWeight(11));
    printf("%d\n", hammingWeight(128));
    printf("%d\n", hammingWeight(0xFFFFFFFD));
}
