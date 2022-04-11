// frequency map
// Runtime: 0 ms, faster than 100.00% of C online submissions for Longest Palindrome.
// Memory Usage: 6 MB, less than 12.37% of C online submissions for Longest Palindrome.
int longestPalindrome(char * s){
    int map[128];
    memset(map, 0, sizeof(map));
    while (*s != '\0') {
        map[*s++]++;
    }

    int result = 0;
    bool flag_x = false;
    for (int i = 0; i < 128; i++) {
        result += (map[i] / 2) * 2;
        if ((map[i] & 1) && (flag_x == false)) {
            flag_x = true;
            result++;
        }
    }
    return result;
}