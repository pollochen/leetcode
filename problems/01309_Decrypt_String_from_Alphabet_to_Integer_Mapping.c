// brute force
// Runtime: 3 ms, faster than 40.26% of C online submissions for Decrypt String from Alphabet to Integer Mapping.
// Memory Usage: 5.5 MB, less than 87.01% of C online submissions for Decrypt String from Alphabet to Integer Mapping.
char * freqAlphabets(char * s){
    int num;
    char ch;
    char *result = s;
    int  left = 0;
    int  pos = 0;
    int  cur = 0;
    while (s[cur] != '\0') {
        ch = s[cur];
        if (s[cur] == '#') {
            // output [left, cur - 3]
            for (int i = left; i < cur - 2; i++) {
                s[pos++] = 'a' + s[i] - '1';
            }
            // output [cur-2, cur - 1]
            num = (s[cur -2] - '0') * 10 + (s[cur - 1] - '0') - 10;
            s[pos++] = 'j' + num;
            cur++;
            left = cur;
        } else {
            cur++;
        }
    }
    // output [left, cur-1]
    for (int i = left; i < cur; i++) {
        s[pos++] = 'a' + s[i] - '1';
    }
    s[pos] = '\0';
    return result;
}

void test_01309_Decrypt_String_from_Alphabet_to_Integer_Mapping(void)
{
    char *result;
    char s1[] = "10#11#12";
    char s2[] = "1326#";
    printf("%s\n", freqAlphabets(s1));
    printf("%s\n", freqAlphabets(s2));
}