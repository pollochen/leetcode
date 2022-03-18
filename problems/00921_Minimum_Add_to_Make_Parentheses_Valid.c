	int minAddToMakeValid(char * s) {
		int result = 0;
		int cnt = 0;
		while (*s != '\0') {
			if (*s == '(') {
				cnt++;
		    } else if (*s == ')') {
				if (cnt == 0) result++;
				else cnt--;
			}
			s++;
		}
		return result + cnt;
	}