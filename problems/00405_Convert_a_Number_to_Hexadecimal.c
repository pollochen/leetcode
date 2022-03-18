
char * toHex(int num) {
	char *result = (char *)malloc(sizeof(char) * 9);
	char hex_num[] = {"0123456789abcdef"};
	int idx = 0;
	int flag_start = 0;
	if (num == 0) {
		result[0] = '0';
		result[1] = 0;
	} else {
		for (int i = 7; i >= 0; i--) {
			int x = num >> (4 * i) & 0x0F;
			if (flag_start == 0) {
				if (x != 0) {
					flag_start = 1;
					result[idx++] = hex_num[x];
				}
			} else {
				result[idx++] = hex_num[x];
			}
		}
		result[idx] = 0;
	}
	return result;
}