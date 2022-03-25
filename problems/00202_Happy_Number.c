// Runtime: 6 ms, faster than 18.46% of C online submissions for Happy Number.
// Memory Usage: 5.6 MB, less than 26.62% of C online submissions for Happy Number.
int iteration_next(int n)
{
    int x = 0;
    int y;
    while (n > 0) {
        y = n % 10;
        x += y * y;
        n = n / 10;
    }
    return x;
}

bool isHappy(int n){
    while (n != 1) {
        n = iteration_next(n);
        if (n == 4) return false;
    }
    return true;
}


void test_00202_Happy_Number(void)
{
    printf("\n");
    printf("%d\n", isHappy(19));
    printf("%d\n", isHappy(2));
}
