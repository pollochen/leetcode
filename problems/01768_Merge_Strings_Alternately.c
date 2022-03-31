// Runtime: 0 ms, faster than 100.00% of C online submissions for Merge Strings Alternately.
// Memory Usage: 5.7 MB, less than 97.20% of C online submissions for Merge Strings Alternately.
char * mergeAlternately(char * word1, char * word2){
    char *result = (char *)malloc(sizeof(char) * (strlen(word1) + strlen(word2) + 1));
    int i = 0;
    char *s = result;
    while (*word1 != '\0' && *word2 != '\0') {
        if ((i & 0x01) == 0) {
            *s++ = *word1++;
        } else {
            *s++ = *word2++;
        }
        i++;
    }
    
    while (*word1 != '\0') *s++ = *word1++;
    while (*word2 != '\0') *s++ = *word2++;
    *s = '\0';
    return result;
}

void test_01768_Merge_Strings_Alternately(void)
{
    char w1[] = "abc";
    char w2[] = "pqr";
    char* result = mergeAlternately(w1, w2);
    printf("%s\n", result);

    char w3[] = "ab";
    char w4[] = "pqrs";
    result = mergeAlternately(w3, w4);
    printf("%s\n", result);
}
