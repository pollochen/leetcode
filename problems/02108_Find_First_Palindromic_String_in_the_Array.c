
bool is_palindrome_nospace(char * s){
    int len = strlen(s);
    int steps = len / 2;
    char *tail = &s[len-1];
    char *head = s;
    int i = 0;
    while (i < steps) {
        if (*head != *tail) return false;
        head++;
        tail--;
        i++;
    }
    return true;
}

char * firstPalindrome(char ** words, int wordsSize){
    for (int i = 0; i < wordsSize; i++) {
        if (is_palindrome_nospace(words[i]) == true) {
            return words[i];
        }
    }
    return "";
}