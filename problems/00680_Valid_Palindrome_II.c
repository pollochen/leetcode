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

bool is_palindrome(char* s, int left, int right)
{
    while (left < right) {
        if (s[left] == s[right]) {
            left++;
            right--;
        } else {
            return false;
        }
    }
    return true;
}
// https://leetcode.com/problems/valid-palindrome-ii/solution/
// Runtime: 16 ms, faster than 80.36% of C online submissions for Valid Palindrome II.
// Memory Usage : 9.1 MB, less than 66.67 % of C online submissions for Valid Palindrome II.
bool validPalindrome(char* s) {
    int len = strlen(s);
    int l = 0;
    int r = len - 1;
    while (l < r) {
        // find a mismatch
        if (s[l] == s[r]) {
            l++;
            r--;
        } else {
            // mismatch found
            // the true condition is either left or right is palindrome
            return is_palindrome(s, l, r - 1) || is_palindrome(s, l + 1, r);
        }
    }
    return true;
}