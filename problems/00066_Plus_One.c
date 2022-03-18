

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
	if ((digits == NULL) || (digitsSize == 0)) {
		*returnSize = 0;
		return NULL;
	}

	// check if overflow
	int i;
	int *result;
	int flag_carry = 1;
	for (i = 0; i < digitsSize; i++) {
		if (digits[i] != 9) {
			break;
		}
	}

	if (i == digitsSize) {
		*returnSize = digitsSize + 1;
	} else {
		*returnSize = digitsSize;
	}

	result = (int *)malloc(sizeof(int) * *returnSize);
	
	for (i = digitsSize - 1; i >= 0; i--) {
		digits[i] = digits[i] + flag_carry;
		if (digits[i] >= 10) {
			digits[i] -= 10;
			flag_carry = 1;
		} else {
			flag_carry = 0;
		}
	}
	if (flag_carry == 1) {
		memcpy(result + 1, digits, sizeof(int) * digitsSize);
		result[0] = 1;
	} else {
		memcpy(result, digits, sizeof(int) * digitsSize);
	}

	return result;
}
