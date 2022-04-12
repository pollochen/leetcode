// https://www.cnblogs.com/grandyang/p/4371526.html
// DP
// Runtime: 117 ms, faster than 31.19% of C online submissions for Jump Game.
// Memory Usage: 10.5 MB, less than 5.29% of C online submissions for Jump Game.
int  max_int(int x, int y)
{
	if (x > y) return x;
	return y;
}

bool canJump(int* nums, int numsSize){
    int *dp = (int *)malloc(numsSize * sizeof(int));
    bool result = true;
    
    dp[0] = 0;
    for (int i = 1; i < numsSize; i++) {
        dp[i] = max_int(dp[i-1], nums[i-1]) - 1;
        if (dp[i] < 0) {
            result = false;  
            break;
        }
    }
    
    free(dp);
    return result;
}