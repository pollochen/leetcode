static char roman_table[] = {
    'I', // 1
    'V', // 5
    'X', // 10
    'L', // 50
    'C', // 100
    'D', // 500
    'M', // 1000
    '~', // 5000, not used
    '!', // 10000, not used
};

class Solution {
public:
    string int_to_roman(int num, int digit)
    {
        string one  = string(1, roman_table[digit * 2]);
        string five = string(1, roman_table[digit * 2 + 1]);
        string ten =  string(1, roman_table[digit * 2 + 2]);
        switch (num) {
            case 0: return ten;
            case 1: return one;
            case 2: return one + one;
            case 3: return one + one + one;
            case 4: return five + one; // in reverse order
            case 5: return five;
            case 6: return one + five; // in reverse order
            case 7: return one + one + five; // in reverse order
            case 8: return one + one + one + five; // in reverse order
            case 9: return ten + one; // in reverse order
        }
        return "#";
    }
    void string_reverse(string &s)
    {
        int l = 0;
        int r = s.length() - 1;
        while (l < r) {
            char tmp = s[l];
            s[l++] = s[r];
            s[r--] = tmp;
        }
    }
    string intToRoman(int num) {
        string result;
        int digit = 0;
        while (num > 0) {
            int x = num % 10;
            if (x != 0) {
                result += int_to_roman(x, digit);
            }
            digit++;
            num = num / 10;
        }
        string_reverse(result);
        return result;
    }
};