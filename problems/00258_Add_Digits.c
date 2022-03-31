// brute force
// Runtime: 10 ms, faster than 7.28% of C online submissions for Add Digits.
// Memory Usage: 5.6 MB, less than 19.38% of C online submissions for Add Digits.
int addDigits(int num){
    int x;
    while (num >= 10) {
        x = num;
        num = 0;
        while (x > 0) {
            num += x % 10;
            x = x / 10;
        }
    }
    return num;
}
// it has patterns
// Runtime: 12 ms, faster than 7.28% of C online submissions for Add Digits.
// Memory Usage: 5.5 MB, less than 47.59% of C online submissions for Add Digits.
int addDigits(int num){
    if (num >= 10) {
        num = num % 9;
        if (num == 0) num = 9;
        return num;
    } else {
        return num;    
    }
}