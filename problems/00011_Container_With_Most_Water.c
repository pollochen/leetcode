int min_int(int x, int y)
{
    if (x < y) return x;
    else return y;
}

int  max_int(int x, int y)
{
    if (x > y) return x;
    return y;
}

// greedy method
// Runtime: 144 ms, faster than 30.90 % of C online submissions for Container With Most Water.
// Memory Usage : 11.7 MB, less than 55.85 % of C online submissions for Container With Most Water.
int maxArea(int* height, int heightSize) {
    int area;
    int result = 0;
    int l = 0;
    int r = heightSize - 1;
    while (l < r) {
        area = (r - l) * min_int(height[l], height[r]);
        result = max_int(result, area);
        if (height[l] < height[r]) l++; // move left if it is smaller
        else r--; // move right if it is smaller
    }
    return result;
}