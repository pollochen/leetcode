class Solution {
public:
    uint32_t reverseBits(uint32_t b) {
       uint32_t mask = 0b11111111111111110000000000000000;
       b = (b & mask) >> 16 | (b & ~mask) << 16;
       mask = 0b11111111000000001111111100000000;
       b = (b & mask) >> 8 | (b & ~mask) << 8;
       mask = 0b11110000111100001111000011110000;
       b = (b & mask) >> 4 | (b & ~mask) << 4;
       mask = 0b11001100110011001100110011001100;
       b = (b & mask) >> 2 | (b & ~mask) << 2;
       mask = 0b10101010101010101010101010101010;
       b = (b & mask) >> 1 | (b & ~mask) << 1;
       return b;        
    }
};