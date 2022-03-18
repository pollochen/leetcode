

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* reverse_int_array(int *num, int len)
{
	int head = 0, tail = len - 1;
	while (head < tail) {
		int tmp = num[head];
		num[head] = num[tail];
		num[tail] = tmp;

		head++;
		tail--;
	}

	return num;
}

int* addToArrayForm(int* num, int numSize, int k, int* returnSize) {
	
	int *result = (int *)malloc(sizeof(int) * 200000);
	int idx_result = 0;
	int idx_num = numSize - 1;
	int flag_carry = 0;

	while ((idx_num >= 0) || (k > 0)) {
		int val_a = 0;

		if (idx_num >= 0) val_a = num[idx_num];

		int val_b = k % 10;
		int val = val_a + val_b + flag_carry;

		flag_carry = 0;

		if (val >= 10) {
			flag_carry = 1;
			val -= 10;
		}

		result[idx_result++] = val;

		k = k / 10;
		idx_num--;
	}

	if (flag_carry == 1) {
		result[idx_result++] = 1;
	}

	reverse_int_array(result, idx_result);
	*returnSize = idx_result;

	return result;
}