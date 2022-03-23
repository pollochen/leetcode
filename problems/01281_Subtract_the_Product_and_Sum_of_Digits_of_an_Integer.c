// brute force
// Runtime: 4 ms, faster than 21.99% of C online submissions for Subtract the Product and Sum of Digits of an Integer.
// Memory Usage: 5.6 MB, less than 14.89% of C online submissions for Subtract the Product and Sum of Digits of an Integer.
int subtractProductAndSum(int n){
    int product = 1;
    int sum = 0;
    int x;
    while (n > 0) {
        int x = n % 10;
        product = product * x;
        sum = sum + x;
        n = n / 10;
    }
    return product - sum;
}

// sprintf() version
// Runtime: 0 ms, faster than 100.00% of C online submissions for Subtract the Product and Sum of Digits of an Integer.
// Memory Usage: 5.8 MB, less than 14.89% of C online submissions for Subtract the Product and Sum of Digits of an Integer.
int subtractProductAndSum(int n){
    char s[10];
    int product = 1;
    int sum = 0;

    sprintf(s,"%d",n);

    for (int i = 0; i < strlen(s); i++) {
        product = product * (s[i] - '0');
        sum     = sum + (s[i] - '0');
    }

    return product - sum;
}

void test_01281_Subtract_the_Product_and_Sum_of_Digits_of_an_Integer(void)
{
    printf("%d\n", subtractProductAndSum(234));
    printf("%d\n", subtractProductAndSum(4421));
    printf("%d\n", subtractProductAndSum(1));
}
