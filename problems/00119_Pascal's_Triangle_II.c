

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {

	int numRows = rowIndex + 1;
	int counts = numRows;
	if (counts == 0) counts = 1;
	int *row = (int *)malloc(sizeof(int) * counts);
	int i, j;
	int pos;
	int *row_ptr;

	*returnSize = counts;

	for (i = 0; i < numRows; i++) {
		pos = 0;
		row_ptr = &row[pos];
		int pre_j;

		for (j = 0; j < (i + 1); j++) {
			if ((j == 0) || (j == i)) {
				row_ptr[j] = 1;
				pre_j = 1;
			} else {
				int tmp = row_ptr[j];
				row_ptr[j] = row_ptr[j] + pre_j;
				pre_j = tmp;
			}
		}
	}

	return row;
}