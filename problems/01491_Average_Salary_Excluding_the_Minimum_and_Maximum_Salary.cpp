// Runtime: 3 ms, faster than 44.28% of C++ online submissions for Average Salary Excluding the Minimum and Maximum Salary.
// Memory Usage: 7.2 MB, less than 42.94% of C++ online submissions for Average Salary Excluding the Minimum and Maximum Salary.
class Solution {
public:
    double average(vector<int>& salary) {
        int val_min = INT_MAX;
        int val_max = INT_MIN;
        double sum = 0;
        int sl;
        for (int i = 0; i < salary.size(); i++) {
            sl = salary[i];
            sum += sl;
            if (sl < val_min) val_min = sl;
            if (sl > val_max) val_max = sl;
        }
        return (sum - val_min - val_max) / (salary.size() - 2);
    }
};