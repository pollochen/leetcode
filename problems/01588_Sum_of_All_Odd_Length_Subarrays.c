// brute force
// Runtime: 8 ms, faster than 34.26% of C online submissions for Sum of All Odd Length Subarrays.
// Memory Usage: 5.8 MB, less than 99.07% of C online submissions for Sum of All Odd Length Subarrays.
int sumOddLengthSubarrays(int* arr, int arrSize) {
    int result = 0;
    for (int len = 1; len <= arrSize; len += 2) {
        for (int i = 0; i <= arrSize - len; i++) {
            for (int k = i; k < i + len; k++) {
                result += arr[k];
            }
        }
    }
    return result;
}

// https://www.geeksforgeeks.org/sum-of-all-odd-length-subarrays/
// Runtime: 0 ms, faster than 100.00 % of C online submissions for Sum of All Odd Length Subarrays.
// Memory Usage : 5.9 MB, less than 77.45 % of C online submissions for Sum of All Odd Length Subarrays.
int sumOddLengthSubarrays(int* arr, int arrSize) {
    int result = 0;
    int freq;
    for (int i = 0; i < arrSize; i++) {
        freq = ((i + 1) * (arrSize - i) + 1) / 2;
        result += freq * arr[i];
    }
    return result;
}

void test_01588_Sum_of_All_Odd_Length_Subarrays(void)
{
    int nums1[] = { 1, 4 , 2, 5, 3 };
    printf("%d\n", sumOddLengthSubarrays(nums1, 5));
}