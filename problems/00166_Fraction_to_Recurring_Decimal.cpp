class Solution {
public:
    int find_idx(vector<long> &set, long value)
    {
        for (int i = 0; i < set.size(); i++) {
            if (set[i] == value) {
                return i;
            }
        }
        return -1;
    }
    string fractionToDecimal(int numerator, int denominator) {
        string result = "";
        vector<long> set;
        // int part
        long n = numerator;
        long d = denominator;

        if (n == 0) { return "0";}
        if (d == -1) {
            n = -n;
            result += to_string(static_cast<long long>(n));
            return result;
        }

        long val = n / d;
        long remainder = n % d;

        if (val == 0 && remainder != 0) {
            if (((n > 0) && (d < 0)) || ((n < 0) && (d > 0))) {
                result += "-";
            }
        }
        result += to_string(static_cast<long long>(val));
        if (remainder == 0) {
            return result;
        } else {

            result += ".";
            string sub_str = "";
            remainder = labs(remainder);
            d = labs(d);

            set.push_back(remainder);

            int repeat_idx = -1;

            while (remainder != 0) {

                remainder = remainder * 10;
                val = remainder / d;
                remainder = remainder % d;

                sub_str += to_string(static_cast<long long>(labs(val)));

                repeat_idx = find_idx(set, remainder);
                if (repeat_idx != -1) {
                    // repeat
                    break;
                } else {
                    set.push_back(remainder);
                }
            };

            if (repeat_idx != -1) {
                sub_str = sub_str.insert(repeat_idx, "(") + ")";
                result += sub_str;
            } else {
                result += sub_str;
            }
        }
        return result;
    }
};

void test_166_Fraction_to_Recurring_Decimal(void)
{
    Solution s;
    printf("-2147483648/-1 = %s\n", s.fractionToDecimal(-2147483648, -1).c_str());
    printf("-1/-2147483648 = %s\n", s.fractionToDecimal(-1, -2147483648).c_str());
    printf("7/-12 = %s\n", s.fractionToDecimal(7, -12).c_str());
    printf("1/6 = %s\n", s.fractionToDecimal(1, 6).c_str());
    printf("4/333 = %s\n", s.fractionToDecimal(4, 333).c_str());
    printf("-4/333 = %s\n", s.fractionToDecimal(-4, 333).c_str());
    printf("1/2 = %s\n", s.fractionToDecimal(1, 2).c_str());
    printf("2/1 = %s\n", s.fractionToDecimal(2, 1).c_str());
    printf("-2/1 = %s\n", s.fractionToDecimal(-2, 1).c_str());
    printf("-2/-1 = %s\n", s.fractionToDecimal(-2, -1).c_str());
    printf("2/-1 = %s\n", s.fractionToDecimal(2, -1).c_str());
    printf("0/-1 = %s\n", s.fractionToDecimal(0, -1).c_str());
    printf("1/3 = %s\n", s.fractionToDecimal(1, 3).c_str());
}