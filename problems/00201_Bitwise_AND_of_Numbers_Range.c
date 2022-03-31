// intuition
// Runtime: 8 ms, faster than 90.36% of C online submissions for Bitwise AND of Numbers Range.
// Memory Usage: 5.8 MB, less than 68.67% of C online submissions for Bitwise AND of Numbers Range.
int rangeBitwiseAnd(int left, int right){
    long steps = right - left; // steps from left to right
    long x = right & left;     // initial value would be l & r
    long bit = 1;              // the bit we want to mask out
    while (steps > 0) {
        x = x & (~bit);
        steps = steps >> 1;    // bit 0 would be 0 if steps >= 1, bit 1 would be 0 if steps >= 2, 
        bit = bit << 1;        // bit 2 would be 0 if steps >= 4, bit 3 would be 0 if steps >= 8....
    }
    return x;
}