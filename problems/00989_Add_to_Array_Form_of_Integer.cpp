// brute force
// Runtime: 51 ms, faster than 26.03% of C++ online submissions for Add to Array-Form of Integer.
// Memory Usage: 28.7 MB, less than 30.16% of C++ online submissions for Add to Array-Form of Integer.
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> result;
        int idx = num.size() - 1;
        int carry = 0;
        int x;
        while (idx >= 0 || k > 0) {
            if (idx >= 0) x = num[idx] + k % 10 + carry;
            else x = k % 10 + carry;
            if (x >= 10) {
                carry = x / 10;
                x = x % 10;
            } else {
                carry = 0;
            }
            result.push_back(x);
            idx--;
            k /= 10;
        }
        if (carry) result.push_back(carry);
        reverse(result.begin(), result.end());
        return result;
    }
};
// no carry flag version
// Runtime: 49 ms, faster than 29.43% of C++ online submissions for Add to Array-Form of Integer.
// Memory Usage: 28.6 MB, less than 30.16% of C++ online submissions for Add to Array-Form of Integer.
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> result;
        int idx = num.size() - 1;
        while (idx >= 0 || k > 0) {
            if (idx >= 0) {
                k += num[idx];
            }
            result.push_back(k%10);
            idx--;
            k /= 10;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};