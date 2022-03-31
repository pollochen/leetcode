// map and check one by one
// Runtime: 3 ms, faster than 61.04% of C online submissions for Verifying an Alien Dictionary.
// Memory Usage: 5.9 MB, less than 64.94% of C online submissions for Verifying an Alien Dictionary.
bool comapre(char *w1, char *w2, int *map)
{
    while (*w1 != '\0' && *w2 != '\0') {
        if (map[*w1 - 'a'] < map[*w2 - 'a']) return true; // w1 is smaller
        if (map[*w1 - 'a'] > map[*w2 - 'a']) return false; // wl is larger
        w1++;
        w2++;
    }

    // w1 and w2 is the same, check length
    if (*w1 == '\0') return true; // if w1 is shorter, it has smaller value
    else return false;
}

bool isAlienSorted(char ** words, int wordsSize, char * order){
    int map[26];
    // create map for a, b, c, ... -> [i]
    for (int i = 0; i < 26; i++) {
        map[order[i] - 'a'] = i;
    }
    for (int i = 1; i < wordsSize; i++) {
        if (comapre(words[i-1], words[i], map) == false) return false;
    }
    return true;
}

void test_00953_Verifying_an_Alien_Dictionary(void)
{
    char *words1[] = {"hello","leetcode"};
    char order1[] = "hlabcdefgijkmnopqrstuvwxyz";
    printf("%d\n", isAlienSorted(words1, 2, order1));

    char *words2[] = {"word","world","row"};
    char order2[] = "worldabcefghijkmnpqstuvxyz";
    printf("%d\n", isAlienSorted(words2, 3, order2));

    char *words3[] = {"apple","app"};
    char order3[] = "abcdefghijklmnopqrstuvwxyz";
    printf("%d\n", isAlienSorted(words3, 2, order3));

}