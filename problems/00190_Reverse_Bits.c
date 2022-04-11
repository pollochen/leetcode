// Runtime: 3 ms, faster than 48.83% of C online submissions for Reverse Bits.
// Memory Usage: 5.3 MB, less than 98.54% of C online submissions for Reverse Bits.
uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (uint32_t i = 0; i < 32; i++) {
        result |= (n & 0x1) << (31-i);
        n = n >> 1;
    }
    return result;
}