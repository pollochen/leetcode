// index version
// Runtime: 81 ms, faster than 32.64% of C online submissions for Reverse String.
// Memory Usage: 12.3 MB, less than 91.78% of C online submissions for Reverse String.
void reverseString(char* s, int sSize){
    int l = 0;
    int r = sSize - 1;
    char tmp;
    while (l < r) {
        tmp = s[l];
        s[l++] = s[r];
        s[r--] = tmp;
    }
}

// pointer version
// Runtime: 67 ms, faster than 54.77% of C online submissions for Reverse String.
// Memory Usage: 12.6 MB, less than 19.71% of C online submissions for Reverse String.
void reverseString(char* s, int sSize){
    char *end = s + sSize - 1;
    char tmp;
    while (s < end) {
        tmp = *s;
        *s++ = *end;
        *end-- = tmp;
    }
}