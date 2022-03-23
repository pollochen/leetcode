// Runtime: 7 ms, faster than 65.66% of C online submissions for Ransom Note.
// Memory Usage: 6.7 MB, less than 15.15% of C online submissions for Ransom Note.
bool canConstruct(char * ransomNote, char * magazine){
    int freqs[26];
    memset(freqs, 0, sizeof(freqs));
    char *tmp = magazine;
    int result = 0;

    // build frequency of letters in magazine
    while (*tmp != '\0') {
        freqs[*tmp - 'a']++;
        tmp++;
    }

    // check frequency of each letter in ransonNote
    tmp = ransomNote;
    while (*tmp != '\0') {
        if (freqs[*tmp - 'a'] == 0) return false;
        freqs[*tmp - 'a']--;
        tmp++;
    }
    return true;
}

void test_00383_Ransom_Note(void)
{
    printf("%d\n", canConstruct("a", "b"));
    printf("%d\n", canConstruct("aa", "ab"));
    printf("%d\n", canConstruct("aa", "aab"));
}