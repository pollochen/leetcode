// brute force
// Runtime: 6 ms, faster than 66.20% of C online submissions for Richest Customer Wealth.
// Memory Usage: 6 MB, less than 78.62% of C online submissions for Richest Customer Wealth.
int  max_int(int x, int y)
{
	if (x > y) return x;
	return y;
}

int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
    int result = 0;
    for (int row = 0; row < accountsSize; row++) {
        int sum = 0;
        for (int col = 0; col < accountsColSize[row]; col++) {
            sum += accounts[row][col];
        }
        result = max_int(result, sum);
    }
    return result;
}