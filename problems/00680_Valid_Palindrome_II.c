bool validPalindromeX(char * s, int left, int right, int count){
    if (left > right) return false;
    while (left < right) {
        if (s[left] != s[right]) {
            count++;
            if (count > 1) return false;
            else {
                return validPalindromeX(s, left+1, right, count) | validPalindromeX(s, left, right-1, count);
            }
        }

        left++;
        right--;
    }
    return true;
}

bool validPalindrome(char * s){
    int len = strlen(s);
    return validPalindromeX(s, 0, len-1, 0);

}
