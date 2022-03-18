class Solution {
public:
    string breakPalindrome(string palindrome) {
        int len = palindrome.length();
        if (len == 1) {return "";}
        int left = 0, right = len-1;

        while (left < right) {
            if (palindrome[left] != 'a') {
                break;
            }
            left++;
            right--;
        }

        // left == right
        if (palindrome[left] == 'a') {
            // 'aaaaa', set last char as 'b'
            palindrome[len-1] = 'b';
        } else {
            if (left != right) {
                // 'acbca'
                palindrome[left] = 'a';
            } else {
                // 'aabaa', set last char as 'b'
                palindrome[len-1] = 'b';
            }
        }
        return palindrome;

    }
};

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int len = palindrome.length();
        if (len == 1) {return "";}
        int i;
        for (i = 0; i < len/2; i++) {
            if (palindrome[i] != 'a') {
                // a'b'cba, set it as 'a'
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        // aaaa or aabaa, set last char as 'b'
        palindrome[len-1] = 'b';
        return palindrome;
    }
};