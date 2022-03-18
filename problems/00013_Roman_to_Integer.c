int to_int(char ch)
{
	switch (ch) {
	case 'M': return 1000;
	case 'D': return 500;
	case 'C': return 100;
	case 'L': return 50;
	case 'X': return 10;
	case 'V': return 5;
	case 'I': return 1;
	default: return 0;
	}
}

int romanToInt(char * s) {
	int length = strlen(s);
	int i = 0;
	int result = 0;
	int val;
	char ch, ch_next;
	while (i < length) {
		ch = s[i];
		val = to_int(ch);
		if ((i + 1) < length) {
			int temp;
			ch_next = s[i + 1];
			temp = to_int(ch_next) - to_int(ch);
			if (temp > 0) {
				// 'CM', 'CD', 'XL', 'XC', 'IV', 'IX' cases
				result += temp;
				i++;
			}
			else {
				result += val;
			}
		}
		else {
			result += val;
		}
		i++;
	}

	return result;
}