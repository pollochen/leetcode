class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n, true);
        if (n == 0 || n == 1) { return 0;}
        prime[0] = false;
        prime[1] = false;
        // check from [0 - sqrt(n)]
        for (int i = 2; i*i < n; i++) {
            // mark off i^2 + i, I^2 + i*2, I^2 + i*3, .... n
            for (int j = i * i; j < n; j += i) {
                prime[j] = false;
            }
        }
        int result = 0;
        for (int i = 2; i < n; i++) {
            if (prime[i] == true) result++;
        }
        return result;
    }
};

void test_204_Count_Primes(void)
{
    Solution s;
    printf("%d\n", s.countPrimes(10));
}