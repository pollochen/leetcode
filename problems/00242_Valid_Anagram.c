// 2 hash and memcmp version
// Runtime: 4 ms, faster than 66.19% of C online submissions for Valid Anagram.
// Memory Usage: 6.1 MB, less than 6.64% of C online submissions for Valid Anagram.
bool isAnagram(char * s, char * t){
    int freqs_s[26];
    int freqs_t[26];
    memset(freqs_s, 0, sizeof(freqs_s));
    memset(freqs_t, 0, sizeof(freqs_t));

    char *tmp = s;

    // build frequency of letters in s
    while (*tmp != '\0') {
        freqs_s[*tmp - 'a']++;
        tmp++;
    }

    tmp = t;
    // build frequency of letters in t
    while (*tmp != '\0') {
        freqs_t[*tmp - 'a']++;
        tmp++;
    }
    if (memcmp(freqs_s, freqs_t, sizeof(freqs_s)) == 0) return true;
    return false;
}

// one hash only
// Runtime: 6 ms, faster than 45.02% of C online submissions for Valid Anagram.
// Memory Usage: 5.8 MB, less than 95.89% of C online submissions for Valid Anagram.
bool isAnagram(char * s, char * t){
    int freqs[26];
    memset(freqs, 0, sizeof(freqs));

    // build frequency of letters in s and t
    while (*s != '\0' && *t != '\0') {
        freqs[*s++ - 'a']++;
        freqs[*t++ - 'a']--;
        //s++;
        //t++;
    }

    // check if s and t have the same length
    if (*s != '\0' || *t != '\0') return false;

    // if they are anagram, freqs should have all zeros.
    for (int i = 0; i < 26; i++) {
        if (freqs[i] != 0) return false;
    }
    return true;
}

void test_00242_Valid_Anagram(void)
{
    printf("%d\n", isAnagram("anagram", "nagaram"));
    printf("%d\n", isAnagram("rat", "car"));
}