// Runtime: 4 ms, faster than 23.18% of C++ online submissions for Next Greater Element III.
// Memory Usage: 6.2 MB, less than 7.45% of C++ online submissions for Next Greater Element III.
class Solution {
public:
    void swap_int(int *x, int *y)
    {
        int tmp = *x;
        *x = *y;
        *y = tmp;
    }
    int nextGreaterElement(int n) {
        vector<int> nums;
        // create int array for the n
        while (n > 0) {
            nums.push_back(n % 10);
            n = n / 10;
        }

        int idx = 0;
        int last_idx = -1;
        bool flag_found = false;
        // find a farest idx which has greater value than [dix] in [0, idx-1]
        // monotonic stack is used
        stack<int> stk;
        for (int idx = 0; idx < nums.size(); idx++) {
            if (stk.empty() == true) {
                stk.push(idx);
            } else {
                if (nums[stk.top()] > nums[idx]) {
                    while (stk.empty() == false && nums[stk.top()] > nums[idx]) {
                        last_idx = stk.top();
                        stk.pop();
                    }
                    // found, swap them
                    swap_int(&nums[idx], &nums[last_idx]);
                    // need to sort [0, idx] by decending order, because we want to have smallest value for n
                    sort(nums.begin(), nums.begin() + idx, greater<int>());
                    flag_found = true;
                    break;
                }
                stk.push(idx);
            }
        }
        if (flag_found == false) return -1;

        // convert nums array back to int
        long long result = 0;
        long long x = 1;
        for (int i = 0; i < nums.size(); i++) {
            result += nums[i] * x;
            x *= 10;
        }
        if (result > 0x7FFFFFFF) return -1;
        return result;
    }
};

void test_00556_Next_Greater_Element_III()
{
    Solution s;
    printf("%d\n", s.nextGreaterElement(12));
    printf("%d\n", s.nextGreaterElement(21));
    printf("%d\n", s.nextGreaterElement(123456));
    printf("%d\n", s.nextGreaterElement(230241)); // 230412

}