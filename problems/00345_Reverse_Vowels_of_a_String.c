bool is_vowels(char ch)
{
	return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
}


char * reverseVowels(char * s){
	int len = strlen(s);
	char *result = (char *)malloc(len + 1);
	strcpy(result, s);
	char *l = result;
	char *r = result + len - 1;
	bool flag_l = is_vowels(*l);
	bool flag_r = is_vowels(*r);
	while (l < r) {
		if ((flag_l == true) && (flag_r == true)) {
			// swap
			char tmp = *l;
			*l++ = *r;
			*r-- = tmp;
			flag_l = is_vowels(*l);
			flag_r = is_vowels(*r);
		} else if (flag_l == false) {
			// step l
			l++;
			flag_l = is_vowels(*l);
		} else {
			// step r
			r--;
			flag_r = is_vowels(*r);
		}
	}
	return result;
}