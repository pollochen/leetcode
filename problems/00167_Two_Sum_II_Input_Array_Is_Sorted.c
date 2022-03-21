/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// hash version
// Runtime: 16 ms, faster than 47.26% of C online submissions for Two Sum II - Input Array Is Sorted.
// Memory Usage: 7.2 MB, less than 47.26% of C online submissions for Two Sum II - Input Array Is Sorted.
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
	int* result = (int*)malloc(sizeof(int) * 2);
	*returnSize = 2;

	int base = 1000;
	int freqs[2000 + 2];
	int pos_array[2000 + 2];
	memset(freqs, 0, sizeof(freqs));
	memset(pos_array, 0, sizeof(freqs));

	if (numbersSize == 2) {
		result[0] = 1;
		result[1] = 2;
	} else {
		for (int i = 0; i < numbersSize; i++) {
			int num = numbers[i];
			freqs[num + base]++;
			pos_array[num + base] = i;
		}
		for (int i = 0; i < numbersSize; i++) {
			int x = target - numbers[i];
			int freq_x = freqs[x + base];
			if ((x == numbers[i]) && (freq_x == 1)) {
				// can't use same element
				continue;
			} else {
				// check frequency of x ([-1000 ~ 1000], need to add base)
				if (freq_x > 0) {
					result[0] = i + 1;
					result[1] = pos_array[x + base] + 1; // get position of x ([-1000 ~ 1000], need to add base)
					return result;
				}
			}
		}
	}
	return result;
}

// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/discuss/1861931/Easy-to-understand-C%2B%2B-solution.
// Runtime: 18 ms, faster than 38.31% of C online submissions for Two Sum II - Input Array Is Sorted.
// Memory Usage: 7.4 MB, less than 18.91% of C online submissions for Two Sum II - Input Array Is Sorted.
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
	int* result = (int*)malloc(sizeof(int) * 2);
	*returnSize = 2;

	int l = 0;
	int r = numbersSize - 1;
	while (l < r) {
		int val_l = numbers[l];
		int val_r = numbers[r];
		int x = val_l + val_r;
		if (x == target) {
			result[0] = l + 1;
			result[1] = r + 1;
			break;
		} else if (x > target) {
			r--;
		} else {
			l++;
		}
	}

	return result;
}

// TLE version
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
	int* result = (int*)malloc(sizeof(int) * 2);
	*returnSize = 2;

	if (numbersSize == 2) {
		result[0] = 1;
		result[1] = 2;
	} else {
		for (int i = 0; i < numbersSize; i++) {
			int x = target - numbers[i];
			for (int j = i + 1; j < numbersSize; j++) {
				if (x == numbers[j]) {
					result[0] = i+1;
					result[1] = j+1;
					return result;
				}
				if (x < numbers[j]) break; // number[j] is larger than x, end of this iteration
			}
		}
	}
	return result;
}