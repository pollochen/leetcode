

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {

	int **rows = (int **)malloc(sizeof(int *) * numRows);
	int *column_sizes = (int *)malloc(sizeof(int) * numRows);
	int counts = ((1 + numRows) * numRows) / 2;
	int *elements = (int *)malloc(sizeof(int) * counts);
	int i, j;
	int pos, pos_pre;
	int *row_ptr;
	int *row_ptr_pre;

	*returnColumnSizes = column_sizes;
	*returnSize = numRows;

	for (i = 0; i < numRows; i++) {
		pos = ((i+1) * i) / 2;
		pos_pre = ((i) * (i - 1)) / 2;
		row_ptr = &elements[pos];
		row_ptr_pre = &elements[pos_pre];

		// assign row pointer
		rows[i] = row_ptr;

		// assign column size
		column_sizes[i] = i+1;

		for (j = 0; j < (i+1); j++) {
			if ((j == 0) || (j == i)) {
				row_ptr[j] = 1;
			} else {
				row_ptr[j] = row_ptr_pre[j-1] + row_ptr_pre[j];
			}
		}
	}

	return rows;
}