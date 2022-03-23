// slow version (strlen() called twice)
// Runtime: 383 ms, faster than 5.02% of C online submissions for First Unique Character in a String.
// Memory Usage: 7.2 MB, less than 19.73% of C online submissions for First Unique Character in a String.
int firstUniqChar(char * s){
    int freqs[26];
    memset(freqs, 0, sizeof(freqs));
    for (int i = 0; i < strlen(s); i++) {
        freqs[s[i] - 'a']++;
    }
    for (int i = 0; i < strlen(s); i++) {
        if (freqs[s[i] - 'a'] == 1) return i;
    }
    return -1;
}

// faster version (strlen() called once)
// Runtime: 20 ms, faster than 44.31% of C online submissions for First Unique Character in a String.
// Memory Usage: 7.2 MB, less than 19.73% of C online submissions for First Unique Character in a String.
int firstUniqChar(char * s){
    int freqs[26];
    int len = strlen(s);
    memset(freqs, 0, sizeof(freqs));
    for (int i = 0; i < len; i++) {
        freqs[s[i] - 'a']++;
    }
    for (int i = 0; i < len; i++) {
        if (freqs[s[i] - 'a'] == 1) return i;
    }
    return -1;
}

// no strlen() version
// Runtime: 10 ms, faster than 79.77% of C online submissions for First Unique Character in a String.
// Memory Usage: 7.2 MB, less than 19.73% of C online submissions for First Unique Character in a String.
int firstUniqChar(char * s){
    int freqs[26];
    memset(freqs, 0, sizeof(freqs));
    char *tmp = s;
    int result = 0;
    while (*tmp != '\0') {
        freqs[*tmp - 'a']++;
        tmp++;
    }

    tmp = s;
    while (*tmp != '\0') {
        if (freqs[*tmp - 'a'] == 1) return result;
        tmp++;
        result++;
    }
    return -1;
}

void test_00387_First_Unique_Character_in_a_String(void)
{
    printf("%d\n", firstUniqChar("leetcode"));
    printf("%d\n", firstUniqChar("loveleetcode"));
    printf("%d\n", firstUniqChar("aabb"));
}