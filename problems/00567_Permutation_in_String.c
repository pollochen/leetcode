// sliding window
// Runtime: 9 ms, faster than 42.80% of C online submissions for Permutation in String.
// Memory Usage: 6 MB, less than 76.20% of C online submissions for Permutation in String.
bool checkInclusion(char * s1, char * s2){
    int freqs_1[26];
    int freqs_2[26];
    memset(freqs_1, 0, sizeof(freqs_1));
    memset(freqs_2, 0, sizeof(freqs_2));

    // s1 > s2, always false
    if (strlen(s1) > strlen(s2)) {
        return false;
    }

    char *tmp = s2;

    // build frequency map for s1 and s2
    while (*s1 != '\0') {
        freqs_1[*s1++ - 'a']++;
        freqs_2[*s2++ - 'a']++;
    }

    while (*s2 != '\0') {
        if (memcmp(freqs_1, freqs_2, sizeof(freqs_1)) == 0) {
            // match found
            return true;
        }
        // no match, slide window to right by 1
        freqs_2[*tmp++ - 'a']--;
        freqs_2[*s2++ - 'a']++;
    }
    if (memcmp(freqs_1, freqs_2, sizeof(freqs_1)) == 0) return true;
    return false;
}

// sliding window (no strlen() calls)
// Runtime: 0 ms, faster than 100.00% of C online submissions for Permutation in String.
// Memory Usage: 6 MB, less than 76.20% of C online submissions for Permutation in String.
bool checkInclusion(char * s1, char * s2){
    int freqs_1[26];
    int freqs_2[26];
    memset(freqs_1, 0, sizeof(freqs_1));
    memset(freqs_2, 0, sizeof(freqs_2));

    char *tmp = s2;

    // build frequency map for s1 and s2
    while (*s1 != '\0' && *s2 != '\0') {
        freqs_1[*s1++ - 'a']++;
        freqs_2[*s2++ - 'a']++;
    }

    // if s1 > s2, *s1 will not be '\0'
    if (*s1 != '\0') return false;

    while (*s2 != '\0') {
        if (memcmp(freqs_1, freqs_2, sizeof(freqs_1)) == 0) {
            // match found
            return true;
        }
        // no match, slide window to right by 1
        freqs_2[*tmp++ - 'a']--;
        freqs_2[*s2++ - 'a']++;
    }
    if (memcmp(freqs_1, freqs_2, sizeof(freqs_1)) == 0) return true;
    return false;
}

void test_00567_Permutation_in_String(void)
{
    printf("%d\n", checkInclusion("ab", "a"));
    printf("%d\n", checkInclusion("adc", "dcda"));
    printf("%d\n", checkInclusion("ab", "eidbaooo"));
    printf("%d\n", checkInclusion("ab", "eidboaoo"));
}