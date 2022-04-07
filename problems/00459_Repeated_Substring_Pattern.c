// brute force  O(N^3)
// Runtime: 16 ms, faster than 34.55% of C online submissions for Repeated Substring Pattern.
// Memory Usage: 6.4 MB, less than 65.45% of C online submissions for Repeated Substring Pattern.
bool repeatedSubstringPattern(char * s){
    int length = strlen(s);
    bool result;
    // check each length [1 ~ length /2]
    for (int len = 1; len <= length / 2; len++ ) {
        // check total length for this substring length
        if ((length % len) != 0) continue;
        result = true;
        for (int i = 1; i < length / len; i++) {
            // compare each char in substring
            for (int j = 0; j < len; j++) {
                if (s[j] != s[i * len + j]) {
                    result = false;
                    break;
                };
            }
        }
        if (result == true) return true;
    }
    return false;
}

// O(N^2)
// Runtime: 8 ms, faster than 87.27% of C online submissions for Repeated Substring Pattern.
// Memory Usage: 6.6 MB, less than 52.73% of C online submissions for Repeated Substring Pattern.
bool repeatedSubstringPattern(char * s){
    int length = strlen(s);
    int i;
    // check each length [length /2 ~ 1]
    for (int l = length / 2; l > 0; l--) {
        if ((length % l) != 0) continue;
        i = 0;
        while ((i + l < length) && (s[i] == s[i+l])) {
            i++;
        }
        if (i + l == length) return true;
    }
    return false;
}