int lengthOfLongestSubstring(char * s){
	if (s == NULL) return 0;    
    if (*s == '\0') return 0;
	int map[128];
	memset(map, 0, sizeof(map));
	int l = 0;
	int r = 0;
	int result = 1;
	while (s[r] != '\0') {
		char ch = s[r];
		if (map[ch] == 1) {
			// slide l to first position of ch
			while (s[l] != ch) {
				map[s[l]]--;
				l++;
			}
			l++;
		} else {
			map[ch]++;
			// calculate length
			int x = r - l + 1;
			if (x > result) result = x;
		}
		r++;
	}
	return result;
}

// sliding window
// Runtime: 4 ms, faster than 82.54% of C online submissions for Longest Substring Without Repeating Characters.
// Memory Usage: 5.9 MB, less than 64.06% of C online submissions for Longest Substring Without Repeating Characters.
int max_int(int x, int y)
{
    if (x > y) return x;
    else return y;
}

int lengthOfLongestSubstring(char* s) {
    int freqs[128];
    memset(freqs, 0, sizeof(freqs));
    int idx = 0;
    int result = 0;
    int start = 0;
    char ch;
    while (s[idx] != '\0') {
        ch = s[idx];
        if (freqs[ch] == 1) {
            // repeat char
            // check length
            result = max_int(result, idx - start);

            // update start pos until it has same char  (left = right)
            while (s[start] != ch) {
                freqs[s[start]]--;
                start++;
            }
            // step start pos
            start++;
        }
        // update frequency
        freqs[ch] = 1;
        idx++;
    }
    // corner case if last is not calculated
    result = max_int(result, idx - start);
    return result;
}

void test_00003_Longest_Substring_Without_Repeating_Characters(void)
{
    printf("%d\n", lengthOfLongestSubstring("dvdf"));
    printf("%d\n", lengthOfLongestSubstring("abcabcbb"));
    printf("%d\n", lengthOfLongestSubstring("bbbbb"));
    printf("%d\n", lengthOfLongestSubstring("pwwkew"));
    printf("%d\n", lengthOfLongestSubstring(""));
    printf("%d\n", lengthOfLongestSubstring(" "));

}